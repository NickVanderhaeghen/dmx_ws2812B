idf_component_register(SRCS "channel.c" "readSendArray.c" "main.c" "ws2812b.c"
                    INCLUDE_DIRS "."
                    REQUIRES esp_driver_gpio)
                    