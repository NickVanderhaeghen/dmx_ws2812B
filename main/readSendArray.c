#include "include/readSendArray.h"
#include "include/ws2812b.h"


QueueHandle_t arrayQueue;

uint8_t rValue, gValue, bValue = 0;
uint8_t array[512] = {0};

void config_uart(){
    uart_config_t uart_config = {
        .baud_rate = CONFIG_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB
    };
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_1, 1024*2, 0, 1024, &arrayQueue, 0)); //RX buffer
    ESP_ERROR_CHECK(uart_param_config(UART_NUM_1, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_1, 18, 17, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}


void readArray(){
    if(uart_read_bytes(UART_NUM_1, &array, 512, 20 / portTICK_PERIOD_MS) > 0){
        xQueueSend(arrayQueue, &array, (TickType_t) 0); //steek het in de queue
        printf("Data received\n");
    }
    // array[16] = 0;
    // array[17] = 255;
    // array[18] = 255;
}

void sendArray(){  //haal het uit de queue
    if(xQueueReceive(arrayQueue, &array, (TickType_t) 0) == pdTRUE){
        uart_write_bytes(UART_NUM_1, &array, 512); //haal het uit de queue en verzend het
        printf("Data sent\n");
    }
}

void arrayTask(void* channel){
    arrayQueue = xQueueCreate(1, sizeof(array));


    while (1)
    {
        int *channelCount = (int*) channel;

        readArray();
        sendArray();

        if(*channelCount > 252){
            rValue = 0;
            gValue = 0;
            bValue = 0;
            
        }
        else{
            rValue = array[*channelCount];
            gValue = array[*channelCount+1];
            bValue = array[*channelCount+2];
        }


        for (int i = 0; i < CONFIG_WS2812B_LED_COUNT; i++)
        {
            setColor(rValue, gValue, bValue, i);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}
