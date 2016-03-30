#include "DoHoa.h"
void gotoxy(short x,short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void textcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void resizeConsole(int width, int height)

{

	HWND console = GetConsoleWindow();

	RECT r;

	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, width, height, TRUE);

}
void drawBoard(int x1, int y1, int x2, int y2, int color,char title[100],int ttColor)
{
	int i;
	multiPut(x1,y1,(char)218,color); //top-left
	multiPut(x2,y1,(char)191,color); //top-right
	multiPut(x1,y2,(char)192,color); //bottom-left
	multiPut(x2,y2,(char)217,color); //bottom-right
	textcolor(color);
	for(i=x1;i<x2-1;i++) //top border */
		multiPut(i+1,y1,(char)196,color);
	for(i=x1;i<x2-1;i++) //bottom border */
		multiPut(i+1,y2,(char)196,color);
	for(i=0;i<y2-y1-1;i++) /* left border */
		multiPut(x1,y1+i+1,(char)179,color);
	for(i=0;i<y2-y1-1;i++) /* right border */
		multiPut(x2,y1+i+1,(char)179,color);
	if (title!=NULL&&strlen(title)<(x2-x1))
		for(i=0;i<strlen(title);i++)
			multiPut(i+(x2+x1)/2-strlen(title)/2,y1,*(title+i),ttColor);
	textcolor(15);
}
void multiPut(int x,int y,char c, int color)
{
	gotoxy(x,y);
	textcolor(color);
	printf("%c",c);
	gotoxy(40,20);
}
void printxy(int x,int y,char c[30])
{
	gotoxy(x,y);
	printf("%s",c);
}