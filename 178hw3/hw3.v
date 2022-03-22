//hw3 instantiation

module hw3(SW, KEY, CLOCK_50, HEX0, HEX1, HEX2, HEX3,
				HEX4, HEX5, HEX6, HEX7, LEDG, LEDR, SRAM_DQ,
				SRAM_ADDR, SRAM_LB_N, SRAM_UB_N, SRAM_CE_N,
				SRAM_OE_N, SRAM_WE_N);
				
		input  wire        CLOCK_50;         //      clk.clk
		output wire [6:0]  HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7;
		output wire [7:0]  LEDG;     //     ledg.export
		output wire [17:0] LEDR;     //     ledr.export
		input  wire [3:0]  KEY;   //    reset.reset_n
		inout  wire [15:0] SRAM_DQ;         //     sram.DQ
		output wire [19:0] SRAM_ADDR;       //         .ADDR
		output wire        SRAM_LB_N;       //         .LB_N
		output wire        SRAM_UB_N;       //         .UB_N
		output wire        SRAM_CE_N;       //         .CE_N
		output wire        SRAM_OE_N;       //         .OE_N
		output wire        SRAM_WE_N;       //         .WE_N
		input  wire [17:0] SW;  // switches.export
		
		hw3proc u0 (
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
		.reset_reset_n   (KEY[0]),   //    reset.reset_n
		.sram_DQ         (SRAM_DQ),         //     sram.DQ
		.sram_ADDR       (SRAM_ADDR),       //         .ADDR
		.sram_LB_N       (SRAM_LB_N),       //         .LB_N
		.sram_UB_N       (SRAM_UB_N),       //         .UB_N
		.sram_CE_N       (SRAM_CE_N),       //         .CE_N
		.sram_OE_N       (SRAM_OE_N),       //         .OE_N
		.sram_WE_N       (SRAM_WE_N),       //         .WE_N
		.switches_export (SW),  // switches.export
		.pushbuttons_export(KEY) // pushbuttons
	);

endmodule 