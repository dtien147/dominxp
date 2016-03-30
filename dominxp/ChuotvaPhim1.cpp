#include "ChuotvaPhim1.h"
int KeyEventProcedure(KEY_EVENT_RECORD key, int &dongmenu) 
{ 
	if(key.bKeyDown) 
	{ 
		switch(key.wVirtualKeyCode) 
		{ 
		case VK_UP:dongmenu--;break; 
		case VK_DOWN:dongmenu++;break; 
		case VK_ESCAPE: exit(1); 
		case 13: return 1; // Enter=13;
		} 
	} 
	return 0;
} 
int MouseEventProcedure(MOUSE_EVENT_RECORD mouse,int &dongmenu,int xmin,int xmax, int ymin, int ymax) 
{ 
	int xmouse=mouse.dwMousePosition.X; 
	int ymouse=mouse.dwMousePosition.Y; 
	if(xmouse>=xmin && xmouse<=xmax && ymouse>=ymin && ymouse<=ymax)
		switch(mouse.dwEventFlags) 
	{ 
		case 0:
			if(mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				return 1;
		case MOUSE_MOVED:
			dongmenu=ymouse;
			break;
	} 
	return 0;
}