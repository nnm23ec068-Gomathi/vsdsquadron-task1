#ifndef GPIO_H
#define GPIO_H

#define GPIO_OUTPUT  0
#define GPIO_INPUT   1
#define GPIO_LOW     0
#define GPIO_HIGH    1
#define GPIO_MAX_PINS 16

void gpio_init(int pin, int direction);
void gpio_write(int pin, int value);
int  gpio_read(int pin);
void gpio_toggle(int pin);
void gpio_status(void);

#endif
