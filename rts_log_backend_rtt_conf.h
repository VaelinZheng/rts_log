#ifndef _RTS_LOG_BACKEND_RTT_CONF_H_
#define _RTS_LOG_BACKEND_RTT_CONF_H_
#include "rts_log.h"

// Max. number of up-buffers (T->H) available on this target    (Default: 0)
#if (CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS)
#define SEGGER_RTT_MAX_NUM_UP_BUFFERS CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS
#else
#define SEGGER_RTT_MAX_NUM_UP_BUFFERS (1)
#endif

// Max. number of down-buffers (H->T) available on this target  (Default: 0)
#if (CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS)
#define SEGGER_RTT_MAX_NUM_DOWN_BUFFERS CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS
#else
#define SEGGER_RTT_MAX_NUM_DOWN_BUFFERS (0)
#endif

// Size of the buffer for terminal output of target, up to host (Default: 128)
#if (CONFIG_SEGGER_RTT_BUFFER_SIZE_UP)
#define BUFFER_SIZE_UP CONFIG_SEGGER_RTT_BUFFER_SIZE_UP
#else
#define BUFFER_SIZE_UP (128)
#endif

// Size of the buffer for terminal input to target from host (Usually keyboard input) (Default: 16)
#if (CONFIG_SEGGER_RTT_BUFFER_SIZE_DOWN)
#define BUFFER_SIZE_DOWN CONFIG_SEGGER_RTT_BUFFER_SIZE_DOWN
#else
#define BUFFER_SIZE_DOWN (16)
#endif

#endif // _RTS_LOG_BACKEND_RTT_CONF_H_
