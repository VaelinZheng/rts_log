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

#ifndef _RTS_LOG_H
#define _RTS_LOG_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_RTS_CFG
#include "rts_cfg.h"
#endif

#if (RTS_LOG_ENABLE)
#include "stdio.h"

//log level define
#define RTS_LOG_LEVEL_DEFAULT  0
#define RTS_LOG_LEVEL_ERROR    1
#define RTS_LOG_LEVEL_WARNING  2
#define RTS_LOG_LEVEL_INFO     3
#define RTS_LOG_LEVEL_DEBUG    4


#ifndef RTS_LOG_LEVEL
#define RTS_LOG_LEVEL    RTS_LOG_LEVEL_DEFAULT
#endif

//color define
#if (RTS_LOG_COLOR_ENABLE)
    #include "segger_rtt/SEGGER_RTT.h"
    #define LOG_COLOR   RTT_CTRL_TEXT_WHITE
    #define LOG_D_COLOR RTT_CTRL_TEXT_WHITE
    #define LOG_I_COLOR RTT_CTRL_TEXT_WHITE
    #define LOG_W_COLOR RTT_CTRL_TEXT_YELLOW
    #define LOG_E_COLOR RTT_CTRL_TEXT_RED
#else
    #define LOG_COLOR
    #define LOG_D_COLOR
    #define LOG_I_COLOR
    #define LOG_W_COLOR
    #define LOG_E_COLOR
#endif

//log define
#if RTS_LOG_LEVEL==RTS_LOG_LEVEL_DEFAULT
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    do{}while(0)
#elif RTS_LOG_LEVEL==RTS_LOG_LEVEL_ERROR
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif RTS_LOG_LEVEL==RTS_LOG_LEVEL_WARNING
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   printf(LOG_W_COLOR"[W]"format,##__VA_ARGS__)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif RTS_LOG_LEVEL==RTS_LOG_LEVEL_INFO
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     printf(LOG_I_COLOR"[I]"format,##__VA_ARGS__)
    #define rts_log_waring(format,...)   printf(LOG_W_COLOR"[W]"format,##__VA_ARGS__)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif RTS_LOG_LEVEL==RTS_LOG_LEVEL_DEBUG
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    printf(LOG_D_COLOR"[D]"format,##__VA_ARGS__)
    #define rts_log_info(format,...)     printf(LOG_I_COLOR"[I]"format,##__VA_ARGS__)
    #define rts_log_waring(format,...)   printf(LOG_W_COLOR"[W]"format,##__VA_ARGS__)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#else
    #define rts_log(format,...)          do{}while(0)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    do{}while(0)
#endif
#endif

//log init funtion
#if (RTS_LOG_ENABLE)

/*
 * init & putchar input NULL will use rtt as default
 *
 */
void rts_log_init(void(*init)(void),void(*putchar)(char ch));

#else
//avoid link not declared
#define rts_log_init(init,putchar)  do{}while(0)

#define rts_log(format,...)          do{}while(0)
#define rts_log_debug(format,...)    do{}while(0)
#define rts_log_info(format,...)     do{}while(0)
#define rts_log_waring(format,...)   do{}while(0)
#define rts_log_error(format,...)    do{}while(0)

#endif

#ifdef __cplusplus
}
#endif
#endif
