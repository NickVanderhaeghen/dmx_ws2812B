#pragma once

#include "include/ws2812b.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "driver/uart.h"
#include "esp_log.h"

void config_uart();

void readArray();

void sendArray();

void arrayTask(void* channel);