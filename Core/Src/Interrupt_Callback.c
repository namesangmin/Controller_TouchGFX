#include "Interrupt_Callback.h"
#include "ModeFunction.h"

extern volatile uint8_t modeChoice;
extern volatile uint8_t pressButton;
volatile uint32_t lastInterruptTime = 0;
volatile uint32_t lastInterruptTime_Button = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == MODE_BUTTON_Pin){
		modeChange_Button();
	}
	else if(GPIO_Pin == JOY_BUTTON_Pin){
		joyStick_Button();
	}
}

void modeChange_Button(){
	uint32_t currentTime = HAL_GetTick();

	if(currentTime - lastInterruptTime > DEBOUNCE_TIME)
	{
		lastInterruptTime = currentTime;
		modeChoice = ! modeChoice;

		// 1이면 조이스틱
		if(modeChoice)
		{
			currentFunction = JoxStickMode;
			HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
		}
		else
		{
			currentFunction = ADCMode;
			HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET);
		}
	}
}

void joyStick_Button()
{
	uint32_t currentTime = HAL_GetTick();
	if(modeChoice){
		if(currentTime - lastInterruptTime_Button > DEBOUNCE_TIME)
		{
			lastInterruptTime_Button = currentTime;
			pressButton = !pressButton;
		}
	}
}
