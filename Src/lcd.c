#include "lcd.h"


uint8_t powValL;  //电量值左侧数字
uint8_t powValR;  //电量值右侧数字
uint8_t powerValAry[3]={0};  //电量值数组，除两位电量值外增加一位0元素，防止了偶尔显示乱码


///////////////////////////点阵字符数组常量定义////////////////////////////////////////////////

unsigned char const bmp128X64TurnOn[]={
/*--  开机图像，bmp格式--*/
/*--  宽度x高度=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x40,0x80,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4A,0x94,0x22,0x8C,0x81,0x86,0x01,0x8A,
0x44,0x42,0x90,0x60,0x1C,0x01,0x06,0x09,0x04,0xD2,0x24,0x0A,0x04,0x02,0x00,0xC0,
0x34,0x88,0x66,0x82,0x41,0x42,0x84,0x42,0xA9,0x56,0x89,0x42,0x85,0x40,0x46,0x00,
0xEA,0x0A,0x15,0x00,0x00,0x00,0x80,0x40,0x08,0xA6,0x41,0x22,0x81,0x62,0x01,0xA0,
0x43,0xA0,0x02,0x61,0x82,0x20,0x43,0x20,0x81,0x62,0x09,0x46,0x09,0x00,0x00,0xC0,
0x00,0xF0,0x14,0x48,0x03,0x00,0x80,0x4A,0x84,0x02,0x08,0x06,0x00,0x06,0x09,0x02,
0xC4,0x4A,0x04,0x00,0x06,0x00,0x00,0xA0,0x40,0xB0,0x54,0x08,0x02,0x01,0x00,0x54,
0x49,0x96,0x00,0x00,0x00,0x01,0x02,0x41,0x90,0x20,0x18,0x07,0x00,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x70,0x0C,0x03,0x00,0x41,0x90,0x64,0x09,0x02,0x00,
0x80,0x00,0xD4,0x2B,0x90,0x68,0x04,0x09,0x02,0x00,0x00,0x00,0x40,0x14,0x68,0x06,
0x19,0x00,0x18,0x00,0x58,0x84,0x70,0x0F,0x10,0x08,0x10,0x08,0x10,0x08,0x95,0x4A,
0xA1,0x00,0x00,0x00,0x00,0x40,0x80,0x50,0xAC,0x40,0x04,0x00,0x00,0x80,0x50,0xA4,
0x19,0x06,0x08,0x10,0x08,0x08,0x10,0x08,0x08,0x00,0x00,0x00,0x00,0x01,0xA2,0x55,
0x28,0x06,0x00,0x00,0x00,0x00,0x04,0x19,0x26,0x00,0x80,0x40,0xA0,0x1C,0x01,0x0A,
0x01,0x00,0x00,0x00,0x00,0x01,0x90,0x61,0x1E,0x00,0x01,0x00,0x00,0x80,0x40,0x00,
0xCF,0x30,0x46,0xA8,0x94,0x09,0x82,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x01,0x00,0x02,0x04,0x02,0x05,0x02,0x00,0x02,0x00,0x06,0x01,
0x00,0x02,0x00,0x01,0x00,0x05,0x09,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x05,0x02,0x04,0x02,0x02,0x04,0x02,0x02,0x04,0x02,0x01,0x02,
0x00,0x00,0x00,0x05,0x02,0x01,0x00,0x00,0x02,0x01,0x02,0x05,0x02,0x00,0x07,0x00,
0x06,0x00,0x06,0x02,0x04,0x02,0x02,0x04,0x02,0x00,0x00,0x00,0x00,0x06,0x09,0x00,
0x00,0x02,0x04,0x03,0x04,0x01,0x02,0x05,0x02,0x00,0x07,0x00,0x06,0x00,0x03,0x04,
0x02,0x00,0x00,0x00,0x00,0x0A,0x05,0x02,0x00,0x04,0x02,0x01,0x02,0x01,0x00,0x01,
0x00,0x00,0x00,0x00,0x05,0x02,0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xC0,0x20,0xC0,0x20,0x40,0x20,0x00,0x00,0x00,
0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x80,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x40,0x80,0x00,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0xC0,0x00,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xA0,0x40,0xA0,0x40,0xA0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0x70,0x8D,0x12,0x09,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0xAA,0x00,0x00,0x00,0x00,0xC0,0x10,0x60,0x1A,0x04,0x03,0x00,0x00,
0x00,0x00,0x00,0x01,0x01,0x00,0x01,0xC0,0x00,0x75,0x08,0x17,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x78,0x06,0x08,0x02,0x01,0x00,0x00,0x41,0x94,
0x65,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x52,0xAD,0x10,0x06,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x30,0xC4,0x3A,0x85,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x25,0x58,0x86,0x68,0x90,0x20,0x0E,0x01,0x02,0x00,0x00,0x00,0x00,0x40,0xC0,0x20,
0x48,0xB0,0x44,0x8A,0x40,0x43,0xC0,0x01,0x40,0x00,0x00,0x00,0x40,0x80,0x60,0x00,
0x00,0x00,0x00,0x00,0x54,0xAB,0x54,0x81,0x40,0x80,0x40,0x90,0x20,0x1C,0x03,0x04,
0x01,0x00,0x00,0x00,0x00,0x00,0xC0,0x10,0xE4,0x18,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
0x02,0x05,0x08,0x07,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x08,0x04,0x00,0x07,0x01,0x04,0x09,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};


unsigned char const bmp128X64Battery[]={
/*--  调入了电池图像，bmp格式--*/
/*--  宽度x高度=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x20,0x20,0xFC,0x04,
0x04,0xF4,0xF4,0xF4,0xF4,0x04,0xF4,0xF4,0xF4,0xF4,0x04,0xF4,0xF4,0xF4,0xF4,0x04,
0xF4,0xF4,0xF4,0xF4,0x04,0xF4,0xF4,0xF4,0xF4,0x04,0x04,0xFC,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x04,0x3F,0x20,
0x20,0x2F,0x2F,0x2F,0x2F,0x20,0x2F,0x2F,0x2F,0x2F,0x20,0x2F,0x2F,0x2F,0x2F,0x20,
0x2F,0x2F,0x2F,0x2F,0x20,0x2F,0x2F,0x2F,0x2F,0x20,0x20,0x3F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};



///定义数字0~9的16*32点阵常量数组
unsigned char const Num0_16X32DM_Ary[]=
{
0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0xF0,0xFE,0xFF,0x07,0x01,0x00,0x00,0x00,0x00,0x03,0x0F,0xFF,0xFC,0x00,0x00,
0x00,0x1F,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0x7F,0x00,0x00,
0x00,0x00,0x00,0x03,0x03,0x07,0x06,0x0E,0x0E,0x06,0x07,0x03,0x01,0x00,0x00,0x00
};
unsigned char const Num1_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x1C,0x0C,0x06,0x03,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00
};
unsigned char const Num2_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,
0x00,0x04,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0xC1,0xFF,0xFF,0x1E,0x00,0x00,
0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1E,0x0F,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x07,0x07,0x07,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x00,0x00
};
unsigned char const Num3_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0x06,0x0F,0x03,0x01,0x80,0x80,0x80,0xC0,0xC1,0x7F,0x7F,0x1E,0x00,0x00,
0x00,0x40,0xC0,0xE0,0x80,0x00,0x01,0x01,0x01,0x03,0x03,0xDF,0xFE,0xFC,0x00,0x00,
0x00,0x00,0x01,0x03,0x07,0x07,0x06,0x0E,0x0E,0x06,0x07,0x03,0x03,0x00,0x00,0x00
};
unsigned char const Num4_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0xE0,0x70,0x3C,0x1E,0x07,0xFF,0xFF,0x00,0x00,0x00,0x00,
0x70,0x78,0x7E,0x7F,0x73,0x71,0x70,0x70,0x70,0x70,0xFF,0xFF,0x70,0x70,0x70,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x00,0x00,0x00,0x00
};
unsigned char const Num5_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,
0x00,0x80,0xF8,0xFF,0xCF,0x60,0x60,0x60,0x60,0xE0,0xC0,0xC0,0x80,0x00,0x00,0x00,
0x00,0xC1,0xE1,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE7,0xFF,0xFE,0x00,0x00,
0x00,0x01,0x03,0x07,0x06,0x0E,0x0E,0x0E,0x0E,0x07,0x07,0x03,0x01,0x00,0x00,0x00
};
unsigned char const Num6_16X32DM_Ary[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xC0,0xF0,0xF8,0xFE,0xCF,0xC7,0xC1,0xC0,0xC0,0x80,0x00,0x00,0x00,
0x00,0x7C,0xFF,0xFF,0x83,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x00,
0x00,0x00,0x01,0x03,0x07,0x07,0x06,0x0E,0x0E,0x0E,0x06,0x07,0x03,0x01,0x00,0x00
};
unsigned char const Num7_16X32DM_Ary[]=
{
	0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0x3E,0x0F,0x03,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0xF0,0xFE,0x3F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x04,0x07,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
unsigned char const Num8_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x7F,0x7F,0xE1,0xC0,0x80,0x80,0x80,0xC0,0xE1,0x7F,0x7F,0x1E,0x00,0x00,
0x00,0xFC,0xFE,0xCF,0x07,0x03,0x01,0x01,0x01,0x03,0x03,0x8F,0xFE,0xFC,0x00,0x00,
0x00,0x01,0x03,0x07,0x07,0x06,0x0E,0x0E,0x0E,0x06,0x07,0x07,0x03,0x01,0x00,0x00
};
unsigned char const Num9_16X32DM_Ary[]=
{
	0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0xFE,0xFF,0x87,0x01,0x01,0x00,0x00,0x00,0x01,0x83,0xFF,0xFF,0x7E,0x00,0x00,
0x00,0x01,0x03,0x07,0x07,0x06,0x86,0xE6,0xFE,0x7F,0x1F,0x07,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x08,0x0E,0x0F,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
///////////////////////////操作LCD驱动芯片函数定义////////////////////////////////////////////////

/*LCD模块初始化*/
void lcd_init(void)
{
  HAL_Delay(400);
	MX_GPIO_Init();//初始化LCD用到的GPIO
	GPIOA->ODR&=~(1U<<6);///片选驱动芯片
	GPIOB->ODR|=1U;///不片选字库芯片
      
	lcd_transfer_command(0xAE);   //display off
	lcd_transfer_command(0x20);	//Set Memory Addressing Mode	
	lcd_transfer_command(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	lcd_transfer_command(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	lcd_transfer_command(0xc8);	//Set COM Output Scan Direction
	lcd_transfer_command(0x00);//---set low column address
	lcd_transfer_command(0x10);//---set high column address
	lcd_transfer_command(0x40);//--set start line address
	lcd_transfer_command(0x81);//--set contrast control register
	lcd_transfer_command(0xFF);
	lcd_transfer_command(0xa1);//--set segment re-map 0 to 127
	lcd_transfer_command(0xa6);//--set normal display
	lcd_transfer_command(0xa8);//--set multiplex ratio(1 to 64)
	lcd_transfer_command(0x3F);//
	lcd_transfer_command(0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	lcd_transfer_command(0xd3);//-set display offset
	lcd_transfer_command(0x00);//-not offset
	lcd_transfer_command(0xd5);//--set display clock divide ratio/oscillator frequency
	lcd_transfer_command(0xf0);//--set divide ratio
	lcd_transfer_command(0xd9);//--set pre-charge period
	lcd_transfer_command(0x22); //
	lcd_transfer_command(0xda);//--set com pins hardware configuration
	lcd_transfer_command(0x12);                                                                                         
	lcd_transfer_command(0xdb);//--set vcomh
	lcd_transfer_command(0x20);//0x20,0.77xVcc
	lcd_transfer_command(0x8d);//--set DC-DC enable
	lcd_transfer_command(0x14);//
	lcd_transfer_command(0xaf);//--turn on oled panel 
	GPIOA->ODR|=1U<<6;
}


/*写指令到LCD模块*/
void lcd_transfer_command(uint32_t data1)  
{
	char i;
	GPIOA->ODR&=~(1U<<5);;;  ///LCD的D/C引脚下拉后，为写指令状态
	GPIOA->ODR&=~(1U<<6);///LCD的CS引脚下拉后，为选中LCD驱动芯片状态
	
  ///因为程序采用的时4线SPI输入LCD模式，在CLK引脚的上升沿时将MOSI引脚的高（bit==1）/低电平（bit==0）写入到指令字节
  ///（高电平写入1）或屏幕显示字节（高电平为点亮），先MSB
  for(i=0;i<8;i++)
   {
     GPIOA->ODR&=~(1U<<3);;;
		
		if(data1&0x80) {GPIOA->ODR|=1U<<4;;;}///设置好MOSI电平状态
		else {GPIOA->ODR&=~(1U<<4);;;}
		GPIOA->ODR|=1U<<3;///产生上升沿，并写入MOSI的电平值。MCU串口模拟SPI，在sclk引脚上升沿写数据到显示屏驱动芯片
		__nop();;;///空语句，起延时作用

	 	data1<<=1;
   }
	 GPIOA->ODR|=1U<<5;;;
	 GPIOA->ODR|=1U<<6;;
}

/*写数据到LCD模块*/
void lcd_transfer_data(uint32_t data1)  ///一次写8个像素，字节bit==1写亮点；bit==0写暗点
{
	char i;
	GPIOA->ODR|=1U<<5;;;
	GPIOA->ODR&=~(1U<<6);
	for(i=0;i<8;i++)
   {
		GPIOA->ODR&=~(1U<<3);;;  ///时钟低电平为使能
		if(data1&0x80) {GPIOA->ODR|=1U<<4;;;}  ///开时钟后，MOSI开一次输出一个亮点？？？
		else {GPIOA->ODR&=~(1U<<4);;;}     ///开时钟后，MOSI关一次输出一个暗点？？？
		GPIOA->ODR|=1U<<3;;;
		__nop();;;
		//lcd_sclk(0);;;
	 	data1<<=1;
   }
	GPIOA->ODR|=1U<<5;;;
	GPIOA->ODR|=1U<<6;
}



///设置下步操作的地址。column:列 page：页
void lcd_address(uint8_t column,uint8_t page)  
{

	lcd_transfer_command(0xb0 + page);   /*设置页地址*/
	lcd_transfer_command(((column & 0xf0) >> 4) | 0x10);	/*设置列地址的高4位*/  
	lcd_transfer_command((column & 0x0f) | 0x00);	/*设置列地址的低4位*/	   
}



/*显示8x16点阵图像、ASCII, 或8x16点阵的自造字符、其他图标*/
//输入参数为点阵字符数组地址
void lcd_display8x16(uint32_t page,uint8_t column,uint8_t *dp)
{
	uint32_t i,j;
	GPIOA->ODR&=~(1U<<6);	
	for(j=2;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<8;i++)
		{	
			lcd_transfer_data(*dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
			dp++;
		}
		page++;
	}
	GPIOA->ODR|=1U<<6;
}



/*显示16x16点阵图像、汉字、生僻字或16x16点阵的其他图标*/
//输入参数为点阵字符数组地址
 void lcd_display16x16(uint32_t page,uint32_t column,const uint8_t *dp)
{
	uint32_t i,j;
 	GPIOA->ODR&=~(1U<<6);
	GPIOC->ODR|=1U<<9; 	
	for(j=2;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<16;i++)
		{	
			lcd_transfer_data(*dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
			dp++;
		}
		page++;
	}
	GPIOA->ODR|=1U<<6;
}


/*显示16x32点阵图像、汉字、生僻字或16x16点阵的其他图标*/
 void lcd_display16x32(uint32_t page,uint32_t column,const uint8_t *dp)
{
	uint32_t i,j;
 	GPIOA->ODR&=~(1U<<6);
	GPIOB->ODR|=1U; 	
	for(j=4;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<16;i++)
		{	
			lcd_transfer_data(*dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
			dp++;
		}
		page++;
	}
	GPIOA->ODR|=1U<<6;;
}

///将整数值FD_EnergyVal的每个数字对应的16*32点阵字符数组，存入FourNum16X32DM_Ary[4*16*4]中
void lcd_showFourNumBy16X32DM(int FD_EnergyVal)
{
	char i;
	///将整型数FD_EnergyVal的每个数字依次存入数组tempcharAry中。如FD_EnergyVal=1234，将1放入组tempcharAry[]中,以此类推。
	char tempcharAry[6]={0};
	tempcharAry[0]=(FD_EnergyVal/100000)%10;
	tempcharAry[1]=(FD_EnergyVal%100000)/10000;
	tempcharAry[2]=(FD_EnergyVal%10000)/1000;
	tempcharAry[3]=(FD_EnergyVal%1000)/100;
  tempcharAry[4]=(FD_EnergyVal%100)/10;
  tempcharAry[5]=FD_EnergyVal%10;
	///
//	tempcharAry[0]=(FD_EnergyVal/1000)%10;
//	tempcharAry[1]=(FD_EnergyVal%1000)/100;
//	tempcharAry[2]=(FD_EnergyVal%100)/10;
//	tempcharAry[3]=FD_EnergyVal%10;
	//将整型数FD_EnergyVal的每个数字按16*32点阵显示
	for(i=0;i<6;i++)
	{
		switch(tempcharAry[i])
		{
			case 0:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num0_16X32DM_Ary);
				break;
			case 1:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num1_16X32DM_Ary);
				break;
			case 2:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num2_16X32DM_Ary);
				break;
			case 3:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num3_16X32DM_Ary);
				break;
			case 4:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num4_16X32DM_Ary);
				break;
			case 5:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num5_16X32DM_Ary);
				break;
			case 6:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num6_16X32DM_Ary);
				break;
			case 7:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num7_16X32DM_Ary);
				break;
			case 8:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num8_16X32DM_Ary);
				break;
			case 9:
				lcd_display16x32(3,GAP_FD_energyVal+i*16,Num9_16X32DM_Ary);
				break;
			default:break;
		}
	}
}



