/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'hw3proc' in SOPC Builder design 'hw3proc'
 * SOPC Builder design path: ../../hw3proc.sopcinfo
 *
 * Generated: Mon Mar 14 22:58:24 PDT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00001820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x17
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x17
#define ALT_CPU_NAME "hw3proc"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00001820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x17
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x17
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_SRAM


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x20f8
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x20f8
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x20f8
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "hw3proc"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK HR_TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * hex_0 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_0 altera_avalon_pio
#define HEX_0_BASE 0x20b0
#define HEX_0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_0_CAPTURE 0
#define HEX_0_DATA_WIDTH 7
#define HEX_0_DO_TEST_BENCH_WIRING 0
#define HEX_0_DRIVEN_SIM_VALUE 0
#define HEX_0_EDGE_TYPE "NONE"
#define HEX_0_FREQ 50000000
#define HEX_0_HAS_IN 0
#define HEX_0_HAS_OUT 1
#define HEX_0_HAS_TRI 0
#define HEX_0_IRQ -1
#define HEX_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_0_IRQ_TYPE "NONE"
#define HEX_0_NAME "/dev/hex_0"
#define HEX_0_RESET_VALUE 0
#define HEX_0_SPAN 16
#define HEX_0_TYPE "altera_avalon_pio"


/*
 * hex_1 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_1 altera_avalon_pio
#define HEX_1_BASE 0x20a0
#define HEX_1_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_1_CAPTURE 0
#define HEX_1_DATA_WIDTH 7
#define HEX_1_DO_TEST_BENCH_WIRING 0
#define HEX_1_DRIVEN_SIM_VALUE 0
#define HEX_1_EDGE_TYPE "NONE"
#define HEX_1_FREQ 50000000
#define HEX_1_HAS_IN 0
#define HEX_1_HAS_OUT 1
#define HEX_1_HAS_TRI 0
#define HEX_1_IRQ -1
#define HEX_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_1_IRQ_TYPE "NONE"
#define HEX_1_NAME "/dev/hex_1"
#define HEX_1_RESET_VALUE 0
#define HEX_1_SPAN 16
#define HEX_1_TYPE "altera_avalon_pio"


/*
 * hex_2 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_2 altera_avalon_pio
#define HEX_2_BASE 0x2090
#define HEX_2_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_2_CAPTURE 0
#define HEX_2_DATA_WIDTH 7
#define HEX_2_DO_TEST_BENCH_WIRING 0
#define HEX_2_DRIVEN_SIM_VALUE 0
#define HEX_2_EDGE_TYPE "NONE"
#define HEX_2_FREQ 50000000
#define HEX_2_HAS_IN 0
#define HEX_2_HAS_OUT 1
#define HEX_2_HAS_TRI 0
#define HEX_2_IRQ -1
#define HEX_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_2_IRQ_TYPE "NONE"
#define HEX_2_NAME "/dev/hex_2"
#define HEX_2_RESET_VALUE 0
#define HEX_2_SPAN 16
#define HEX_2_TYPE "altera_avalon_pio"


/*
 * hex_3 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_3 altera_avalon_pio
#define HEX_3_BASE 0x2080
#define HEX_3_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_3_CAPTURE 0
#define HEX_3_DATA_WIDTH 7
#define HEX_3_DO_TEST_BENCH_WIRING 0
#define HEX_3_DRIVEN_SIM_VALUE 0
#define HEX_3_EDGE_TYPE "NONE"
#define HEX_3_FREQ 50000000
#define HEX_3_HAS_IN 0
#define HEX_3_HAS_OUT 1
#define HEX_3_HAS_TRI 0
#define HEX_3_IRQ -1
#define HEX_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_3_IRQ_TYPE "NONE"
#define HEX_3_NAME "/dev/hex_3"
#define HEX_3_RESET_VALUE 0
#define HEX_3_SPAN 16
#define HEX_3_TYPE "altera_avalon_pio"


/*
 * hex_4 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_4 altera_avalon_pio
#define HEX_4_BASE 0x2070
#define HEX_4_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_4_CAPTURE 0
#define HEX_4_DATA_WIDTH 7
#define HEX_4_DO_TEST_BENCH_WIRING 0
#define HEX_4_DRIVEN_SIM_VALUE 0
#define HEX_4_EDGE_TYPE "NONE"
#define HEX_4_FREQ 50000000
#define HEX_4_HAS_IN 0
#define HEX_4_HAS_OUT 1
#define HEX_4_HAS_TRI 0
#define HEX_4_IRQ -1
#define HEX_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_4_IRQ_TYPE "NONE"
#define HEX_4_NAME "/dev/hex_4"
#define HEX_4_RESET_VALUE 0
#define HEX_4_SPAN 16
#define HEX_4_TYPE "altera_avalon_pio"


/*
 * hex_5 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_5 altera_avalon_pio
#define HEX_5_BASE 0x2060
#define HEX_5_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_5_CAPTURE 0
#define HEX_5_DATA_WIDTH 7
#define HEX_5_DO_TEST_BENCH_WIRING 0
#define HEX_5_DRIVEN_SIM_VALUE 0
#define HEX_5_EDGE_TYPE "NONE"
#define HEX_5_FREQ 50000000
#define HEX_5_HAS_IN 0
#define HEX_5_HAS_OUT 1
#define HEX_5_HAS_TRI 0
#define HEX_5_IRQ -1
#define HEX_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_5_IRQ_TYPE "NONE"
#define HEX_5_NAME "/dev/hex_5"
#define HEX_5_RESET_VALUE 0
#define HEX_5_SPAN 16
#define HEX_5_TYPE "altera_avalon_pio"


/*
 * hex_6 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_6 altera_avalon_pio
#define HEX_6_BASE 0x2050
#define HEX_6_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_6_CAPTURE 0
#define HEX_6_DATA_WIDTH 7
#define HEX_6_DO_TEST_BENCH_WIRING 0
#define HEX_6_DRIVEN_SIM_VALUE 0
#define HEX_6_EDGE_TYPE "NONE"
#define HEX_6_FREQ 50000000
#define HEX_6_HAS_IN 0
#define HEX_6_HAS_OUT 1
#define HEX_6_HAS_TRI 0
#define HEX_6_IRQ -1
#define HEX_6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_6_IRQ_TYPE "NONE"
#define HEX_6_NAME "/dev/hex_6"
#define HEX_6_RESET_VALUE 0
#define HEX_6_SPAN 16
#define HEX_6_TYPE "altera_avalon_pio"


/*
 * hex_7 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_7 altera_avalon_pio
#define HEX_7_BASE 0x2040
#define HEX_7_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_7_CAPTURE 0
#define HEX_7_DATA_WIDTH 7
#define HEX_7_DO_TEST_BENCH_WIRING 0
#define HEX_7_DRIVEN_SIM_VALUE 0
#define HEX_7_EDGE_TYPE "NONE"
#define HEX_7_FREQ 50000000
#define HEX_7_HAS_IN 0
#define HEX_7_HAS_OUT 1
#define HEX_7_HAS_TRI 0
#define HEX_7_IRQ -1
#define HEX_7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_7_IRQ_TYPE "NONE"
#define HEX_7_NAME "/dev/hex_7"
#define HEX_7_RESET_VALUE 0
#define HEX_7_SPAN 16
#define HEX_7_TYPE "altera_avalon_pio"


/*
 * hr_timer configuration
 *
 */

