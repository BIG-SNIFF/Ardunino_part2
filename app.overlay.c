
/* waveform generation - Part 2 */
/* app.overlay */

/ {
    bus_outputs {
        compatible = "gpio-leds";

        bus_bit0: led_0 {
            gpios = <&gpio4 3 GPIO_ACTIVE_HIGH>;
            label = "ARD_D0";
        };

        bus_bit1: led_1 {
            gpios = <&gpio4 2 GPIO_ACTIVE_HIGH>;
            label = "ARD_D1";
        };

        bus_bit2: led_2 {
            gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>;
            label = "ARD_D2";
        };

        bus_bit3: led_3 {
            gpios = <&gpio1 23 GPIO_ACTIVE_HIGH>;
            label = "ARD_D3";
        };
    };
};
