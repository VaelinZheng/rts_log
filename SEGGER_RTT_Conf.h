/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
*        SEGGER RTT * Real Time Transfer for embedded targets        *
*                  https://github.com/SEGGERMicro/RTT                *
*                                                                    *
**********************************************************************

---------------------------END-OF-HEADER------------------------------
Purpose : User configuration file for RTT.
          For available configuration,
          refer to SEGGER_RTT_ConfDefaults.h.

----------------------------------------------------------------------
*/

#ifndef SEGGER_RTT_CONF_H
#define SEGGER_RTT_CONF_H


/*********************************************************************
*
*       Defines, configurable
*
**********************************************************************
*/

#include "rts_log.h"

// Max. number of up-buffers (T->H) available on this target    (Default: 1)
#if (CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS)
#define SEGGER_RTT_MAX_NUM_UP_BUFFERS CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS
#else
#define SEGGER_RTT_MAX_NUM_UP_BUFFERS (1)
#endif

// Max. number of down-buffers (H->T) available on this target  (Default: 1)
#if (CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS)
#define SEGGER_RTT_MAX_NUM_DOWN_BUFFERS CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS
#else
#define SEGGER_RTT_MAX_NUM_DOWN_BUFFERS (1)
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

#endif
/*************************** End of file ****************************/
