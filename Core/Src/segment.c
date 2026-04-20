#include "segment.h"

// 0부터 9까지 숫자임
// 바이너리의 첫 번째 수가 a임
const uint32_t segment_element[10] = {
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100000,
    0b11111110,
    0b11110110
};

const uint32_t com_pin[4] = {COM1_Pin, COM2_Pin, COM3_Pin, COM4_Pin};
GPIO_TypeDef* com_ports[4] = {GPIOB, GPIOB, GPIOB, GPIOG};

const uint32_t gpio_pin[8] = {SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, SEG_DP_Pin};
GPIO_TypeDef* gpio_port[8] = {GPIOG, GPIOG, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD};

// 계산한 값을 가지고 있어야지 바로 출력할 때 이 배열을 가지고 출력을 함
volatile uint32_t current_num[4] = {0,};

// ADC값을 분리해서 저장하는 코드
uint32_t SEG_UpdateProcess(uint32_t hadc1_arr){
    uint32_t first_digit = hadc1_arr / 1000;
    uint32_t second_digit = (hadc1_arr % 1000) / 100;
    uint32_t third_digit = (hadc1_arr % 100) / 10;
    uint32_t fourth_digit = hadc1_arr % 10;

    current_num[0] = first_digit;
    current_num[1] = second_digit;
    current_num[2] = third_digit;
    current_num[3] = fourth_digit;
    return 1;
}

// 세그먼트를 계산해서 출력하는 코드
void SEG_TimCallback()
{
	//SEG_UpdateProcess();
    // COM1부터 COM4까지 끄기
    for(int i=0; i<4; i++)
    {
        HAL_GPIO_WritePin(com_ports[i], com_pin[i], GPIO_PIN_SET);
    }
    static int current_com = 0;

    for(int i=0; i<8; i++)
    {
        uint32_t num = current_num[current_com];
        uint32_t segment_val = segment_element[num];

        if(segment_val >> (7 -i) & 1)
        {
            HAL_GPIO_WritePin(gpio_port[i], gpio_pin[i], GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(gpio_port[i], gpio_pin[i], GPIO_PIN_RESET);
        }
    }

    HAL_GPIO_WritePin(com_ports[current_com], com_pin[current_com], GPIO_PIN_RESET);
    current_com = (current_com + 1) % 4;
}
