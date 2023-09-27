#ifndef OLED_H
#define OLED_H
#include "main.h"                  // Device header
#include "i2c.h"
 
 
#define OLED_CMD  0X00 //写命令
#define OLED_DATA 0X40 //写数据
 
#define SSD1306_I2C_ADDR         0x78
#define SSD1306_WIDTH            128
#define SSD1306_HEIGHT           6
 
#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64
 
typedef struct
{
	uint8_t xSize;
	uint8_t ySize;
	const unsigned char *p;
}BMP;
 
 
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size);
void OLED_ShowPic(uint8_t x,uint8_t y,BMP bmp);
uint32_t OLED_Pow(uint8_t m,uint8_t n);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size2);
void OLED_ShowFNum(unsigned x,unsigned y,float Fnum,unsigned char TextSize);
#endif
