#ifndef SETUP_H
#define SETUP_H

#include "stdafx.h"

/**
 * @brief Initialize ADC for temperature reading.
 * 
 * This function configures the ADC width and attenuation.
 * It also calibrates the ADC if eFuse Vref is available.
 */
void adc_init();

/**
 * @brief Initialize UART2 with specific baud rate and pins.
 * 
 * This function sets up UART2 with the given baud rate, data bits,
 * parity, stop bits, and flow control. It also configures the TX and RX pins.
 */
void uart2_init();

/**
 * @brief Initialize GPIO for LED blinking.
 * 
 * This function sets the GPIO direction for the LED to output.
 */
void led_init();

/**
 * @brief Get the ADC calibration characteristics.
 * 
 * @return A pointer to the esp_adc_cal_characteristics_t structure.
 */
const esp_adc_cal_characteristics_t* get_adc_chars();

#endif /* SETUP_H */
