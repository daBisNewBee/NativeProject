//
// Created by Salmon on 2021/2/19.
/*
 *
 *
 *
之前有个日志问题，跟你同步下结果，不知道还记不记得。

之前的问题代码：

static void LogCallbackBrief(__attribute__((unused)) void *ptr, int level, const char *fmt, va_list vl)
{
    if (level > av_log_get_level())
        return;

    int xmlv __attribute__((unused)) = LogLevelAvToXm(level);
    FFMPEGLOG(xmlv, XM_FFMPEG_LOG_TAG, fmt, vl);
}


void AePrintLog(const LogLevel level, const char *filename, const int line,
                const char *format, ...);


#define FFMPEGLOG(level, TAG, format, ...) \
    AePrintLog(level, __FILE__, __LINE__, format, TAG, ##__VA_ARGS__)


崩溃的是AePrintLog。

"..."，相当于在需要传入具体可变参数的地方，又传入了一个va_list，使得结果不确定。

实际，在接受可变参数的地方，最好使用va_list，而不是...，因为参数本身可能包括了va_list

比如

#define FFMPEGLOG(level, TAG, format, args)

就好了
 * */
//

#include <stdio.h>
#include <stdarg.h>

// 它(这里指'...')被表示成零个或多个符号
#define printf_debug(...) printf(__VA_ARGS__)

// 一般会带上"##"，如果可变参数被忽略或为空，'##'操作将使预处理器(preprocessor)去除掉它前面的那个逗号
#define printf_debug_format_1(format, ...) printf(format, ##__VA_ARGS__)
#define printf_debug_format_2(format, ...) printf(format, __VA_ARGS__)

// 这种方式易错！！建议使用 va_list接收可变参数，而不是"..."，因为可变参数中可能包括"va_list"
#define FFMPEGLOG_ERROR(format, ...) printf(format, ##__VA_ARGS__)

void my_print(const char* format, va_list args) {
    char string[256];
    vsprintf(string, format, args);
    printf("[my_print]%s", string);
}

#define FFMPEGLOG_CORRECT(format, args) my_print(format, args);

int printf_debug_ex(const char * format, ...) {
    va_list args;
    va_start(args, format);

    va_list copy_args;
    va_copy(copy_args, args);
//    FFMPEGLOG_ERROR(format, copy_args); // 错误示范：应该传入具体可变参数，实际传入"va_list"
    FFMPEGLOG_CORRECT(format, copy_args); // 正确示范：接收参数使用"va_list"
    va_end(copy_args);

    // 使用format，可以打印行号、文件名等多种格式
    char string[256];
    vsprintf(string, format, args);
    printf("[%s]%s", "DEBUG", string);
    va_end(args);
}

int main() {
    printf_debug("Hello MAIN %d, %s, %d\n", 1234, "aaa", 888);

    printf_debug_ex("Hello MAIN %d, %s, %d\n", 1234, "aaa", 888);

    printf_debug_format_1("-----> Hello MAIN\n"); // 可以不加参数
    printf_debug_format_1("-----> Hello MAIN %d, %s, %d\n", 1234, "aaa", 888); // 也可以有多个参数
    printf_debug_format_2("-----> Hello MAIN %d, %s, %d\n", 1234, "aaa", 888); // 必须有多个参数

    FFMPEGLOG_ERROR("-----> Hello MAIN %d, %s, %d\n", 1234, "aaa", 888); // 必须有多个参数

    return 0;
}