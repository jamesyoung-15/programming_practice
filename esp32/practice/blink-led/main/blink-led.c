#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <driver/gpio.h>
#define BLUE_LED 16
#define RED_LED 5
#define GREEN_LED 17

void app_main(void)
{
	char *ourTaskName = pcTaskGetName(NULL);

	ESP_LOGI(ourTaskName, "Hello starting up \n");
	gpio_reset_pin(RED_LED);
	gpio_set_direction(RED_LED, GPIO_MODE_OUTPUT);
	gpio_reset_pin(GREEN_LED);
	gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);
	gpio_reset_pin(BLUE_LED);
	gpio_set_direction(BLUE_LED, GPIO_MODE_OUTPUT);
	while(1)
	{
		gpio_set_level(RED_LED, 1);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
		gpio_set_level(RED_LED,0);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
		gpio_set_level(GREEN_LED, 1);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
		gpio_set_level(GREEN_LED,0);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
		gpio_set_level(BLUE_LED, 1);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
		gpio_set_level(BLUE_LED,0);
		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
