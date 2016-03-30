#include <Windows.h>
#include <stdio.h>
#pragma once
#define DEN 0
#define LAM 1
#define LUC 2
#define LUC_LAM 3
#define DO 4
#define TIM 5
#define NAU 6
#define XAM_SANG 7
#define XAM_TRO 8
#define LAM_SANG 9
#define LUC_SANG 10
#define LUC_LAM_SANG 11
#define DO_SANG 12
#define TIM_SANG 13
#define VANG 14
#define TRANG 15
void gotoxy(short x,short y);															//Di den toa do x,y tren man hinh
void textcolor(WORD color);																//Mau chu
void SetBGColor(WORD color);															//Mau nen
void resizeConsole(int width, int height);												//Thay doi kich co man hinh Console
void drawBoard(int x1, int y1, int x2, int y2, int color,char title[100],int ttColor);	//Ve bang
void multiPut(int x,int y,char c, int color);											//In ky tu c ra man hinh tai toa do x,y
void printxy(int x,int y,char c[30]);													//In xau c ra man hinh tai toa do x,y