#pragma once

#include "include/ws2812b.h"
#include "freertos/FreeRTOS.h"



void readArray();

void sendArray(uint8_t array[]);

void arrayTask(void* channel);