#define ALT_MODULE_CLASS_hr_timer altera_avalon_timer
#define HR_TIMER_ALWAYS_RUN 0
#define HR_TIMER_BASE 0x2000
#define HR_TIMER_COUNTER_SIZE 32
#define HR_TIMER_FIXED_PERIOD 0
#define HR_TIMER_FREQ 50000000
#define HR_TIMER_IRQ 1
#define HR_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define HR_TIMER_LOAD_VALUE 49999
#define HR_TIMER_MULT 0.001
#define HR_TIMER_NAME "/dev/hr_timer"
#define HR_TIMER_PERIOD 1
#define HR_TIMER_PERIOD_UNITS "ms"
#define HR_TIMER_RESET_OUTPUT 0
#define HR_TIMER_SNAPSHOT 1
#define HR_TIMER_SPAN 32
#define HR_TIMER_TICKS_PER_SEC 1000
#define HR_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define HR_TIMER_TYPE "altera_avalon_timer"


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x20f8
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * ledg configuration
 *
 */

#define ALT_MODULE_CLASS_ledg altera_avalon_pio
#define LEDG_BASE 0x20c0
#define LEDG_BIT_CLEARING_EDGE_REGISTER 0
#define LEDG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDG_CAPTURE 0
#define LEDG_DATA_WIDTH 8
#define LEDG_DO_TEST_BENCH_WIRING 0
#define LEDG_DRIVEN_SIM_VALUE 0
#define LEDG_EDGE_TYPE "NONE"
#define LEDG_FREQ 50000000
#define LEDG_HAS_IN 0
#define LEDG_HAS_OUT 1
#define LEDG_HAS_TRI 0
#define LEDG_IRQ -1
#define LEDG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDG_IRQ_TYPE "NONE"
#define LEDG_NAME "/dev/ledg"
#define LEDG_RESET_VALUE 0
#define LEDG_SPAN 16
#define LEDG_TYPE "altera_avalon_pio"


