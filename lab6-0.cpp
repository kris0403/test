{\rtf1\ansi\ansicpg950\cocoartf1504\cocoasubrtf600
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;\csgray\c100000;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /**\
  ******************************************************************************\
  * @file    main.c\
  * @author  Ac6\
  * @version V1.0\
  * @date    01-December-2013\
  * @brief   Default main function.\
  ******************************************************************************\
*/\
\
#include<stdio.h>\
#include<stdlib.h>\
#include "stm32l4xx.h"\
#include "stm32l4xx_nucleo.h"\
			\
\
//These functions inside the asm file\
extern void GPIO_init();\
extern void max7219_init();\
extern void max7219_send(unsigned char address, unsigned char data);\
/**\
* TODO: Show data on 7-seg via max7219_send\
* Input:\
* data: decimal value\
* num_digs: number of digits will show on 7-seg * Return:\
* 0: success\
* -1: illegal data range(out of 8 digits range) */\
\
int display(int data, int num_digs)\
\{\
	int i=1;\
		if(num_digs>8)return -1;\
\
		while(i <= num_digs)\
		\{\
			int temp = data % 10;\
			max7219_send(i,temp);\
			data /= 10;\
			i++;\
		\}\
		return 0;\
\
\
\}\
int main()\
\{\
  int student_id = 316206;\
  GPIO_init();\
  max7219_init();\
  display(student_id, 8);\
\}\
}