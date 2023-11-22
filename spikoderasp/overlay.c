/ dts - v1 / ;
/ plugin / ;

/ {
    compatible = "brcm,bcm2835", "brcm,bcm2708";
    /* disable spi-dev for spi0.0 */
    fragment@0 {
        target = <&spi0>; // SPI Bus 0
        __overlay__{
            status = "okay";
            spidev@0{     // SPI Chip Select 0
                status = "disabled";
            };
        };
    };

    fragment@1 {
        target = <&spi0>; // SPI Bus 0
        __overlay__{
            /* needed to avoid dtc warning */
            #address - cells = <1>;
            #size - cells = <0>;
            spi_drv:spi_drv@0 {
                compatible = "ase, spi_drv";
                reg = <0>; // SPI Chip Select 0
                /* spi-cpha; */ /* Comment in to set CPHA */
                /* spi-cpol; */ /* Comment in to set CPOL */
                spi - max - frequency = <10000>;
            };
        };
    };
};
