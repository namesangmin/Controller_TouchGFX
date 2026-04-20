#ifndef __LED_H__
#define __LED_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define MAX_LED 3

int LED_TurnOn(int channel_index);
void LED_TurnOff();
#ifdef __cplusplus
}
#endif

#endif