/*显示128x16点阵图像*/
//输入参数为点阵字符数组地址
void lcd_display128x16(const uint8_t *dp)
{
	uint32_t i,j;
	GPIOA->ODR&=~(1U<<6);
	for(j=0;j<2;j++)
	{
		lcd_address(0,j);  ///param1：第几列（水平方向1个像素为一列）param2：第几页（竖直方向8个像素为一页）
		for (i=0;i<128;i++)  ///执行一次写完128*8个像素？？？
		{	
			lcd_transfer_data(*dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
			dp++;
		}
	}
	GPIOA->ODR|=1U<<6;
}



/*显示128x64点阵图像*/
//输入参数为点阵字符数组地址
void lcd_display128x64(const uint8_t *dp)
{
	uint32_t i,j;
	GPIOA->ODR&=~(1U<<6);
	for(j=0;j<8;j++)
	{
		lcd_address(0,j);  ///param1：第几列（水平方向1个像素为一列）param2：第几页（竖直方向8个像素为一页）
		for (i=0;i<128;i++)  ///执行一次写完128*8个像素？？？
		{	
			lcd_transfer_data(*dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
			dp++;
		}
	}
	GPIOA->ODR|=1U<<6;
}


///////////////////////////操作字库驱动芯片函数定义////////////////////////////////////////////////


/****送指令到晶联讯字库IC***/
///写入数据方式与LCD驱动IC完全相同，都是SCK引脚上升沿写入SI引脚电平。与LCD驱动共用SCK和MOSI
void lcd_sendCommandToROM( uint8_t datu )
{
	uint8_t i;
	for(i=0;i<8;i++ )
	{
		//根据MSB的为0或1，MOSI引脚写入高或低电平
		if(datu&0x80)
			{GPIOA->ODR|=1U<<4;;;__nop();}
		else
			{GPIOA->ODR&=~(1U<<4);;; __nop(); }
			datu = datu<<1;
			
			//CLK产生上升沿，来写入MOSI引脚电平
			GPIOA->ODR&=~(1U<<3);;;__nop();
			GPIOA->ODR|=1U<<3;;;__nop();
	}
}



/****从晶联讯字库IC中取汉字或字符数据（1个字节）***/
///clk每一个下降沿都从SO引脚读一个bit
static uint8_t lcd_getDataFormROM( )
{	
	uint8_t i;
	uint8_t ret_data=0;
	GPIOA->ODR|=1U<<3;;;  __nop();

  ///电平转换，所有此句设置输入或输出不影响结果
	for(i=0;i<8;i++)
	{
//		Rom_OUT(1);;; __nop();///（原版有此句）已经将PB12设置为输入模式，这句输出电平有什么用？？？
		GPIOA->ODR&=~(1U<<3);;;__nop();///下降沿从字库IC的SO引脚输出数据
		ret_data=ret_data<<1;///根据SO引脚输出高低电平将bit存入ret_data
		if( GPIOA->IDR&1U<<7 )//判读PA8(字库芯片输出引脚电平)
			{ret_data=ret_data+1;;;__nop();}
		else
			{ret_data=ret_data+0;;;__nop();	}
		GPIOA->ODR|=1U<<3;
	}
//	GBZK_ROMOUTRESET();///（原版有此句）将PB12设置为输出模式，作用？？？
	return(ret_data);
}




/****从晶联讯字库IC中某个地址取n个字节***/
/*从相关地址（addrHigh：地址高字节,addrMid：地址中字节,addrLow：地址低字节）中连续读出DataLen个字节的数据到 pBuff的地址*/
/*连续读取*/
void lcd_getBytesFormROM(uint8_t addrHigh,uint8_t addrMid,uint8_t addrLow,uint8_t *pBuff,uint8_t DataLen )
{
	uint8_t i;
	GPIOB->ODR&=~(1U);//片选字库芯片
	GPIOA->ODR|=1U<<6;	//不片选驱动芯片
	GPIOA->ODR&=~(1U<<3);//CLK引脚置0
	lcd_sendCommandToROM(0x03);
	lcd_sendCommandToROM(addrHigh);
	lcd_sendCommandToROM(addrMid);
	lcd_sendCommandToROM(addrLow);
	for(i = 0; i < DataLen; i++ )
	     *(pBuff+i) =lcd_getDataFormROM();
	GPIOB->ODR|=1U;
}



///////////////////////////综合功能函数定义////////////////////////////////////////////////

/****直接输入汉字(16*16点阵)、字母（8*16）、数字（8*16）组成的字符串，通过晶联讯字库IC取对应点阵字符数组，并显示到LCD***/
///*显示汉字到LCD上，y为页地址，x为列地址，text为字符串而非点阵字符数组*/
uint32_t  fontaddr=0;
void lcd_displayGB2312String(uint8_t y,uint8_t x,uint8_t *text)
{
	uint8_t i= 0;
	uint8_t addrHigh,addrMid,addrLow ;
	uint8_t fontbuf[32];			
	while((text[i]>0x00))
	{
		if(((text[i]>=0xb0) &&(text[i]<=0xf7))&&(text[i+1]>=0xa1))
		{						
			/*国标简体（GB2312）汉字在晶联讯字库IC中的地址由以下公式来计算：*/
			/*Address = ((MSB - 0xB0) * 94 + (LSB - 0xA1)+ 846)*32+ BaseAdd;BaseAdd=0*/
			/*由于担心8位单片机有乘法溢出问题，所以分三部取地址*/
			fontaddr = (text[i]- 0xb0)*94; 
			fontaddr += (text[i+1]-0xa1)+846;
			fontaddr = (uint32_t)(fontaddr*32);
			
			addrHigh = (fontaddr&0xff0000)>>16;  /*地址的高8位,共24位*/
			addrMid = (fontaddr&0xff00)>>8;      /*地址的中8位,共24位*/
			addrLow = fontaddr&0xff;	     /*地址的低8位,共24位*/
			lcd_getBytesFormROM(addrHigh,addrMid,addrLow,fontbuf,32 );/*取32个字节的数据，存到"fontbuf[32]"*/
			lcd_display16x16(y,x,fontbuf);/*显示汉字到LCD上，y为页地址，x为列地址，fontbuf[]为数据*/
			i+=2;
			x+=16;
		}
		else if(((text[i]>=0xa1) &&(text[i]<=0xa3))&&(text[i+1]>=0xa1))
		{						
			/*国标简体（GB2312）15x16点的字符在晶联讯字库IC中的地址由以下公式来计算：*/
			/*Address = ((MSB - 0xa1) * 94 + (LSB - 0xA1))*32+ BaseAdd;BaseAdd=0*/
			/*由于担心8位单片机有乘法溢出问题，所以分三部取地址*/
			fontaddr = (text[i]- 0xa1)*94; 
			fontaddr += (text[i+1]-0xa1);
			fontaddr = (uint32_t)(fontaddr*32);
			
			addrHigh = (fontaddr&0xff0000)>>16;  /*地址的高8位,共24位*/
			addrMid = (fontaddr&0xff00)>>8;      /*地址的中8位,共24位*/
			addrLow = fontaddr&0xff;	     /*地址的低8位,共24位*/
			lcd_getBytesFormROM(addrHigh,addrMid,addrLow,fontbuf,32 );/*取32个字节的数据，存到"fontbuf[32]"*/
			lcd_display16x16(y,x,fontbuf);/*显示汉字到LCD上，y为页地址，x为列地址，fontbuf[]为数据*/
			i+=2;
			x+=16;
		}
		else if((text[i]>=0x20) &&(text[i]<=0x7e))	
		{						
			unsigned char fontbuf[16];			
			fontaddr = (text[i]- 0x20);
			fontaddr = (unsigned long)(fontaddr*16);
			fontaddr = (unsigned long)(fontaddr+0x3cf80);			
			addrHigh = (fontaddr&0xff0000)>>16;
			addrMid = (fontaddr&0xff00)>>8;
			addrLow = fontaddr&0xff;

			lcd_getBytesFormROM(addrHigh,addrMid,addrLow,fontbuf,16 );/*取16个字节的数据，存到"fontbuf[32]"*/
			
			lcd_display8x16(y,x,fontbuf);/*显示8x16的ASCII字到LCD上，y为页地址，x为列地址，fontbuf[]为数据*/
			i+=1;
			x+=8;
		}
		else
			i++;	
	}
	
}



//全屏清屏
void lcd_clear_screen(void)
{
	unsigned char i,j;
	GPIOA->ODR&=~(1U<<6);  ///片选lcd
	GPIOB->ODR|=1U;	 ///不片选GT
	for(i=0;i<8;i++)
	{
		lcd_transfer_command(0xb0+i);
		lcd_transfer_command(0x00);
		lcd_transfer_command(0x10);
		for(j=0;j<150;j++)
		{
		  	lcd_transfer_data(0x00);
		}
	}
 	GPIOA->ODR|=1U<<6; 
}



//开机效果
void lcd_turnOnShow(void)
{
	lcd_clear_screen();    //LCD清屏
	lcd_display128x64(bmp128X64TurnOn);//显示开机画面
	HAL_Delay(200);	
		
	//开机图片渐淡效果，分10档到消失		
	for(int i=0;i<10;i++)
	{
		//设置屏幕对比度
		lcd_transfer_command(0x81);
		lcd_transfer_command(0xFF-i*0xFF/10);
		HAL_Delay(50);
	}
	HAL_Delay(100);
	
	lcd_clear_screen();    //LCD清屏
	
	//恢复对比度到最高
	lcd_transfer_command(0x81);
	lcd_transfer_command(0xFF);
	//
}



//显示电池剩余电量
void lcd_showBatPower(void)
{
	//重绘全屏，显示电池图标
	lcd_display128x16(bmp128X64Battery);  ///（1）片选LCD(2)开时钟（3）开MOSI（4）关时钟 以上4步写一个亮点；暗点将（3）关闭即可		
	lcd_displayGB2312String(0,10,(uint8_t*)"电量:  %");	/*在第0页，第10列，显示一串16x16点阵汉字或8x16的ASCII字*/		
		
	powerValAry[0]=0x30+powValL;  //将数值转换成对应ASCII码
	powerValAry[1]=0x30+powValR;
	lcd_displayGB2312String(0,GAP_PowVal,powerValAry);  //一次显示16column，即两个ASCII数字

}



//屏幕休眠前的显示
void lcd_showBeforeLcdSleep(uint8_t model)
{
	lcd_clear_screen();//清屏
	lcd_transfer_command(0xA6);//必须加，防止上次放电后正好切换到蒙版显示，那底色就是亮的了
	lcd_showBatPower();//显示电量
	if(model==1)//上位机控制模式
	{
		lcd_displayGB2312String(3,10,(uint8_t*)"上位机监测中...");
		lcd_displayGB2312String(6,18,(uint8_t*)"屏幕即将休眠");
		lcd_transfer_command(0xAF);//唤醒LCD
		HAL_Delay(1000);
	}
	else
	{
		lcd_displayGB2312String(3,10,(uint8_t*)"监测中....");
		lcd_displayGB2312String(6,18,(uint8_t*)"屏幕即将休眠");
		HAL_Delay(5000);
	}
	
	//lcd_transfer_command(0xAE);//LCD休眠
}		
