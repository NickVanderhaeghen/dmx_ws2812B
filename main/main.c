#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#include "include/channel.h"
#include "include/readSendArray.h"
#include "include/ws2812b.h"


TaskHandle_t xt_array;
TaskHandle_t xt_readChannel;

uint8_t channel = 0;

void gpioSettings(){
    gpio_config_t gpio_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ULL<<CONFIG_GPIO_DIP_0) | (1ULL<<CONFIG_GPIO_DIP_1) | (1ULL<<CONFIG_GPIO_DIP_2) | (1ULL<<CONFIG_GPIO_DIP_3) | 
                        (1ULL<<CONFIG_GPIO_DIP_4) | (1ULL<<CONFIG_GPIO_DIP_5) | (1ULL<<CONFIG_GPIO_DIP_6) | (1ULL<<CONFIG_GPIO_DIP_7),
        .pull_down_en = true,
        .pull_up_en = false,
    };
    gpio_config(&gpio_conf);
}


void app_main(void)
{
    int array[512];
    int dataAmount = 3;



    gpioSettings();
    config_led();
    config_uart();


    xTaskCreate(readChannel, "readChannel", 2048, &channel, 5, &xt_readChannel);
    xTaskCreate(arrayTask, "arrayTask", 2048, &channel, 5, &xt_array);
}