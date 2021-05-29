/*
 * Copyright (c) 2020, Xiaojin.Zheng
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date             Author                  Notes
 * 2020-11-08       Xiaojin.Zheng           add license
 *
*/

#include "rts_log.h"
#if (RTS_LOG_ENABLE)

/** X.x.x: Major version */
#define RTS_LOG_VERSION_MAJOR      1
/** x.X.x: Minor version */
#define RTS_LOG_VERSION_MINOR      0
/** x.x.X: Revision*/
#define RTS_LOG_VERSION_REVISION   0

#include "stdio.h"

#if (RTS_LOG_BACKEND==RTS_LOG_BACKEND_RTT)
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
    __putchar(ch);
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
        rts_log("\r\nrts log V%d.%d.%d\r\n\r\n",RTS_LOG_VERSION_MAJOR,RTS_LOG_VERSION_MINOR,RTS_LOG_VERSION_REVISION);
    }
    else
    {
        //normal can not be here
        while(1);
    }
}
#endif
