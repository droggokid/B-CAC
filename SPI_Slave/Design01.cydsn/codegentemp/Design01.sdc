# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\deniz\OneDrive\Dokumenter\GitHub\B-CAC\SPI_Slave\Design01.cydsn\Design01.cyprj
# Date: Tue, 05 Dec 2023 11:08:15 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {SPIS_2_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 25} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_SAR_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 27} -nominal_period 541.66666666666663 [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_1}]]


# Component constraints for C:\Users\deniz\OneDrive\Dokumenter\GitHub\B-CAC\SPI_Slave\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\deniz\OneDrive\Dokumenter\GitHub\B-CAC\SPI_Slave\Design01.cydsn\Design01.cyprj
# Date: Tue, 05 Dec 2023 11:08:09 GMT
