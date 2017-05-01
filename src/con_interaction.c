#define _NOMAIN_
#include "zio-con.h"
#undef _NOMAIN_


extern short int debug;

void mlog(char* template, ...)
{
    va_list args;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);

    va_start(args, template);
    vprintf(template, args);
    va_end(args);

    putchar('\n');

    return;
}

void mwarn(char* template, ...)
{
    va_list args;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);

    va_start(args, template);
    vprintf(template, args);
    va_end(args);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
    putchar('\n');

    return;
}

void merror(char* template, ...)
{
    va_list args;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_RED|FOREGROUND_INTENSITY);

    va_start(args, template);
    vprintf(template, args);
    va_end(args);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
    putchar('\n');

    return;
}

void mdebug(char* template, ...)
{
    if(debug > 0) {
        va_list args;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_GREEN|FOREGROUND_INTENSITY);

        va_start(args, template);
        vprintf(template, args);
        va_end(args);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
        putchar('\n');
    }
    return;
}
