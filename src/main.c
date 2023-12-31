#include "Setup.h"
#include "Utils.h"

void uart_send_task(void* arg) {
    while (1) {
        // Read the temperature
        float temperature = read_temperature();
        // Create a packet with the temperature data
        uint8_t packet[9];
        create_temperature_packet(temperature, packet);
        // Send the packet over UART
        // Since uart2_send is designed for strings, we need to send the packet byte-by-byte
        for (int i = 0; i < sizeof(packet); i++) {
            uart_write_bytes(UART_NUM_2, (const char *)&packet[i], 1);
        }
        // Delay for a period (e.g., 1 second)
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void uart_receive_task(void* arg) {
    uint8_t *data = (uint8_t *) malloc(UART2_RX_BUF_SIZE);
    while (1) {
        int len = uart_read_bytes(UART_NUM_2, data, (UART2_RX_BUF_SIZE - 1), 20 / portTICK_PERIOD_MS);
        if (len > 0) {
            gpio_set_level(GPIO_NUM_23, 1);
            vTaskDelay(200 / portTICK_PERIOD_MS);
            gpio_set_level(GPIO_NUM_23, 0);
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void app_main() {
    led_init();
    uart2_init();
    adc_init();
    xTaskCreate(uart_send_task, "uart_send_task", 2048, NULL, 5, NULL);
    xTaskCreate(uart_receive_task, "uart_receive_task", 2048, NULL, 5, NULL);
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
    }
}
