#ifndef _RTS_LOG_H
#define _RTS_LOG_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_RTS_CFG
#include "rts_cfg.h"
#endif

#ifdef USE_RTS_LOG
#include "stdio.h"

//log level define
#define RTS_LOG_LEVEL_DEFAULT  0
#define RTS_LOG_LEVEL_ERROR    1
#define RTS_LOG_LEVEL_WARNING  2
#define RTS_LOG_LEVEL_INFO     3
#define RTS_LOG_LEVEL_DEBUG    4


#ifndef USE_RTS_LOG_LEVEL
#define USE_RTS_LOG_LEVEL    RTS_LOG_LEVEL_DEFAULT
#endif

//color define
#ifdef USE_RTS_LOG_COLOR
    #ifndef USE_RTS_LOG_BACKEND_SEGGER_RTT
    #error "RTS_LOG_COLOR only support segger rtt"
    #endif
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
#if USE_RTS_LOG_LEVEL==RTS_LOG_LEVEL_DEFAULT
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    do{}while(0)
#elif USE_RTS_LOG_LEVEL==RTS_LOG_LEVEL_ERROR
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif USE_RTS_LOG_LEVEL==RTS_LOG_LEVEL_WARNING
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   printf(LOG_W_COLOR"[W]"format,##__VA_ARGS__)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif USE_RTS_LOG_LEVEL==RTS_LOG_LEVEL_INFO
    #define rts_log(format,...)          printf(LOG_COLOR format,##__VA_ARGS__)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     printf(LOG_I_COLOR"[I]"format,##__VA_ARGS__)
    #define rts_log_waring(format,...)   printf(LOG_W_COLOR"[W]"format,##__VA_ARGS__)
    #define rts_log_error(format,...)    printf(LOG_E_COLOR"[E]"format,##__VA_ARGS__)
#elif USE_RTS_LOG_LEVEL==RTS_LOG_LEVEL_DEBUG
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
#else
    #define rts_log(format,...)          do{}while(0)
    #define rts_log_debug(format,...)    do{}while(0)
    #define rts_log_info(format,...)     do{}while(0)
    #define rts_log_waring(format,...)   do{}while(0)
    #define rts_log_error(format,...)    do{}while(0)
#endif

//log init funtion
#ifdef USE_RTS_LOG
typedef void (*rts_log_init_t)(void);
typedef void (*rts_log_putchar_t)(char ch);

void rts_log_init(rts_log_init_t init,rts_log_putchar_t putchar);
#else
#define rts_log_init(init,putchar) do{}while(0)  //avoid link not declared

#endif

#ifdef __cplusplus
}
#endif
#endif
