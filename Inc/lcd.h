#ifndef __LCD_H
#define __LCD_H

#include "stm32l1xx_hal.h"
#include "gpio.h"

#define GAP_PowVal  10+40  //电量值距屏幕左边缘column数，该值根据左侧字符串长度调整
#define GAP_FD_energyVal  10	//定义放电能量值最左侧那个数字距屏幕左边缘column个数

extern unsigned char const bmp128X64TurnOn[];


void lcd_init(void);
void lcd_transfer_command(uint32_t data1);
void lcd_transfer_data(uint32_t data1);
void lcd_address(uint8_t column,uint8_t page);
void lcd_display128x16(const uint8_t *dp);
void lcd_display128x64(const uint8_t *dp);
void lcd_displayGB2312String(uint8_t y,uint8_t x,uint8_t *text);
void lcd_clear_screen(void);
void lcd_turnOnShow(void);
void lcd_showBatPower(void);
void lcd_showFourNumBy16X32DM(int FD_EnergyVal);
void lcd_showBeforeLcdSleep(uint8_t model);

#endif
