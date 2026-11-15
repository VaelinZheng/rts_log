# rts_log

rts_log is a small, portable logging component for embedded projects. It supports
printf-style messages, configurable log levels, a SEGGER RTT backend, and custom
output backends.

## Configuration

The component is configured through `Kconfig`. Enable `RTS_LOG_ENABLE`, select a
maximum log level, and choose a backend:

We strongly recommend using the **Menuconfig for VSCode** extension to configure
Kconfig options interactively and regenerate the configuration header. Avoid
editing the generated header by hand.

- `RTS_LOG_BACKEND_RTT` uses the bundled SEGGER RTT implementation (the default).
- `RTS_LOG_BACKEND_CUSTOM` uses callbacks supplied by the application.
- `RTS_LOG_USE_COLOR` enables colored output when using RTT.

When using the generated configuration header, define `KCONFIG_HEADER_FILE` in
the compiler options (for example, `KCONFIG_HEADER_FILE=rts_cfg.h`). The header
is included by `rts_log.h`. For a project without Kconfig, provide the equivalent
configuration defines in the header included by `KCONFIG_HEADER_FILE`.

## Adding the component

Add `rts_log.c` to the project sources and make the directory containing
`rts_log.h` available to the compiler. 

## Usage

Include `rts_log.h` and initialize the logger once during startup, before
writing log messages. With the RTT backend, pass `NULL` for both callbacks:

```c
#include <stdint.h>

#define RTS_LOG_TAG "[app] "
#include "rts_log.h"

int main(void)
{
    static const uint8_t sample[] = {0x10, 0x20, 0x30};

    rts_log_init(NULL, NULL);

    rts_log("Application started\r\n");
    rts_log_debug("debug value: %d\r\n", 1);
    rts_log_info("device ready\r\n");
    rts_log_warning("low battery\r\n");
    rts_log_error("operation failed: %d\r\n", -1);
    rts_log_dump_hex(sample, sizeof(sample));

    for (;;)
    {
    }
}
```

`RTS_LOG_TAG` is used by the level-specific logging macros. Define it before
including `rts_log.h`. Available levels are `NONE`, `ERROR`, `WARNING`, `INFO`,
and `DEBUG`; messages above the configured maximum level are compiled out.
`rts_log()` writes an untagged message, and the level-specific macros support
`printf` format specifiers.

## Custom output backend

For a custom backend, select `RTS_LOG_BACKEND_CUSTOM` and provide both callbacks
to `rts_log_init()`. The application is responsible for initializing its output
device and sending each character:

```c
#include "rts_log.h"

static void board_log_init(void)
{
    /* Initialize the UART or other output device. */
}

static void board_log_putchar(char ch)
{
    /* Send ch using the output device. */
}

void app_init(void)
{
    rts_log_init(board_log_init, board_log_putchar);
    rts_log_info("custom backend ready\r\n");
}
```

Both callbacks must be non-`NULL`. The logger routes `printf` output through
the character callback; the provided retargeting uses `fputc` with ARMCC/IAR
and `_write` with GCC.

## Third-party library: SEGGER RTT

This repository includes SEGGER's Real Time Transfer (RTT) target sources under
`RTT/`. The built-in RTT backend sends log output to RTT channel 0. Use a
compatible SEGGER debug probe and host tool to view the output. See the bundled
[RTT documentation](./RTT/README.md) and [SEGGER RTT information](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/).

RTT is a separate third-party component; its license is in
[RTT/LICENSE.md](./RTT/LICENSE.md). Follow that license's conditions when
redistributing the bundled RTT files. This component's MIT license does not
replace or change the RTT license.

## License

rts_log is licensed under the MIT License. See [LICENSE](./LICENSE) for the full
text and copyright notice.
