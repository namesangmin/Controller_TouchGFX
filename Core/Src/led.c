#include "led.h"

const uint16_t LED_Pin_arr[3] = {LED_1_Pin, LED_2_Pin, LED_3_Pin};

void LED_TurnOff(){
	// 모든 LED 끄기
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_Pin_arr[0] | LED_Pin_arr[1] | LED_Pin_arr[2], GPIO_PIN_RESET);
}

int LED_TurnOn(int channel_index){
    // 모든 LED 끄기
    for(int idx= 0; idx < MAX_LED; idx++){
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_Pin_arr[idx], GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_Pin_arr[channel_index], GPIO_PIN_SET);
    return 1;
}
