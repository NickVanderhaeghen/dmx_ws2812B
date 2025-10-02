#include "include/channel.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#pragma once


/*
We hebben 8 dipswitches om 512 kanalen te representeren
We hebben hier 3 opeenvolgende kanalen nodig voor R G B geteld vanaf het ingestelde kanaal
We moeten dus 8 pinnen van de esp32 verbinden met de dipswitches en uitlezen via de pinnen
*/

void readChannel(void* channel){

    int *channelCount = (int*) channel;
    while (1)
    {   
        /*channelCount = 0;
        if(gpio_get_level(CONFIG_GPIO_DIP_0)){
            channelCount += 1;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_1)){
            channelCount += 2;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_2)){
            channelCount += 4;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_3)){
            channelCount += 8;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_4)){
            channelCount += 16;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_5)){
            channelCount += 32;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_6)){
            channelCount += 64;
        }
        if(gpio_get_level(CONFIG_GPIO_DIP_7)){
            channelCount += 128;
        }
        
        printf("Channel: %d\n", channelCount);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        */
        printf("Channel: %d\n", *channelCount);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}