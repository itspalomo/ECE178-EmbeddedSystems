//hw3 instantiation

module hw3(SW, KEY, CLOCK_50, HEX0, HEX1, HEX2, HEX3,
				HEX4, HEX5, HEX6, HEX7, LEDG, LEDR, DRAM_CLK, DRAM_CKE,
				DRAM_ADDR, DRAM_BA, DRAM_CS_N, DRAM_CAS_N, DRAM_RAS_N,
				DRAM_WE_N, DRAM_DQ, DRAM_DQM, GPIO, UART_RXD, UART_TXD, HCdata);
				
		input  wire        CLOCK_50;         //      clk.clk
		output wire [6:0]  HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7;
		output wire [7:0]  LEDG;     //     ledg.export
		output wire [17:0] LEDR;     //     ledr.export
		input  wire [3:0]  KEY;   //    reset.reset_n
		input  wire [17:0] SW;  // switches.export
		output [12:0] DRAM_ADDR;
		output [1:0] DRAM_BA;
		output DRAM_CAS_N, DRAM_RAS_N, DRAM_CLK;
		output DRAM_CKE, DRAM_CS_N, DRAM_WE_N;
		output [3:0] DRAM_DQM;
		inout [31:0] DRAM_DQ;
		inout [39:0] GPIO;
		input UART_RXD;
		output UART_TXD;
		output [15:0] HCdata;


		
		niosdramproc u0 (
		.clk_clk         (CLOCK_50),         //      clk.clk
		.hex0_export     (HEX0),     //     hex0.export
		.hex1_export     (HEX1),     //     hex1.export
		.hex2_export     (HEX2),     //     hex2.export
		.hex3_export     (HEX3),     //     hex3.export
		.hex4_export     (HEX4),     //     hex4.export
		.hex5_export     (HEX5),     //     hex5.export
		.hex6_export     (HEX6),     //     hex6.export
		.hex7_export     (HEX7),     //     hex7.export
		.ledg_export     (LEDG),     //     ledg.export
		.ledr_export     (LEDR),     //     ledr.export
		.reset_reset   (SW[17]),   //    reset.reset_n
		.switches_export (SW[15:0]),  // switches.export
		.pushbutton_export (KEY), // pushbuttons exports
		.sdram_wire_addr   (DRAM_ADDR),   // sdram_wire.addr
		.sdram_wire_ba     (DRAM_BA),     //           .ba
		.sdram_wire_cas_n  (DRAM_CAS_N),  //           .cas_n
		.sdram_wire_cke    (DRAM_CKE),    //           .cke
		.sdram_wire_cs_n   (DRAM_CS_N),   //           .cs_n
		.sdram_wire_dq     (DRAM_DQ),     //           .dq
		.sdram_wire_dqm    (DRAM_DQM),    //           .dqm
		.sdram_wire_ras_n  (DRAM_RAS_N),  //           .ras_n
		.sdram_wire_we_n   (DRAM_WE_N),   //           .we_n
		.sdram_clk_clk (DRAM_CLK),
		.uart_RXD          (UART_RXD),          //       uart.RXD
		.uart_TXD          (UART_TXD),          //           .TXD
		.mot_1_export      (GPIO[3:0]),      //      mot_1.export
		.mot_0_export      (GPIO[7:4]),       //      mot_0.export
		.hctrig_export     (GPIO[13]),     //     hctrig.export
		.hcecho_export     (GPIO[12]),     //     hcecho.export
		.buzzer_export     (GPIO[14])      //     buzzer.export
	);
	

endmodule 