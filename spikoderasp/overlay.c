// Definitions for plat_drv module
// Adapted from w1-gpio-pullup-overlay.dts
/dts-v1/;
/plugin/;

/ {
  compatible = "brcm,bcm2835", "brcm,bcm2708";

  fragment@0 {
    /* Add device to base */
    target-path = "/";
    __overlay__ {
      /* instance:type */
      plat_drv: plat_drv@0 {
        /* Label to match in driver */
        compatible = "ase, plat_drv";
        status = "okay";

        /* Configure gpio module */
        /* <ressource pinno dir pinno dir pinno dir ....> */
        gpios = <&gpio 12 0>, <&gpio 21 1>;
      };
    };
  };
};