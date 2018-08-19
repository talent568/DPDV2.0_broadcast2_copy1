#ifndef __LCD_H
#define __LCD_H

#include "stm32l1xx_hal.h"
#include "gpio.h"

#define GAP_PowVal  10+40  //����ֵ����Ļ���Եcolumn������ֵ��������ַ������ȵ���
#define GAP_FD_energyVal  10	//����ŵ�����ֵ������Ǹ����־���Ļ���Եcolumn����

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
