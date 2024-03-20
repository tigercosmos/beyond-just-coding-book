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
    // 模擬剛開啟 Shell 的顯示提示符號
    std::cout << "$" << std::endl;

    // 處理 SIGCHLD，可以避免 Child 疆屍程序
    struct sigaction sigchld_action;
    sigchld_action.sa_handler = SIG_DFL,
    sigchld_action.sa_flags = SA_NOCLDWAIT;

    // 模擬下達指令 ls | cat | cat | cat | cat | cat | cat | cat | cat
    std::cout << "$ ls | cat | cat | cat | cat | cat | cat | cat | cat" << std::endl;

    // Shell 會需要 Parse 指令，我們假設 Shell 已經將指令 Parse 好

    // 接下來 Shell 的邏輯是，每一個指令都 fork 一個新的 Process，然後將 pipe 的讀取端或寫入端取代成 stdin 或 stdout

    const char *ls_cmd = "ls";
    const char *cat_cmd = "cat";

    char **cmds[COMMAND_COUNT];

    const char *p1_args[] = {ls_cmd, NULL};
    cmds[0] = const_cast<char **>(p1_args);

    const char *p2_args[] = {cat_cmd, NULL}; // 只是 DEMO，所以重複利用，真實世界 Shell 會一個一個 Parse
    for (int i = 1; i < COMMAND_COUNT; i++)
        cmds[i] = const_cast<char **>(p2_args);

    int pipes[(COMMAND_COUNT - 1) * 2]; // 9 個指令，中間需要 8 條 pipe
    for (int i = 0; i < COMMAND_COUNT - 1; i++)
        pipe(pipes + i * 2); // 建立 i-th pipe

    pid_t pid;

    for (int i = 0; i < COMMAND_COUNT; i++)
    {

        pid = fork();
        if (pid == 0) // Child
        {
            // 讀取端
            if (i != 0)
            {
                // 用 dup2 將 pipe 讀取端取代成 stdin
                dup2(pipes[(i - 1) * 2], STDIN_FILENO);
            }

            // 用 dup2 將 pipe 寫入端取代成 stdout
            if (i != COMMAND_COUNT - 1)
            {
                dup2(pipes[i * 2 + 1], STDOUT_FILENO);
            }

            // 關掉之前一次打開的
            for (int j = 0; j < (COMMAND_COUNT - 1) * 2; j++)
            {
                close(pipes[j]);
            }

            execvp(*cmds[i], cmds[i]); // 屬於 exec 系列的函數，會取代目前的 Process

            // execvp 正確執行的話，程式不會繼續到這裡
            fprintf(stderr, "Cannot run %s\n", *cmds[i]);
        }
        else // Parent
        {
            // printf("- fork %d\n", pid);

            if (i != 0)
            {
                close(pipes[(i - 1) * 2]);     // 前一個的寫
                close(pipes[(i - 1) * 2 + 1]); // 當前的讀
            }
        }
    }

    waitpid(pid, NULL, 0); // 等最後一個指令結束

    // 模擬前一個命令結束之後，Shell 顯示提示符號
    std::cout << "$" << std::endl; 
}