#ifndef __BOARD_H
#define __BOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

#ifndef KEY_Pin
#define KEY_Pin GPIO_PIN_13
#endif
#ifndef KEY_GPIO_Port
#define KEY_GPIO_Port GPIOC
#endif
#ifndef KEY_GPIO_CLK_ENABLE
#define KEY_GPIO_CLK_ENABLE __HAL_RCC_GPIOC_CLK_ENABLE
#endif

#ifndef LED_Pin
#define LED_Pin GPIO_PIN_2
#endif
#ifndef LED_GPIO_Port
#define LED_GPIO_Port GPIOB
#endif
#ifndef LED_GPIO_CLK_ENABLE
#define LED_GPIO_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE
#endif

#ifndef SD_DETECT_Pin
#define SD_DETECT_Pin GPIO_PIN_8
#endif
#ifndef SD_DETECT_GPIO_Port
#define SD_DETECT_GPIO_Port GPIOA
#endif
#ifndef SD_DETECT_GPIO_CLK_ENABLE
#define SD_DETECT_GPIO_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE
#endif

    void board_button_init(void);
    uint8_t board_button_getstate(void);
    void board_led_init(void);
    void board_led_toggle(void);
    void board_led_set(uint8_t set);
		
		void board_sd_detect_init(void);
		uint8_t board_sd_detect_getstate(void);

#ifdef __cplusplus
}
#endif

#endif
