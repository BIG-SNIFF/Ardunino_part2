/* waveform generation - Part 2 */

/* main.c */

#include <zephyr/kernel.h>   
#include <zephyr/drivers/gpio.h>
#include <stdint.h>

#define BIT0_NODE DT_NODELABEL(bus_bit0)   //refering to the device tree node for ARD_D0
#define BIT1_NODE DT_NODELABEL(bus_bit1)
#define BIT2_NODE DT_NODELABEL(bus_bit2)
#define BIT3_NODE DT_NODELABEL(bus_bit3)

static const struct gpio_dt_spec bit0 =   //Variable is only accessible within c file, zephyr data structure that holds info about GPIO pin.
    GPIO_DT_SPEC_GET(BIT0_NODE, gpios);   //retrieves GPIO controller, pin number and configuration from app.overlay

static const struct gpio_dt_spec bit1 =
    GPIO_DT_SPEC_GET(BIT1_NODE, gpios);

static const struct gpio_dt_spec bit2 =
    GPIO_DT_SPEC_GET(BIT2_NODE, gpios);

static const struct gpio_dt_spec bit3 =
    GPIO_DT_SPEC_GET(BIT3_NODE, gpios);


/* Function to write the four output bits */
static void write_bus(uint8_t value)   //
{
    gpio_pin_set_dt(&bit0, (value >> 0) & 1);    //'&bit0' says what gpio we control,'value >> 0' shifts the binary value right by zero palces, '& 1' extracts bit 0 
    gpio_pin_set_dt(&bit1, (value >> 1) & 1);    //move bit 1 to the right most poisition
    gpio_pin_set_dt(&bit2, (value >> 2) & 1);
    gpio_pin_set_dt(&bit3, (value >> 3) & 1);
}


int main(void)
{
    int count;

    /* Array holding the waveform output data */
    uint8_t values[5] = {      //each value is an 8 bit unsigned integer, array called values, [5] array contains 5 elements
        0x0F, 0x0E, 0x0C, 0x08, 0x00   //stores all combinations of high and low 
    };

    /* Array holding the duration of each waveform phase */
    uint32_t duration[5] = {  //same again but 32-bit unsigned integer
        60, 20, 20, 20, 80  //tells the program how long to hold the corresponding waveform partern 
    };

    /* Configure all four GPIO pins as outputs */
    gpio_pin_configure_dt(&bit0, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&bit1, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&bit2, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&bit3, GPIO_OUTPUT_INACTIVE);

    /* Repeat the waveform continuously */
    while (1) {

        for (count = 0; count < 5; count++) {

            /* Write the waveform data to the output pins */
            write_bus(values[count]);

            /* Wait for the duration of the current phase */
            k_sleep(K_MSEC(duration[count]));
        }
    }

    return 0;
}
