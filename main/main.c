/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// const int BTN_PIN= 28;

// const int LED_PIN_R = 5;
// const int LED_PIN_P = 8;
// const int LED_PIN_B = 11;
// const int LED_PIN_Y = 15;

   const int LED_PIN = 13; 

   const int BTN_PIN = 10;

   const int MOT_PIN_1 = 28;
   const int MOT_PIN_2 = 27;
   const int MOT_PIN_3 = 26;
   const int MOT_PIN_4 = 22;
   const int STEPS= 500;

int main() {

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(MOT_PIN_1);
    gpio_set_dir(MOT_PIN_1, GPIO_OUT);

    gpio_init(MOT_PIN_2);
    gpio_set_dir(MOT_PIN_2, GPIO_OUT);

    gpio_init(MOT_PIN_3);
    gpio_set_dir(MOT_PIN_3, GPIO_OUT);

    gpio_init(MOT_PIN_4);
    gpio_set_dir(MOT_PIN_4, GPIO_OUT);

    stdio_init_all();
    while (true) {
        if(!gpio_get(BTN_PIN)){
            gpio_put(LED_PIN, 1);
            
            for (int i=0; i <= STEPS; i++){
                gpio_put(MOT_PIN_4, 1);
                sleep_ms(10);
                gpio_put(MOT_PIN_4, 0);
                gpio_put(MOT_PIN_3, 1);
                sleep_ms(10);
                gpio_put(MOT_PIN_3, 0);
                gpio_put(MOT_PIN_2, 1);
                sleep_ms(10);
                gpio_put(MOT_PIN_2, 0);
                gpio_put(MOT_PIN_1, 1);
                sleep_ms(10);
                gpio_put(MOT_PIN_1, 0);
            }
            
            gpio_put(LED_PIN,0);
        }
        
    }
    }

