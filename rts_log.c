/*
 * Copyright (c) 2020-2025, Xiaojin.Zheng
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date             Author                  Notes
 * 2020-11-08       Xiaojin.Zheng           add license
 * 2025-05-08       Xiaojin.Zheng           add support tag & dump hex
 * 2025-12-16       Xiaojin.Zheng           add support Kconfig
*/

#include "rts_log.h"
#if defined(CONFIG_RTS_LOG_ENABLE) && (CONFIG_RTS_LOG_ENABLE == 1)
#include "stdio.h"

#if defined(CONFIG_RTS_LOG_BACKEND_RTT) && (CONFIG_RTS_LOG_BACKEND_RTT == 1)
#include "segger_rtt/SEGGER_RTT.h"
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


int fputc(int ch, FILE *f)
{
    (void) f;//unused

    __putchar((char)ch);
    return (ch);
}

void rts_log_init(void(*init)(void),void(*putchar)(char ch))
{
    if(init&&putchar)
    {
        __init=init;
        __putchar=putchar;
    }

    if(__init&&__putchar)
    {
        __init();
#if defined(CONFIG_RTS_LOGO_ENABLE) && (CONFIG_RTS_LOGO_ENABLE == 1)
        #include "rts_logo.h"
        rts_log("%s",rts_logo);
#else
        rts_log("\r\nrts log V%d.%d.%d\r\n\r\n",RTS_LOG_VERSION_MAJOR,RTS_LOG_VERSION_MINOR,RTS_LOG_VERSION_REVISION);
#endif
    }
    else
    {
        //normal can not be here
        while(1);
    }
}
#endif
