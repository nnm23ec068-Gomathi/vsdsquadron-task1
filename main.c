#include <stdio.h>
#include "gpio.h"

int main(void) {
    printf("=== VSDSquadron Mini - GPIO Firmware Library Demo ===\n\n");

    printf(">> Initializing GPIO pins...\n");
    gpio_init(0, GPIO_OUTPUT);
    gpio_init(1, GPIO_OUTPUT);
    gpio_init(2, GPIO_INPUT);
    gpio_init(3, GPIO_OUTPUT);

    printf("\n>> Simulating LED blink (3 times)...\n");
    for (int i = 0; i < 3; i++) {
        gpio_write(0, GPIO_HIGH);
        gpio_write(0, GPIO_LOW);
    }

    printf("\n>> Toggle test on Pin 3...\n");
    gpio_toggle(3);
    gpio_toggle(3);
    gpio_toggle(3);

    printf("\n>> Reading Pin 2 (simulated button): %s\n",
           gpio_read(2) == GPIO_HIGH ? "PRESSED" : "RELEASED");

    printf("\n>> Testing error handling (write to INPUT pin)...\n");
    gpio_write(2, GPIO_HIGH);

    gpio_status();
    printf("=== Demo Complete ===\n");
    return 0;
}
