#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

uint32_t SEG_UpdateProcess(uint32_t hadc1_arr);
void SEG_TimCallback();
#ifdef __cplusplus
}
#endif
#endif
