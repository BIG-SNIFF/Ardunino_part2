/ {
    bus_outputs { 
        compatible = "gpio-leds";   //Tells zephyr that this section describes outputs controlled using GPIO pins

        bus_bit0: led_0 {  //Label used to identify the output in your C program  
            gpios = <&gpio4 3 GPIO_ACTIVE_HIGH>;    //Tells Zephyr which GPIO pin to use i.e. pin 3 on GPIO controller 4 
            label = "ARD_D0";   //Gives output a name 
        };

        bus_bit1: led_1 {    //Label used to identify the output in your C program
            gpios = <&gpio4 2 GPIO_ACTIVE_HIGH>;    //Tells Zephyr which GPIO pin to use i.e. pin 2 on GPIO controller 4
            label = "ARD_D1";    //Gives output a name
        };

        bus_bit2: led_2 {
            gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>;    //Tells Zephyr which GPIO pin to use i.e. pin 29 on GPIO controller 0
            label = "ARD_D2";    //Gives output a name
        }; 

        bus_bit3: led_3 {
            gpios = <&gpio1 23 GPIO_ACTIVE_HIGH>;    //Tells Zephyr which GPIO pin to use i.e. pin 23 on GPIO controller 1
            label = "ARD_D3";   //Gives output a name
        };
    };
};