/*
 * ledr configuration
 *
 */

#define ALT_MODULE_CLASS_ledr altera_avalon_pio
#define LEDR_BASE 0x20d0
#define LEDR_BIT_CLEARING_EDGE_REGISTER 0
#define LEDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDR_CAPTURE 0
#define LEDR_DATA_WIDTH 18
#define LEDR_DO_TEST_BENCH_WIRING 0
#define LEDR_DRIVEN_SIM_VALUE 0
#define LEDR_EDGE_TYPE "NONE"
#define LEDR_FREQ 50000000
#define LEDR_HAS_IN 0
#define LEDR_HAS_OUT 1
#define LEDR_HAS_TRI 0
#define LEDR_IRQ -1
#define LEDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDR_IRQ_TYPE "NONE"
#define LEDR_NAME "/dev/ledr"
#define LEDR_RESET_VALUE 0
#define LEDR_SPAN 16
#define LEDR_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x0
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "hw3proc_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 4096
#define ONCHIP_MEMORY2_0_SPAN 4096
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sram_0 altera_up_avalon_sram
#define SRAM_0_BASE 0x400000
#define SRAM_0_IRQ -1
#define SRAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SRAM_0_NAME "/dev/sram_0"
#define SRAM_0_SPAN 2097152
#define SRAM_0_TYPE "altera_up_avalon_sram"


/*
 * switches configuration
 *
 */

#define ALT_MODULE_CLASS_switches altera_avalon_pio
#define SWITCHES_BASE 0x20e0
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 0
#define SWITCHES_DATA_WIDTH 18
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "NONE"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ -1
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES_IRQ_TYPE "NONE"
#define SWITCHES_NAME "/dev/switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x20f0
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1646718024
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * system_timer configuration
 *
 */

#define ALT_MODULE_CLASS_system_timer altera_avalon_timer
#define SYSTEM_TIMER_ALWAYS_RUN 0
#define SYSTEM_TIMER_BASE 0x2020
#define SYSTEM_TIMER_COUNTER_SIZE 32
#define SYSTEM_TIMER_FIXED_PERIOD 0
#define SYSTEM_TIMER_FREQ 50000000
#define SYSTEM_TIMER_IRQ 2
#define SYSTEM_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYSTEM_TIMER_LOAD_VALUE 49999
#define SYSTEM_TIMER_MULT 0.001
#define SYSTEM_TIMER_NAME "/dev/system_timer"
#define SYSTEM_TIMER_PERIOD 1
#define SYSTEM_TIMER_PERIOD_UNITS "ms"
#define SYSTEM_TIMER_RESET_OUTPUT 0
#define SYSTEM_TIMER_SNAPSHOT 1
#define SYSTEM_TIMER_SPAN 32
#define SYSTEM_TIMER_TICKS_PER_SEC 1000
#define SYSTEM_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYSTEM_TIMER_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
