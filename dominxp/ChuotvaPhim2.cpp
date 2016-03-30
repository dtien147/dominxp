#include "ChuotvaPhim2.h"
int KeyEventProcedure(KEY_EVENT_RECORD key, int &x,int &y) 
{ 

	if(key.bKeyDown) 
	{ 
		switch(key.uChar.AsciiChar)
		{
		case 's' : return 6;
		case 'x' : return 1;
		case 'c' : return 2;
		case 'z' : return 3;
		case 'a' : return 4;
		case 'r' : return 5;
		}
		switch(key.wVirtualKeyCode) 
		{ 
		case VK_UP:y--;break; 
		case VK_DOWN:y++;break; 
		case VK_LEFT: x-=2;break;
		case VK_RIGHT: x+=2;break;
		case VK_ESCAPE: return 7; 
		} 
	} 
	return 0;
} 
int MouseEventProcedure(MOUSE_EVENT_RECORD mouse,int &x,int &y)
{ 
	int xmouse=mouse.dwMousePosition.X; 
	int ymouse=mouse.dwMousePosition.Y; 
		switch(mouse.dwEventFlags) 
	{ 
		case 0:
			if(mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				x=xmouse;
				y=ymouse;
				return 1;
			}
			if(mouse.dwButtonState == RIGHTMOST_BUTTON_PRESSED )
			{
				x=xmouse;
				y=ymouse;
				return 2;
			}
			break;
		case MOUSE_MOVED:
			x=xmouse;
			y=ymouse;
			break;
	} 
	return 0;
}