#include "LoadGame.h"
void LoadGame()
{
	int Hang,Cot,Bom;
	system("cls");
	Title();
	int k=Load(Hang,Cot,Bom);
	if(k==KHONG_DUOC) 
	{
		printxy(28,4,"Game truoc da ket thuc");
		_getch();
		return;
	}
	ganEndGame(FALSE);
	std::thread first (thoigian,100);
	std::thread second (Choi,Hang,Cot,Bom);
	first.join();
	second.join();  
}				