#include "include/readSendArray.h"
#include "freertos/FreeRTOS.h"

#pragma once


int* readArray(){

    /*
    hier komt code om de array in te vullen
    binnenlezen via dmx
    */
    static int array[] = {255, 0, 0}; //voorbeeld array

    return array;
}

void sendArray(int array[]){
    //hier komt code om de array te versturen
}

void arrayTask(){
    while (1)
    {
        readArray();
        sendArray(readArray());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
