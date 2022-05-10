#include "system.h"
#include "io.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_up_avalon_rs232.h"
#include "altera_up_avalon_rs232_regs.h"
#include "time.h"

volatile int edge_capture;

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
#define HEXVAL_NEG 0b0111111 /*-*/
#define HEXVAL_CLEAR 0b11111111 /*Clear*/

#define FIFO_EMPTY 0x0

int hextable[] = {HEXVAL_0, HEXVAL_1, HEXVAL_2, HEXVAL_3, HEXVAL_4,
					HEXVAL_5, HEXVAL_6, HEXVAL_7, HEXVAL_8, HEXVAL_9};


#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
	void handle_key_interrupts(void *context);
#else
	void handle_key_interrupts(void *context, alt_u32 id);
#endif

void init_key();
void clearhex();
void decimal_to_hex(alt_u8);

/*UART read bluetooth*/
void taskRS232(char* data);

int main()
{

	alt_printf("Smart Car Project\n");
	clearhex();
	IOWR_ALTERA_AVALON_PIO_DATA(MOT_0_BASE,0b0000);
	IOWR_ALTERA_AVALON_PIO_DATA(MOT_1_BASE,0b0000);

	clock_t begin, end;
	double time_spent = 0, distance = 0;

	init_key();

	while(1){

		if(IORD_ALTERA_AVALON_PIO_DATA(BUZZER_BASE)){
			usleep(100000);
			IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE,0b0);
		}

		IOWR_ALTERA_AVALON_PIO_DATA(HCTRIG_BASE,0b0);
		usleep(200000);

		IOWR_ALTERA_AVALON_PIO_DATA(HCTRIG_BASE,0b1);
		usleep(10);

		IOWR_ALTERA_AVALON_PIO_DATA(HCTRIG_BASE,0b0);

		while(IORD_ALTERA_AVALON_PIO_DATA(HCECHO_BASE) == 0){
			begin = clock();
		}
		while(IORD_ALTERA_AVALON_PIO_DATA(HCECHO_BASE) == 1){
			end = clock();
		}

		time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);

		distance = time_spent/17150;

		printf("Distance: %d \n", distance);


	}

  return 0;
}

void taskRS232(char* data)
{
	alt_u32 FIFO_write;
	alt_up_rs232_dev* rs232dev;

	/*Open serial port*/
	rs232dev = alt_up_rs232_open_dev("/dev/uart");
	if (rs232dev == NULL)
		alt_printf("Error: could not open RS232 UART\n");
	else
		alt_printf("Opened RS232 UART device\n");
		FIFO_write = alt_up_rs232_get_available_space_in_write_FIFO(rs232dev);
		if(FIFO_write == 0x80){
			alt_up_rs232_write_data(rs232dev,(alt_u8)data);
			alt_printf("Wrote %x to RS232 UART\n", (alt_u8)data);
		}
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


#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
void handle_key_interrupts(void *context) {
#else
void handle_key_interrupts(void *context, alt_u32 id)
{
#endif

volatile int *edge_capture_ptr = (volatile int*)context;
   *edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE);

   alt_u8 sw = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

   char STATUS = '1';

   IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0x0);

   if(edge_capture == 0b00001){/*STOP*/
	   IOWR(MOT_0_BASE, 0, 0b0000);
	   IOWR(MOT_1_BASE, 0, 0b0000);
	   IOWR(LEDR_BASE, 0, 0x00);
	   IOWR(LEDG_BASE, 0, 0x00);

	   IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE,0b1);

	   STATUS = 'S';
   }

   else if (edge_capture == 0b0010)/*Forward*/
   {
	   IOWR(MOT_1_BASE, 0, 0b1001);
	   IOWR(MOT_0_BASE, 0, 0b0110);
	   IOWR(LEDR_BASE, 0, 0x00);
	   IOWR(LEDG_BASE, 0, 0b11111111);

	   STATUS = 'F';
   }
   else if (edge_capture == 0b0100)/*Reverse*/
   {
	   IOWR(MOT_1_BASE, 0, 0b0110);
	   IOWR(MOT_0_BASE, 0, 0b1001);
	   IOWR(LEDR_BASE, 0, 0x00);
	   IOWR(LEDG_BASE, 0, 0b11111111);

	   STATUS = 'B';
   }
   else if (edge_capture == 0b1000)/*Direction*/
   {
	   if (sw == 0b00000001)
	   {
		   IOWR(MOT_1_BASE, 0, 0b1001);
		   IOWR(MOT_0_BASE, 0, 0b1001);
		   IOWR(LEDR_BASE, 0, 0x00);
		   IOWR(LEDG_BASE, 0, 0b11111111);

		   STATUS = 'R';
	   }else
	   {
		   IOWR(MOT_1_BASE, 0, 0b0110);
		   IOWR(MOT_0_BASE, 0, 0b0110);
		   IOWR(LEDR_BASE, 0, 0x00);
		   IOWR(LEDG_BASE, 0, 0b11111111);

		   STATUS = 'L';
	   }

   }


   taskRS232(STATUS);
   edge_capture = 0x00;
}




 void init_key() {
   void *edge_capture_ptr = (void *)&edge_capture;
   IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PUSH_BUTTONS_BASE, 0xF);
   IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PUSH_BUTTONS_BASE, 0x0);

 #ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
   alt_ic_isr_register(PUSH_BUTTONS_IRQ_INTERRUPT_CONTROLLER_ID,
		   PUSH_BUTTONS_IRQ,
                       handle_key_interrupts,
                       edge_capture_ptr,
                       0x0);
 #else

   alt_irq_register(PUSH_BUTTONS_IRQ,
                    edge_capture_ptr,
                    handle_key_interrupts);
 #endif
 }
