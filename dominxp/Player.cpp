#include"Player.h"
Player Z[11];
void NhapNguoiChoi()
{
		_flushall();
		printxy(20,4,"Moi ban nhap ten (Ngan hon 10) : ");
		gets(Z[10].Ten);
		Z[10].Diem=0;
		printxy(20,4,"                                                   ");
	
}
void luuThongTin(float Diem)
{
	Z[10].Diem=Diem;
}
void layThongTin()
{
	FILE *g=fopen("Player.txt","r");
	fscanf(g, "%s",&Z[10].Ten); 
	fclose(g);
}
void xemNguoiChoiHienTai()
{
	drawBoard(1,2,15,4,30,"Nguoi choi",10);
	printxy(3,3,Z[10].Ten);
}
void luuBangThanhTich()
{
	system("cls");
	FILE *g=fopen("BangThanhTich.txt","w");
	for(int i=0;i<10;i++)
	{
		fprintf(g, "%s\n",Z[i].Ten); 
		fprintf(g, "%.2f\n",Z[i].Diem);
	}
	fclose(g);
}
void sapxepNguoiChoi()
{
	int n=11;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (Z[i].Diem<Z[j].Diem)
			{
				Player temp= Z[i];
				Z[i]=Z[j];
				Z[j]=temp;
			}
}
void layBangThanhTich()
{
	if (!coBangThanhTich()) taoBangThanhTich();
	FILE *g=fopen("BangThanhTich.txt","r");
	for(int i=0;i<10;i++)
	{
		fgets(Z[i].Ten,10,g);
		fscanf(g,"%f",&Z[i].Diem);
		fscanf(g,"%c");
		int k=strlen(Z[i].Ten)-1;
		if(Z[i].Ten[k]=='\n') Z[i].Ten[k]='\0';
	}
	fclose(g);
}
void taoBangThanhTich()
{
	FILE *f=fopen("BangThanhTich.txt","w");
	for(int i=0;i<10;i++)
	{
		fprintf(f,"Player%d\n",i);
		fprintf(f,"%d\n",100-(10*i));
	}
	fclose(f);
}
bool coBangThanhTich()
{
	FILE *f=fopen("BangThanhTich.txt","r");
	if(f==NULL) return FALSE;
	else
	{
		fclose(f);
		return true;
	}
}
void xemBangThanhTich()
{

	system("cls");
	for(int i=0;i<10;i++)
	{
		gotoxy(20,4+i);printf("%d. %s ",i+1,Z[i].Ten); 
		gotoxy(50,4+i);printf("%.2f",Z[i].Diem);
	}
	Title();
	_getch();
}
void luuNguoiChoi()
{
	FILE *g=fopen("Player.txt","w");
	fprintf(g, "%s",&Z[10].Ten); 
	fclose(g);
}