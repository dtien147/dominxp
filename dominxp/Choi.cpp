#include "Choi.h"
int toadox1,toadoy1;
void Choi(int Hang,int Cot,int Bom)
{
	int t=0;
	Title();
	xuatSoBom();
	xuatbm();
	toadox1=40-Cot;
	toadoy1=18-Hang/2;
	HDSD();
	xemNguoiChoiHienTai();
	drawBoard(70,2,78,4,VANG,"Time",LUC_SANG);
	int k,x1;
	int xnow=toadox1,ynow=toadoy1,x=toadox1,y=toadoy1;
	HANDLE ScreenConsole;  
	DWORD Num, Mode,i=1;  
	INPUT_RECORD ThietBi; 
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);  
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;  
	SetConsoleMode(ScreenConsole,Mode);
	while (1)  
	{ 
		if(RUN())
		{
			ReadConsoleInput(ScreenConsole,&ThietBi,1,&Num); 
			switch(ThietBi.EventType) 
			{ 
			case KEY_EVENT:
				k=KeyEventProcedure(ThietBi.Event.KeyEvent,x,y);
				if (KhongDuocVao(x,0,Cot*2,y,0,Hang)) 
				{x=xnow;y=ynow;}
				else 
				{
					if(!EndGame()) xoalamnoi8(xnow,ynow);
					xnow=x;ynow=y;
				}
				x1=xnow;chuyendoi(x1);
				xnow = x1*2+toadox1;
				switch(k)
				{
				case LAM_NOI: if(!EndGame()) lamnoi(xnow,ynow); break;
				case MO_O: if(!EndGame()) 
						   {
							   Mo(x1,ynow-toadoy1); 
							   if(!EndGame())
							   {lamnoi(xnow,ynow);PlaySound(TEXT("button-09.wav"), NULL, SND_FILENAME);} 
						   }
						   break;
				case DANH_DAU: if(!EndGame()) DanhDau(x1,ynow-toadoy1); break;
				case XEM_O_XQ: if(!EndGame()) {xuatbm();lamnoi8(xnow,ynow);} break;
				case MO_O_XQ: if(!EndGame()&& DuCo(x1,y-toadoy1)) 
							  {
								  Mo8(x1,ynow-toadoy1); 
								  if(!EndGame())
								  {lamnoi(xnow,ynow);PlaySound(TEXT("button-09.wav"), NULL, SND_FILENAME);} 
							  }
							  break;
				case QUAY_LAI: ganEndGame(TRUE); return ;
				case SAVE: if(!EndGame()) Save(); break; 
				case EXIT: luuDiem(); exit(0);
				}
				break;
			case MOUSE_EVENT:
				k= MouseEventProcedure(ThietBi.Event.MouseEvent,x,y);
				if (KhongDuocVao(x,0,Cot*2,y,0,Hang)) 
				{x=xnow;y=ynow;}
				else 
				{
					if(!EndGame()) xoalamnoi8(xnow,ynow);
					xnow=x;ynow=y;
				}
				x1=xnow;chuyendoi(x1);
				xnow = x1*2+toadox1;
				switch(k)
				{
				case LAM_NOI: if(!EndGame()) {lamnoi(xnow,ynow);} break;
				case MO_O: if(!EndGame()) 
						   {
							   Mo(x1,ynow-toadoy1); 
							   if(!EndGame())
							   {lamnoi(xnow,ynow);PlaySound(TEXT("button-09.wav"), NULL, SND_FILENAME);} 
						   }
						   break;
				case DANH_DAU: if(!EndGame()) DanhDau(x1,ynow-toadoy1); break;
				}
				break;
			}
			FlushConsoleInputBuffer(ScreenConsole); 
		}
	}
}
bool KhongDuocVao(int x,int xmin, int xmax,int y,int ymin, int ymax)
{
	if (x<xmin+toadox1 || x>=xmax+toadox1 || y<ymin+toadoy1 || y>=ymax+toadoy1) return true;
	else return false;
}