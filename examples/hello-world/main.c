/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include "periph/gpio.h"
#include "xtimer.h"
#include "board.h"
#include "thread.h"

static char stack[THREAD_STACKSIZE_MAIN];

gpio_t pin;
gpio_t pin_dir;


static void *thread_handler(void *arg){
    (void)arg;
    pin = GPIO_PIN(1,7);
    pin_dir = GPIO_PIN(1,6);
    gpio_init(pin, GPIO_OUT);
    gpio_init(pin_dir, GPIO_OUT);
    gpio_clear(pin_dir);
    while(1){
	gpio_toggle(pin);
        //xtimer_usleep(20);
	xtimer_ticks32_t last_wakeup = xtimer_now();
	xtimer_periodic_wakeup(&last_wakeup, 30);
    }
    return NULL;
}

int main(void)
{
    puts("Hello World!");

    thread_create(stack, sizeof(stack), THREAD_PRIORITY_MAIN - 1,
               0, thread_handler, NULL, "new thread");
    while(1);
    return 0;
}
