/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

/*Address Map
 * 0x0000_20b0 - 0x0000_20bf
0x0000_20a0 - 0x0000_20af
0x0000_2090 - 0x0000_209f
0x0000_2080 - 0x0000_208f
0x0000_2070 - 0x0000_207f
0x0000_2060 - 0x0000_206f
0x0000_2050 - 0x0000_205f
0x0000_2040 - 0x0000_204f
0x0000_2000 - 0x0000_201f
0x0000_1800 - 0x0000_1fff	0x0000_1800 - 0x0000_1fff
0x0000_20f8 - 0x0000_20ff
0x0000_20c0 - 0x0000_20cf
0x0000_20d0 - 0x0000_20df
0x0000_0000 - 0x0000_0fff	0x0000_0000 - 0x0000_0fff
0x0040_0000 - 0x005f_ffff	0x0040_0000 - 0x005f_ffff
0x0000_20e0 - 0x0000_20ef
0x0000_20f0 - 0x0000_20f7
0x0000_2020 - 0x0000_203f	 */

#include <stdio.h>
#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include <unistd.h>
#include <time.h>
#include "altera_avalon_timer_regs.h"

volatile int ledg = 0x000020c0;
volatile int switch_base = 0x000020e0;

volatile int pushbutton = 0x00003000;

volatile int hex0 = 0x000020b0;
volatile int hex1 = 0x000020a0;
volatile int hex2 = 0x00002090;
volatile int hex3 = 0x00002080;
volatile int hex4 = 0x00002070;
volatile int hex5 = 0x00002060;
volatile int hex6 = 0x00002050;
volatile int hex7 = 0x00002040;


#define HEXVAL_0 0b11000000
#define HEXVAL_1 0b11111001
#define HEXVAL_2 0b10100100
#define HEXVAL_3 0b10110000
#define HEXVAL_4 0b10011001
#define HEXVAL_5 0b10010010
#define HEXVAL_6 0b10000010
#define HEXVAL_7 0b11111000
#define HEXVAL_8 0b10000000
#define HEXVAL_9 0b10011000
#define HEXVAL_CLEAR 0b11111111


int main()
{
  printf("Hello from Nios II!\n");

  return 0;
}

