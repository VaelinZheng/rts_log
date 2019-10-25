#include "rts_log.h"
#ifdef USE_RTS_LOG

/** X.x.x: Major version */
#define RTS_LOG_VERSION_MAJOR      1
/** x.X.x: Minor version */
#define RTS_LOG_VERSION_MINOR      0
/** x.x.X: Revision*/
#define RTS_LOG_VERSION_REVISION   0

#include "stdio.h"

#ifdef USE_RTS_LOG_BACKEND_SEGGER_RTT
#include "segger_rtt/SEGGER_RTT.h"
void __SEGGER_RTT_PutChar(char ch)
{
    SEGGER_RTT_PutChar(0,ch);
}
static rts_log_init_t    __init     =SEGGER_RTT_Init;
static rts_log_putchar_t __putchar  =__SEGGER_RTT_PutChar;
#else
static rts_log_init_t    __init     =NULL;
static rts_log_putchar_t __putchar  =NULL;
#endif


int fputc(int ch, FILE *f)
{
    __putchar(ch);
    return (ch);
}

void rts_log_init(rts_log_init_t init,rts_log_putchar_t putchar)
{
    if(init&&putchar)
    {
        __init=init;
        __putchar=putchar;
    }

    if(__init&&__putchar)
    {
        __init();
        rts_log("\r\nrt log V%d.%d.%d\r\n\r\n",RTS_LOG_VERSION_MAJOR,RTS_LOG_VERSION_MINOR,RTS_LOG_VERSION_REVISION);
    }
    else
    {
        //normal can not to here
        while(1);
    }
}
#endif
