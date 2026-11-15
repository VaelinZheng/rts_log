/*
 * Copyright (c) 2026, vaelin.zheng@gmail.com
 *
 * SPDX-License-Identifier: MIT
 */

#include "rts_log.h"
#if defined(CONFIG_RTS_LOG_ENABLE) && (CONFIG_RTS_LOG_ENABLE == 1)
#include "stdio.h"

#if defined(CONFIG_RTS_LOG_BACKEND_RTT) && (CONFIG_RTS_LOG_BACKEND_RTT == 1)
#include "RTT/RTT/SEGGER_RTT.c"
void __SEGGER_RTT_PutChar(char ch)
{
    SEGGER_RTT_PutChar(0,ch);
}
static void(*__init)(void)       = SEGGER_RTT_Init;
static void(*__putchar)(char ch) = __SEGGER_RTT_PutChar;
#else
static void(*__init)(void)       = NULL;
static void(*__putchar)(char ch) = NULL;
#endif

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
/* With ARMCC or IAR, printf directs to `fputc`. */
int fputc(int ch, FILE *f)
{
    (void)f; // Unused.

    if(__putchar)
    {
        __putchar((char)ch);
    }
    return ch;
}
#elif defined(__GNUC__)
/* With GCC, printf directs to `_write`. */
int _write(int file, char *ptr, int len)
{
    (void)file; // Unused.

    for (int i = 0; i < len; i++)
    {
        if(__putchar)
        {
            __putchar(*ptr++);
        }
    }
    return len;
}
#endif

void rts_log_init(void(*init)(void),void(*putchar)(char ch))
{
    if(init&&putchar)
    {
        __init=init;
        __putchar=putchar;
    }

    if(__init && __putchar)
    {
        __init();

        rts_log("\r\nrts log V%d.%d.%d\r\n\r\n", RTS_LOG_VERSION_MAJOR, RTS_LOG_VERSION_MINOR, RTS_LOG_VERSION_PATCH);
    }
    else
    {
        //normal can not be here
        while(1);
    }
}
#endif
