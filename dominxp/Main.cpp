#include "Main.h"
void main()
{
	resizeConsole(800,500);
	SetConsoleTitle("MINESWEEPER");
	int K=0;
	do 
	{
		system("cls");
		Title();
		K=Chon();
		switch(K)
		{
		case 6: NewGame();break;
		case 7: LoadGame();break;
		case 8: HighScores();break;
		case 9: Law();break;
		case 10: exit(0);break;
		}
		luuDiem();

	} while(K!=10);
}
int Chon()
{
	Title();
	MainMenu();
	int dongmenu=7,m,k;
	HANDLE ScreenConsole;  
	DWORD Num, Mode,i=1;  
	INPUT_RECORD ThietBi; 
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);  
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;  
	SetConsoleMode(ScreenConsole,Mode);
	while (1)  
	{ 
		ReadConsoleInput(ScreenConsole,&ThietBi,1,&Num); 
		switch(ThietBi.EventType) 
		{ 
		case KEY_EVENT: // ban phim  
			if(KeyEventProcedure(ThietBi.Event.KeyEvent,dongmenu)!=0) return dongmenu;
			if (dongmenu>10) dongmenu=6;
			if (dongmenu<6) dongmenu=10;
			lamnoi1(dongmenu);
		case MOUSE_EVENT: // mouse input 
			if(MouseEventProcedure(ThietBi.Event.MouseEvent,dongmenu,33,50,6,10)!=0) return dongmenu;
			lamnoi1(dongmenu);
		}
		FlushConsoleInputBuffer(ScreenConsole); 
	}
}