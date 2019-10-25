# rts log
rts log is design for easy to use and portable.

## how to use

### step 1
confige rt log funtion

```
//rt log cfg
#define USE_RTS_LOG
#define USE_RTS_LOG_BACKEND_SEGGER_RTT
#define USE_RTS_LOG_LEVEL   RTS_LOG_LEVEL_DEBUG
#define USE_RTS_LOG_COLOR
```
### step 2
set rt log  backend(note:if USE_RTS_LOG_BACKEND_SEGGER_RTT no need user to set backend)

```
void rts_log_init(void)
{
//init hardward
}
void rts_log_putchar(char ch)
{
    //send one char
}
rts_log_init(rts_log_init,rts_log_putchar);
```

## example

in rts_cfg.h file

```
//rt log cfg
#define USE_RTS_LOG
#define USE_RTS_LOG_BACKEND_SEGGER_RTT
#define USE_RTS_LOG_LEVEL   RTS_LOG_LEVEL_DEBUG
#define USE_RTS_LOG_COLOR
```

in user main.c file

```
int main(void)
{
    rts_log_init(NULL,NULL);

    rts_log_debug("debug\r\n");
    rts_log_info("info\r\n");
    rts_log_waring("waring\r\n");
    rts_log_error("error\r\n");
}
```