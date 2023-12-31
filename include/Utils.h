#ifndef UTILS_H
#define UTILS_H

#include "stdafx.h"

/**
 * @brief Send formatted data over UART2.
 *
 * This function works similarly to printf, but sends the formatted string over UART2.
 *
 * @param format Format string (in).
 * @param ... Variable number of arguments for formatting (in).
 */
void uart2_send(const char* format, ...);

/**
 * @brief Read and calculate the ambient temperature from an ADC channel.
 *
 * This function reads the ADC value from a specific channel and converts it to temperature.
 * The calculation assumes 10mV per degree Celsius.
 *
 * @return Calculated temperature in degree Celsius (out).
 */
float read_temperature();

/**
 * @brief Create a packet containing temperature data.
 *
 * This function creates a packet with temperature data, including start/end markers, type, size, and checksum.
 *
 * @param temperature Temperature value to be included in the packet (in).
 * @param packet Buffer where the packet will be stored (out).
 */
void create_temperature_packet(float temperature, uint8_t *packet);

/**
 * @brief Verify the integrity of a received packet.
 *
 * This function checks a packet for start/end markers, correct data type/size, and checksum validation.
 *
 * @param packet Packet to be verified (in).
 * @param size Size of the packet (in).
 * @return true if the packet is valid, false otherwise (out).
 */
bool verify_packet(const uint8_t *packet, int size);

/**
 * @brief Print the contents of a packet in hexadecimal format.
 *
 * @param packet Packet to be printed (in).
 * @param size Size of the packet (in).
 */
void print_packet(const uint8_t *packet, int size);

/**
 * @brief Extract the temperature data from a valid packet.
 *
 * This function extracts and returns the temperature data from a given packet, assuming the packet is valid.
 *
 * @param packet Packet from which the temperature is to be extracted (in).
 * @param size Size of the packet (in).
 * @param temperature Pointer to where the extracted temperature will be stored (out).
 * @return true if the temperature was successfully extracted, false otherwise (out).
 */
bool extract_temperature_from_packet(const uint8_t *packet, int size, float *temperature);




#endif /* UTILS_H */
