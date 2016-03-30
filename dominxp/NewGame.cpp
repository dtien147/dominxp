#include "NewGame.h"

void NewGame()
{
	int Hang,Cot,Bom;
	cauhinh(choncauhinh(),Hang,Cot,Bom);
	system("cls");
	Title();
	textcolor(15);
	ganTime(1);
	khoitao(Bom,Hang,Cot);
	std::thread first (thoigian,100);
	std::thread second (Choi,Hang,Cot,Bom);
	first.join();
	second.join();  
}
int choncauhinh()
{
	Title();
	CauHinhMenu();
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
			if (dongmenu>10) dongmenu=7;
			if (dongmenu<7) dongmenu=10;
			lamnoi2(dongmenu);
		case MOUSE_EVENT: // mouse input 
			if(MouseEventProcedure(ThietBi.Event.MouseEvent,dongmenu,30,45,7,10)!=0) return dongmenu;
			lamnoi2(dongmenu);
		}
		FlushConsoleInputBuffer(ScreenConsole); 
	}
}
void cauhinh(int y,int &Hang,int &Cot,int &Bom)
{
	system("cls");

	switch(y)
	{
	case 7 :
		Hang=10;
		Cot=10;
		Bom=20;
		break;
	case 8 :
		Hang=16;
		Cot=16;
		Bom=40;
		break;
	case 9 :
		Hang=20;
		Cot=20;
		Bom=200;
		break;
	case 10 :
		Title();
		textcolor(15);
		gotoxy(25,6);
		printf("Nhap so hang (MAX=20, MIN=5) : ");
		scanf("%d",&Hang);
		gotoxy(25,7);
		printf("Nhap so cot (MAX=20, MIN=5) : ");
		scanf("%d",&Cot);
		gotoxy(25,8);
		printf("Nhap so bom (MAX=%d, MIN=%d): ",(Hang*Cot/2),10);
		scanf("%d",&Bom);
		break;
	}
}