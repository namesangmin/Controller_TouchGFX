#ifndef __INTERRUPT_CALLBACK_H__
#define __INTERRUPT_CALLBACK_H__

// C++ 환경에서 C 코드를 링크할 때를 대비한 가드
#ifdef __cplusplus
extern "C" {
#endif

#define DEBOUNCE_TIME 100
#include "main.h"

// 함수 원형 선언
void joyStick_Button();
void modeChange_Button();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif
