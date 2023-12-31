#include "Utils.h"


void uart2_send(const char* format, ...) {
    char buffer[UART2_SEND_MAX_LEN];
    // Start variadic arguments processing
    va_list args;
    va_start(args, format);
    // Format the string
    vsnprintf(buffer, UART2_SEND_MAX_LEN, format, args);
    // Send the formatted string over UART
    uart_write_bytes(UART_NUM_2, buffer, strlen(buffer));
    // Clean up variadic arguments
    va_end(args);
}

float read_temperature() {
    // Get ADC calibration characteristics
    const esp_adc_cal_characteristics_t* adc_chars = get_adc_chars();
    // Read ADC
    int adc_reading = adc1_get_raw(ADC1_CHANNEL_7);
    // Convert ADC reading to voltage in millivolts
    uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);
    // Convert voltage to temperature (assuming 10mV per degree Celsius)
    float temperature = voltage / 10.0;
    return temperature;
}

void create_temperature_packet(float temperature, uint8_t *packet) {
    uint8_t checksum = 0;
    int index = 0;
    packet[index++] = START_OF_FRAME;
    packet[index++] = TEMP_DATA_TYPE;
    packet[index++] = TEMP_DATA_SIZE;
    memcpy(&packet[index], &temperature, TEMP_DATA_SIZE);
    index += TEMP_DATA_SIZE;
    for (int i = 1; i < index; i++) {
        checksum += packet[i];
    }
    packet[index++] = checksum;
    packet[index++] = END_OF_FRAME;
}

bool verify_packet(const uint8_t *packet, int size) {
    if (packet[0] != START_OF_FRAME || packet[size - 1] != END_OF_FRAME) {
        return false;
    }
    if (packet[1] != TEMP_DATA_TYPE || packet[2] != TEMP_DATA_SIZE) {
        return false;
    }
    uint8_t checksum = 0;
    for (int i = 1; i < size - 2; i++) {
        checksum += packet[i];
    }
    return checksum == packet[size - 2];
}

void print_packet(const uint8_t *packet, int size) {
    for (int i = 0; i < size; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

bool extract_temperature_from_packet(const uint8_t *packet, int size, float *temperature) {
    if (!verify_packet(packet, size)) {
        return false;
    }
    memcpy(temperature, &packet[3], TEMP_DATA_SIZE);
    return true;
}