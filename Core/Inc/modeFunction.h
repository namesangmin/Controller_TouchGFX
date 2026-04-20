#ifndef __MODE_FUNCTION__
#define __MODE_FUNCTION__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern void JoxStickMode();
extern void ADCMode();
extern void (*currentFunction)();

#ifdef __cplusplus
}
#endif

#endif
