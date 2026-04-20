#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"

typedef struct Message{
	uint16_t adcConv[MAX_ADC_X];
	uint8_t mode;
}messageBuffer;

#define QUEUE_LENGTH 30
#define QUEUE_ITEM_SIZE sizeof(messageBuffer)

void MX_QUEUE_INIT();
void inputQueue_JoxStick_Data(uint8_t mode, uint8_t button, uint16_t arr[]);
void inputQueue_ADC_Data(uint8_t mode, uint16_t arr[]);

extern QueueHandle_t qid;

#ifdef __cplusplus
}
#endif

#endif
