#ifndef STDAFX_H
#define STDAFX_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "Setup.h"

#define TXD_PIN (GPIO_NUM_17)
#define RXD_PIN (GPIO_NUM_16)
#define UART2_BAUD_RATE 115200
// Maximum length for the formatted string
#define UART2_SEND_MAX_LEN 512

#define UART2_RX_BUF_SIZE 1024
#define START_OF_FRAME 0xAA
#define END_OF_FRAME   0x55
#define TEMP_DATA_TYPE 0x01
#define TEMP_DATA_SIZE 4




#endif /* STDAFX_H */
