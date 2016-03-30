#include "ManHinh.h"
void Title()
{
		drawBoard(0,0,79,37,LUC_LAM_SANG,"MINESWEEPER",LUC_SANG);
}
void MainMenu()
{
	textcolor(TRANG);
	printxy(33,6,"Van moi");
	printxy(33,7,"Choi tiep");
	printxy(33,8,"Xem diem");
	printxy(33,9,"Xem luat choi");
	printxy(33,10,"Thoat");
}
void CauHinhMenu()
{
	textcolor(TRANG);
	printxy(30,6,"Chon cau hinh ban muon : ");
	printxy(30,7,"10 x 10 - 20 Bom");
	printxy(30,8,"16 x 16 - 40 Bom");
	printxy(30,9,"20 x 20 - 200 Bom");
	printxy(30,10,"Nhap vao");
}
void lamnoi1(int y)
{
	MainMenu();
	SetBGColor(XAM_SANG);
	textcolor(FOREGROUND_RED|FOREGROUND_INTENSITY);
	switch (y)
	{
	case 6:printxy(33,6,"Van moi");break;
	case 7:printxy(33,7,"Choi tiep");break;
	case 8:printxy(33,8,"Xem diem");break;
	case 9:printxy(33,9,"xem luat choi");break;
	case 10:printxy(33,10,"Thoat");break;
	}
	textcolor(TRANG);
	SetBGColor(DEN);
}
void lamnoi2(int y)
{
	CauHinhMenu();
	SetBGColor(XAM_SANG);
	textcolor(FOREGROUND_RED|FOREGROUND_INTENSITY);
	switch (y)
	{
	case 7:printxy(30,7,"10 x 10 - 20 Bom");break;
	case 8:printxy(30,8,"16 x 16 - 40 Bom");break;
	case 9:printxy(30,9,"20 x 20 - 200 Bom");break;
	case 10:printxy(30,10,"Nhap vao");break;
	}
	textcolor(TRANG);
	SetBGColor(DEN);
}
void HDSD()
{
	drawBoard(1,30,78,36,30,"Huong dan",10);
	textcolor(TRANG);
	printxy(2,31,"Su dung chuot trai de chon va chuot phai de danh dau");
	printxy(2,32,"Su dung cac phim mui ten de di chuyen va : ");
	printxy(2,33,"X : mo o                                  C : danh dau");	
	printxy(2,34,"Z : lam noi nhung o xung quanh            A : mo nhung o xung quanh");
	printxy(2,35,"S : Luu            ESC : Thoat            R : Quay lai man hinh chinh");
}
void Law()
{
	system("cls");
	char s[320]="";
	textcolor(15);
	FILE *f=fopen("Law.txt","rb");
	fread(s,sizeof(char), 320, f);
	gotoxy(0,4);
	printf("%s", s);
	Title();
	_getch();
	fclose(f);

}
