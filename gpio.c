#include <stdio.h>
#include "gpio.h"

static int pin_direction[GPIO_MAX_PINS] = {0};
static int pin_state[GPIO_MAX_PINS]     = {0};

void gpio_init(int pin, int direction) {
    if (pin < 0 || pin >= GPIO_MAX_PINS) return;
    pin_direction[pin] = direction;
    pin_state[pin] = GPIO_LOW;
    printf("[GPIO] Pin %d initialized as %s\n", pin, direction == GPIO_OUTPUT ? "OUTPUT" : "INPUT");
}

void gpio_write(int pin, int value) {
    if (pin < 0 || pin >= GPIO_MAX_PINS) return;
    if (pin_direction[pin] != GPIO_OUTPUT) {
        printf("[GPIO] ERROR: Pin %d is not configured as OUTPUT\n", pin);
        return;
    }
    pin_state[pin] = value;
    printf("[GPIO] Pin %d -> %s\n", pin, value == GPIO_HIGH ? "HIGH" : "LOW");
}

int gpio_read(int pin) {
    if (pin < 0 || pin >= GPIO_MAX_PINS) return -1;
    return pin_state[pin];
}

void gpio_toggle(int pin) {
    if (pin < 0 || pin >= GPIO_MAX_PINS) return;
    pin_state[pin] = !pin_state[pin];
    printf("[GPIO] Pin %d toggled -> %s\n", pin, pin_state[pin] == GPIO_HIGH ? "HIGH" : "LOW");
}

void gpio_status(void) {
    printf("\n--- GPIO Status ---\n");
    for (int i = 0; i < 4; i++) {
        printf("  Pin %d: %-6s | %s\n", i,
               pin_direction[i] == GPIO_OUTPUT ? "OUT" : "IN",
               pin_state[i] == GPIO_HIGH ? "HIGH" : "LOW");
    }
    printf("-------------------\n\n");
}
