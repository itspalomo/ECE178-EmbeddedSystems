	component hw3proc is
		port (
			clk_clk         : in    std_logic                     := 'X';             -- clk
			hex0_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex1_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex2_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex3_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex4_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex5_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex6_export     : out   std_logic_vector(6 downto 0);                     -- export
			hex7_export     : out   std_logic_vector(6 downto 0);                     -- export
			ledg_export     : out   std_logic_vector(7 downto 0);                     -- export
			ledr_export     : out   std_logic_vector(17 downto 0);                    -- export
			reset_reset_n   : in    std_logic                     := 'X';             -- reset_n
			sram_DQ         : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DQ
			sram_ADDR       : out   std_logic_vector(19 downto 0);                    -- ADDR
			sram_LB_N       : out   std_logic;                                        -- LB_N
			sram_UB_N       : out   std_logic;                                        -- UB_N
			sram_CE_N       : out   std_logic;                                        -- CE_N
			sram_OE_N       : out   std_logic;                                        -- OE_N
			sram_WE_N       : out   std_logic;                                        -- WE_N
			switches_export : in    std_logic_vector(17 downto 0) := (others => 'X')  -- export
		);
	end component hw3proc;

	u0 : component hw3proc
		port map (
			clk_clk         => CONNECTED_TO_clk_clk,         --      clk.clk
			hex0_export     => CONNECTED_TO_hex0_export,     --     hex0.export
			hex1_export     => CONNECTED_TO_hex1_export,     --     hex1.export
			hex2_export     => CONNECTED_TO_hex2_export,     --     hex2.export
			hex3_export     => CONNECTED_TO_hex3_export,     --     hex3.export
			hex4_export     => CONNECTED_TO_hex4_export,     --     hex4.export
			hex5_export     => CONNECTED_TO_hex5_export,     --     hex5.export
			hex6_export     => CONNECTED_TO_hex6_export,     --     hex6.export
			hex7_export     => CONNECTED_TO_hex7_export,     --     hex7.export
			ledg_export     => CONNECTED_TO_ledg_export,     --     ledg.export
			ledr_export     => CONNECTED_TO_ledr_export,     --     ledr.export
			reset_reset_n   => CONNECTED_TO_reset_reset_n,   --    reset.reset_n
			sram_DQ         => CONNECTED_TO_sram_DQ,         --     sram.DQ
			sram_ADDR       => CONNECTED_TO_sram_ADDR,       --         .ADDR
			sram_LB_N       => CONNECTED_TO_sram_LB_N,       --         .LB_N
			sram_UB_N       => CONNECTED_TO_sram_UB_N,       --         .UB_N
			sram_CE_N       => CONNECTED_TO_sram_CE_N,       --         .CE_N
			sram_OE_N       => CONNECTED_TO_sram_OE_N,       --         .OE_N
			sram_WE_N       => CONNECTED_TO_sram_WE_N,       --         .WE_N
			switches_export => CONNECTED_TO_switches_export  -- switches.export
		);

