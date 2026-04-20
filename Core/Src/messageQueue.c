#include "messageQueue.h"

QueueHandle_t qid;

void MX_QUEUE_INIT(){
	qid = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE) ;
	if (qid == NULL) printf("xQueueCreate error found\n");
}

void inputQueue_JoxStick_Data(uint8_t mode, uint8_t button, uint16_t arr[]){
	if(qid == NULL) return;
	messageBuffer msg = {0};
	BaseType_t p;

	msg.mode = mode;
	msg.adcConv[0] = button;
	msg.adcConv[1] = arr[3];
	msg.adcConv[2] = arr[4];

	p=xQueueSendToBack(qid,&msg,0 );
	if (p != pdPASS) printf("xQueueSendToBack error found\n");
}

void inputQueue_ADC_Data(uint8_t mode, uint16_t arr[]){
	if(qid == NULL) return;

	messageBuffer msg;
	BaseType_t p;

	msg.mode = mode;
	msg.adcConv[0] = arr[0];
	msg.adcConv[1] = arr[1];
	msg.adcConv[2] = arr[2];

	p=xQueueSendToBack(qid,&msg,0 );
	if (p != pdPASS) printf("xQueueSendToBack error found\n");
}
