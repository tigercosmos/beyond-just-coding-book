// shell.cpp
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <csignal>
#include <cstdio>
#include <sys/wait.h>
#include <unistd.h>

#define COMMAND_COUNT 9

int main(int argc, char **argv)
{
    /* 步驟一 */
    // 模擬剛開啟 shell 的顯示提示符號
    std::cout << "$" << std::endl;

    // 處理 SIGCHLD，可以避免 child 疆屍程序
    struct sigaction sigchld_action;
    sigchld_action.sa_handler = SIG_DFL,
    sigchld_action.sa_flags = SA_NOCLDWAIT;

    /* 步驟二 */
    // 模擬下達指令 ls | cat | cat | cat | cat | cat | cat | cat | cat
    std::cout << "$ ls | cat | cat | cat | cat | cat | cat | cat | cat" << std::endl;

    // shell 會需要 parse 指令，我們假設 shell 已經將指令 parse 好

    // 接下來 shell 的邏輯是，每一個指令都 fork 一個新的 process，然後將 pipe 的讀取端或寫入端取代成 stdin 或 stdout

    const char *ls_cmd = "ls";
    const char *cat_cmd = "cat";

    char **cmds[COMMAND_COUNT];

    const char *p1_args[] = {ls_cmd, NULL};
    cmds[0] = const_cast<char **>(p1_args);

    const char *p2_args[] = {cat_cmd, NULL};

    // 只是 DEMO，所以重複利用，真實世界 shell 會一個一個 parse
    for (int i = 1; i < COMMAND_COUNT; i++)
        cmds[i] = const_cast<char **>(p2_args);

    int pipe_fds[(COMMAND_COUNT - 1) * 2]; // 8 個 Pipe，16 個 fd
    for (int i = 0; i < COMMAND_COUNT - 1; i++)
        pipe(pipe_fds + i * 2); // 建立 i-th pipe

    pid_t pid;

    for (int i = 0; i < COMMAND_COUNT; i++)
    {

        pid = fork();
        if (pid == 0) // child
        {
            if (i != 0)
            {
                // 用 dup2 將 pipe 的 read end 複製成 stdin (fd=0)
                dup2(pipe_fds[(i - 1) * 2], STDIN_FILENO);
            }

            if (i != COMMAND_COUNT - 1)
            {
                // 用 dup2 將 pipe 的 write end 複製成 stdout (fd=1)
                dup2(pipe_fds[i * 2 + 1], STDOUT_FILENO);
            }

            // 關閉 pipe 開啟的 fd，因為此時 pipe 兩端已經複製成 stdin 或 stdout
            // parent 跟 child 都要關閉，避免其中一邊還開著 fd 導致程序無法結束
            if (i != 0)
            {
                close(pipe_fds[(i - 1) * 2]);     // 前一個命令與當前命令連接的 pipe 的 read end
                close(pipe_fds[(i - 1) * 2 + 1]); // 前一個命令與當前命令連接的 pipe 的 write end
            }

            execvp(*cmds[i], cmds[i]); // 屬於 exec 系列的函數，會取代目前的 process

            // execvp 正確執行的話，程式不會繼續到這裡
            fprintf(stderr, "Cannot run %s\n", *cmds[i]);
        }
        else // parent
        {
            // printf("- fork %d\n", pid);

            // 關閉開啟的 Pipe，Parent 跟 child 都要關閉，避免其中一邊還開著 fd 導致程序無法結束
            if (i != 0)
            {
                close(pipe_fds[(i - 1) * 2]);     // 前一個命令與當前命令連接的 pipe 的 read end
                close(pipe_fds[(i - 1) * 2 + 1]); // 前一個命令與當前命令連接的 pipe 的 write end
            }
        }
    }

    waitpid(pid, NULL, 0); // 等最後一個指令結束

    /* 步驟三 */
    // 模擬前一個命令結束之後，shell 顯示提示符號
    std::cout << "$" << std::endl;
}