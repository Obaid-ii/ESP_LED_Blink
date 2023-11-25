#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#define LED_PIN 2

void led_blink(void *pvParameter)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(LED_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main() 
{
    xTaskCreate(&led_blink, "LED-BLINK", 2048, NULL, 5, NULL);

    // Keep the main task alive
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
