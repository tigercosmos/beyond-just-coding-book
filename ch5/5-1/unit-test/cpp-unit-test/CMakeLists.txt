cmake_minimum_required(VERSION 3.14)
project(myproject)

set(CMAKE_CXX_STANDARD 11)

# 建立 foo 函示庫
add_library(foo STATIC foo.cpp)

# 加入 include 資料夾給 foo 函示庫
target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 建立可執行檔 main
add_executable(main main.cpp)

# 將可執行檔和函示庫做連結
target_link_libraries(main PUBLIC foo)

# 使用 FetchContent 模組
include(FetchContent)
# 下載和引入 Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# 開啟 CMake 測試
enable_testing()

# 建立一個測試用的可執行檔 test_foo
add_executable(test_foo test_foo.cpp)
# 連結必要函示庫給 test_foo
target_link_libraries(test_foo PRIVATE foo gtest gtest_main)

# 把 test_foo 加進命名 foo_unit_test 的測試
add_test(
    NAME foo_unit_test
    COMMAND test_foo
)

# test_application 比照辦理
add_executable(test_application test_application.cpp)
# 多連結 gmock
target_link_libraries(test_application PRIVATE foo gtest gmock gtest_main)
add_test(
    NAME application_unit_test
    COMMAND test_application
)