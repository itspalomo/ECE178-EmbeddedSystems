	component niosdramproc is
		port (
			clk_clk           : in    std_logic                     := 'X';             -- clk
			hex0_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex1_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex2_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex3_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex4_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex5_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex6_export       : out   std_logic_vector(6 downto 0);                     -- export
			hex7_export       : out   std_logic_vector(6 downto 0);                     -- export
			ledg_export       : out   std_logic_vector(8 downto 0);                     -- export
			ledr_export       : out   std_logic_vector(17 downto 0);                    -- export
			mot_0_export      : out   std_logic_vector(3 downto 0);                     -- export
			mot_1_export      : out   std_logic_vector(3 downto 0);                     -- export
			pushbutton_export : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			reset_reset       : in    std_logic                     := 'X';             -- reset
			sdram_clk_clk     : out   std_logic;                                        -- clk
			sdram_wire_addr   : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba     : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n  : out   std_logic;                                        -- cas_n
			sdram_wire_cke    : out   std_logic;                                        -- cke
			sdram_wire_cs_n   : out   std_logic;                                        -- cs_n
			sdram_wire_dq     : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm    : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_wire_ras_n  : out   std_logic;                                        -- ras_n
			sdram_wire_we_n   : out   std_logic;                                        -- we_n
			switches_export   : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			uart_RXD          : in    std_logic                     := 'X';             -- RXD
			uart_TXD          : out   std_logic;                                        -- TXD
			hctrig_export     : out   std_logic;                                        -- export
			hcecho_export     : in    std_logic                     := 'X';             -- export
			buzzer_export     : out   std_logic                                         -- export
		);
	end component niosdramproc;

	u0 : component niosdramproc
		port map (
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			hex0_export       => CONNECTED_TO_hex0_export,       --       hex0.export
			hex1_export       => CONNECTED_TO_hex1_export,       --       hex1.export
			hex2_export       => CONNECTED_TO_hex2_export,       --       hex2.export
			hex3_export       => CONNECTED_TO_hex3_export,       --       hex3.export
			hex4_export       => CONNECTED_TO_hex4_export,       --       hex4.export
			hex5_export       => CONNECTED_TO_hex5_export,       --       hex5.export
			hex6_export       => CONNECTED_TO_hex6_export,       --       hex6.export
			hex7_export       => CONNECTED_TO_hex7_export,       --       hex7.export
			ledg_export       => CONNECTED_TO_ledg_export,       --       ledg.export
			ledr_export       => CONNECTED_TO_ledr_export,       --       ledr.export
			mot_0_export      => CONNECTED_TO_mot_0_export,      --      mot_0.export
			mot_1_export      => CONNECTED_TO_mot_1_export,      --      mot_1.export
			pushbutton_export => CONNECTED_TO_pushbutton_export, -- pushbutton.export
			reset_reset       => CONNECTED_TO_reset_reset,       --      reset.reset
			sdram_clk_clk     => CONNECTED_TO_sdram_clk_clk,     --  sdram_clk.clk
			sdram_wire_addr   => CONNECTED_TO_sdram_wire_addr,   -- sdram_wire.addr
			sdram_wire_ba     => CONNECTED_TO_sdram_wire_ba,     --           .ba
			sdram_wire_cas_n  => CONNECTED_TO_sdram_wire_cas_n,  --           .cas_n
			sdram_wire_cke    => CONNECTED_TO_sdram_wire_cke,    --           .cke
			sdram_wire_cs_n   => CONNECTED_TO_sdram_wire_cs_n,   --           .cs_n
			sdram_wire_dq     => CONNECTED_TO_sdram_wire_dq,     --           .dq
			sdram_wire_dqm    => CONNECTED_TO_sdram_wire_dqm,    --           .dqm
			sdram_wire_ras_n  => CONNECTED_TO_sdram_wire_ras_n,  --           .ras_n
			sdram_wire_we_n   => CONNECTED_TO_sdram_wire_we_n,   --           .we_n
			switches_export   => CONNECTED_TO_switches_export,   --   switches.export
			uart_RXD          => CONNECTED_TO_uart_RXD,          --       uart.RXD
			uart_TXD          => CONNECTED_TO_uart_TXD,          --           .TXD
			hctrig_export     => CONNECTED_TO_hctrig_export,     --     hctrig.export
			hcecho_export     => CONNECTED_TO_hcecho_export,     --     hcecho.export
			buzzer_export     => CONNECTED_TO_buzzer_export      --     buzzer.export
		);

