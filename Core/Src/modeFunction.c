#include "modeFunction.h"
#include "led.h"
#include "segment.h"
#include "messageQueue.h"
#include <stdlib.h>

void (*currentFunction)() = ADCMode;
extern uint16_t hadc1_arr[];
extern uint16_t hadc1_arr_prev[];
extern volatile uint8_t modeChoice;
extern volatile uint8_t pressButton;
volatile uint8_t prev_pressButton;

void JoxStickMode(){
	LED_TurnOff();
	uint8_t isChanged = 0;

	for(int idx = MAX_ADC_X; idx < MAX_ADC; idx++){
		uint32_t diff = abs((int)hadc1_arr_prev[idx] - hadc1_arr[idx]);

		if(diff > NOISE_FILTTER){
			SEG_UpdateProcess((int)hadc1_arr[idx]);
			hadc1_arr_prev[idx] = hadc1_arr[idx];
			isChanged = 1;
		}
	}

	if (pressButton != prev_pressButton) {
		isChanged = 1;
		prev_pressButton = pressButton;
	}

	if (isChanged == 1) {
		inputQueue_JoxStick_Data(modeChoice, pressButton, hadc1_arr);
	}
}

void ADCMode(){
    uint8_t isChanged = 0;

    for(int idx = 0; idx < MAX_ADC_X; idx++){
        uint32_t diff = abs((int)hadc1_arr_prev[idx] - hadc1_arr[idx]);

        if(diff > NOISE_FILTTER){
            LED_TurnOn(idx);
            SEG_UpdateProcess((int)hadc1_arr[idx]);

            hadc1_arr_prev[idx] = hadc1_arr[idx];
            isChanged = 1;
        }
    }

    if(isChanged == 1){
        inputQueue_ADC_Data(modeChoice, hadc1_arr);
    }
}
