#include "include/readSendArray.h"
#include "include/ws2812b.h"


uint8_t rValue, gValue, bValue = 0;
static uint8_t array[512] = {0};


void readArray(){
    /*
    hier komt code om de array in te vullen
    binnenlezen via dmx
    */
    array[16] = 0;
    array[17] = 255;
    array[18] = 255;
}

void sendArray(uint8_t array[]){
    //hier komt code om de array te versturen
}

void arrayTask(void* channel){
    while (1)
    {
        int *channelCount = (int*) channel;

        readArray();
        sendArray(array);

        rValue = array[*channelCount];
        gValue = array[*channelCount+1];
        bValue = array[*channelCount+2];



        setColor(rValue, gValue, bValue, 0); //voorbeeld om de eerste led rood te maken

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
