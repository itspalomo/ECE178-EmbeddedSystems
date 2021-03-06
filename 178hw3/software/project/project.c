/*
 * "Small Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It requires a STDOUT  device in your system's hardware.
 *
 * The purpose of this example is to demonstrate the smallest possible Hello
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete
 * description.
 *
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION
 *      This removes software exception handling, which means that you cannot
 *      run code compiled for Nios II cpu with a hardware multiplier on a core
 *      without a the multiply unit. Check the Nios II Software Developers
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks
 *      support for buffering, file IO, floating point and getch(), etc.
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */


#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"

#define HEXVAL_0 0b11000000 /*0*/
#define HEXVAL_1 0b11111001 /*1*/
#define HEXVAL_2 0b10100100 /*2*/
#define HEXVAL_3 0b10110000 /*3*/
#define HEXVAL_4 0b10011001 /*4*/
#define HEXVAL_5 0b10010010 /*5*/
#define HEXVAL_6 0b10000010 /*6*/
#define HEXVAL_7 0b11111000 /*7*/
#define HEXVAL_8 0b10000000 /*8*/
#define HEXVAL_9 0b10011000 /*9*/
#define HEXVAL_9 0b10011000 /*A*/
#define HEXVAL_9 0b10011000 /*b*/
#define HEXVAL_9 0b10011000 /*c*/
#define HEXVAL_9 0b10011000 /*d*/
#define HEXVAL_NEG 0b0111111 /*d*/
#define HEXVAL_CLEAR 0b11111111 /*Clear*/

int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};

void part1();
void part2();

void clearhex();
void decimal_to_hex(alt_u8);


int main()
{

  part2();


  return 0;
}



void clearhex()
{
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}

void part1()
{
	char led;
	alt_putstr("\nPART 1: \n Please enter 1-4 to turn on the respective Green LED on the DE2. \n");
	alt_putstr("\nEnter 5 or 6 to clear the LEDs \n");

	while (1)
	{
		led = alt_getchar();

		switch(led)
		{
		case '1':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 1);
			break;

		case '2':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0b0010);
			break;

		case '3':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0b0100);
			break;

		case '4':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0b1000);
			break;

		case '\n':
			break;

		case '5':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0b0000);
			break;

		case '6':
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0b0000);
			break;

		default:
			alt_putstr("\nValue entered not valid, try again: ");
			break;

		}
	}
}

void part2()
{
	alt_u8 uhex;
	alt_u16 check;

	alt_putstr("\nPART 2: \n Use switches to get 8 bit representation on HEX0-HEX2. \n");
	alt_putstr("\nThe 9th switch, sw[8] represents signed(on) vs unsigned(off) representation. \n");

	while (1)
		{
			check = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
			uhex = check & 0b11111111;
			if (check >= 0b0000000100000000)
			{
				if (uhex < 0b10000000)
				{
					uhex &= 0b01111111;

					decimal_to_hex(uhex);
				}else
				{
					if (uhex == 0b10000000)
						uhex = 0b00000000;
					else
						uhex = ~(uhex)+1;

					decimal_to_hex(uhex);
				}

			}else
				decimal_to_hex(uhex);
		}
}

void decimal_to_hex(alt_u8 uhex)
{
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, hextable[(uhex)%10]);
	uhex /= 10;

	IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, hextable[uhex%10]);


	IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_6_BASE,HEXVAL_CLEAR);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX_7_BASE,HEXVAL_CLEAR);
}
