#include "BaiMin.h"
int Hang,Cot,Bom,SoOConLai,Co,SoBom;
int BM[100][100], BC[100][100];
int toadox,toadoy; // toa do de canh giua
void loang(int x, int y)
{
	if (BC[y][x]!=DANH_DAU && BC[y][x]!=DA_MO)
	{
		SoOConLai--;
		BC[y][x]=DA_MO;
		if(BM[y][x]==O_TRONG)
		{
			if (x!=0) loang(x-1,y);
			if (x+1!=Cot) loang(x+1,y);
			if (y!=0) loang(x,y-1);
			if (y+1!=Hang) loang(x,y+1);
			if(x!=0 && y!=0) loang(x-1,y-1);
			if(x+1!=Cot && y!=0) loang(x+1,y-1);
			if(x!=0 && y+1!=Hang) loang(x-1,y+1);
			if(x+1!=Cot  && y+1!=Hang) loang(x+1,y+1);
		}
	}
}
void khoitao(int BOOM,int x,int y)
{
	NhapNguoiChoi();
	ganEndGame(FALSE);
	Hang=x; Cot=y; Bom=BOOM; SoBom=BOOM;
	for(int i=0;i<Hang;i++)
		for(int j=0;j<Cot;j++)
		{
			BM[i][j]=O_TRONG;
			BC[i][j]=CHUA_MO;
		}
	toadox=40-Cot;
	toadoy=18-Hang/2;
	SoOConLai=Hang*Cot;
	int x1,y1;
	srand(time(NULL));
	int i=0;
	while (i<BOOM)
	{
		x1=rand()%x;
		y1=rand()%y;
		if (BM[x1][y1]==O_TRONG) 
		{
			BM[x1][y1]=CO_BOM;
			i++;
		}
	}
	for (int i=0;i<x;i++)
		for (int j=0;j<y;j++)
		{
			int dem=0;
			if (BM[i][j]==O_TRONG)
			{
				if (BM[i-1][j]==9) dem++;
				if (BM[i][j-1]==9) dem++;
				if (BM[i-1][j-1]==9) dem++;
				if (BM[i+1][j]==9) dem++;
				if (BM[i][j+1]==9) dem++;
				if (BM[i+1][j+1]==9) dem++;
				if (BM[i+1][j-1]==9) dem++;
				if (BM[i-1][j+1]==9) dem++;
				BM[i][j]=dem;
			}
		}

}
void xuatbm()
{
	gotoxy(toadox,toadoy);
	for(int i=0;i<Hang;i++)
	{
		for(int j=0;j<Cot;j++)
		{
			if((i+j)%2!=0) 
				SetBGColor(XAM_SANG);
			else
				SetBGColor(XAM_TRO);
			if(BC[i][j]==DA_MO)
			{
				if(BM[i][j]!=O_TRONG)
				{
					SetBGColor(LAM_SANG);
					printf("%d",BM[i][j]);
				}
				else
				{
			
					SetBGColor(DO_SANG);
					printf(" ",BM[i][j]);
				}
			}
			if(BC[i][j]==CHUA_MO) 
				printf(" ");
			if(BC[i][j]==DANH_DAU)
				printf("C");
			if(BC[i][j]==NGHI_NGO)
				printf("?");
			printf(" ");
		}
		gotoxy(toadox,toadoy+i+1);
	}
	SetBGColor(DEN);
}
void xuatbm2()
{
	SetBGColor(LAM_SANG);
	gotoxy(toadox,toadoy);
	for(int i=0;i<Hang;i++)
	{
		for(int j=0;j<Cot;j++)
		{
			if (BM[i][j]==CO_BOM) printf("B");
			else printf("%d",BM[i][j]);
			printf(" ");
		}
		gotoxy(toadox,toadoy+i+1);
	}
	SetBGColor(DEN);
}
void xuatSoBom()
{
	drawBoard(1,6,15,8,VANG,"So Bom",LUC_SANG);
	gotoxy(7,7); printf("     ");
	gotoxy(7,7); printf("%d",SoBom);
}
void Save()
{
	luuNguoiChoi();
	FILE *f=fopen("LastGame.txt","w");
	fprintf(f,"%d %d %d %d %d %d\n",Hang,Cot,Bom,SoOConLai,SoBom,Time());
	for(int i=0;i<Hang;i++)
	{
		for(int j=0;j<Cot;j++)
		{
			fprintf(f,"%d ",BC[i][j]);
		}
		fprintf(f,"\n");
	}
	for(int i=0;i<Hang;i++)
	{
		for(int j=0;j<Cot;j++)
		{
			fprintf(f,"%d ",BM[i][j]);
		}
		fprintf(f,"\n");
	}
	fclose(f);
	// Hang Cot Bom 
	// BC
	// BM
}
int Load(int &Y,int &X,int &B)
{
	int i,j,t;
	ganEndGame(FALSE);
	FILE *f=fopen("LastGame.txt","r");
	if(f==NULL) 
		return 0;
	fscanf(f,"%d %d %d %d %d %d",&Hang,&Cot,&Bom,&SoOConLai,&SoBom,&t);
	for ( i=0;i<Hang;i++)
		for( j=0;j<Cot;j++)
			fscanf(f,"%d",&BC[i][j]);
	for ( i=0;i<Hang;i++)
		for( j=0;j<Cot;j++)
			fscanf(f,"%d",&BM[i][j]);
	fclose(f);
	layThongTin();
	ganTime(t);
	Y=Hang; X=Cot; B=Bom;
	toadox=40-Cot;
	toadoy=18-Hang/2;
	return 1;
}
void Mo(int x,int y)
{

	if (EndGame() || BC[y][x]==DA_MO || BC[y][x]==DANH_DAU) return;
	if(BM[y][x]==O_TRONG) 
	{
		loang(x,y);
		xuatbm();
	}
	if(BM[y][x]!=CO_BOM && BC[y][x]!=DA_MO) 
	{
		BC[y][x]=DA_MO;
		SoOConLai--;
	}
	if(BM[y][x]==CO_BOM) GAMEOVER();
	if (SoOConLai==Bom) WIN();
}
void DanhDau(int x,int y)
{
	switch(BC[y][x])
	{
	case CHUA_MO: SoBom--;BC[y][x]=DANH_DAU;xuatSoBom();break;
	case DA_MO: break;
	case DANH_DAU: SoBom++;BC[y][x]=NGHI_NGO;break;
	case NGHI_NGO: BC[y][x]=CHUA_MO;break;
	}
}
void lamnoi(int x,int y)
{
	SetBGColor(LAM);
	gotoxy(x,y);
	chuyendoi(x);y=y-toadoy;
	switch(BC[y][x])
	{
	case O_TRONG : printf("  ");break;
	case DA_MO : printf("%d ",BM[y][x]);break;
	case DANH_DAU : printf("C ");break;
	case NGHI_NGO : printf("? ");break;
	}
	SetBGColor(DEN);
}
void Mo8(int x,int y)
{
	if (x!=0) Mo(x-1,y);
	if (x+1!=Cot) Mo(x+1,y);
	if (y!=0) Mo(x,y-1);
	if (y+1!=Hang) Mo(x,y+1);
	if(x!=0 && y!=0) Mo(x-1,y-1);
	if(x+1!=Cot && y!=0) Mo(x+1,y-1);
	if(x!=0 && y+1!=Hang) Mo(x-1,y+1);
	if(x+1!=Cot && y+1!=Hang) Mo(x+1,y+1);
}
void WIN()
{
	ganEndGame(TRUE);
	DeleteFile("LastGame.txt");
	xuatbm2();
	for(int i=0;i<30;i++)
	{
		textcolor(i);
		gotoxy(65,23);
		printf("YOU WIN!!!");
		Sleep(30);
	}
	PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME);
	luuThongTin(((float)Bom/(float)(Hang*Cot))*20000/Time());
	textcolor(TRANG);
}
void GAMEOVER()
{
	ganEndGame(TRUE);
	DeleteFile("LastGame.txt");
	xuatbm2();
	PlaySound(TEXT("bom.wav"), NULL, SND_FILENAME);
	for(int i=0;i<30;i++)
	{
		textcolor(i);
		gotoxy(65,23);
		printf("GAME OVER!!!");
		Sleep(30);
	}
	luuThongTin(0);
	textcolor(TRANG);
}
void lamnoi8(int x,int y)
{
	if (x!=toadox) lamnoi(x-2,y);
	if (x+2!=Cot*2+toadox) lamnoi(x+2,y);
	if (y!=toadoy) lamnoi(x,y-1);
	if (y+1!=Hang+toadoy) lamnoi(x,y+1);
	if(x!=toadox && y!=toadoy) lamnoi(x-2,y-1);
	if(x+2!=Cot*2+toadox && y!=toadoy) lamnoi(x+2,y-1);
	if(x!=toadox && y+1!=Hang+toadoy) lamnoi(x-2,y+1);
	if(x+2!=Cot*2+toadox  && y+1!=Hang+toadoy) lamnoi(x+2,y+1);
}
bool DuCo(int x,int y)
{

	if(BC[y][x]!=DA_MO) return FALSE;
	Co=BM[y][x];
	if (x!=0) kiemtra(x-1,y);
	if (x+1!=Cot) kiemtra(x+1,y);
	if (y!=0) kiemtra(x,y-1);
	if (y+1!=Hang) kiemtra(x,y+1);
	if(x!=0 && y!=0) kiemtra(x-1,y-1);
	if(x+1!=Cot && y!=0) kiemtra(x+1,y-1);
	if(x!=0 && y+1!=Hang) kiemtra(x-1,y+1);
	if(x+1!=Cot && y+1!=Hang) kiemtra(x+1,y+1);
	if(Co==0) return TRUE;
	else return FALSE;
}
void kiemtra(int x,int y)
{
	if(BC[y][x]==DANH_DAU) Co--;
}
void chuyendoi(int &x)
{
	x=(x-toadox)/2;
}
void xoalamnoi(int x,int y)
{
	gotoxy(x,y);
	chuyendoi(x);y=y-toadoy;
	if((x+y)%2!=0) 
		SetBGColor(XAM_SANG);
	else
		SetBGColor(XAM_TRO);
	switch(BC[y][x])
	{
	case O_TRONG : printf("  ");break;
	case DA_MO : 
				if(BM[y][x]==0) 
				{
					SetBGColor(DO_SANG);
					printf("  ");
				}
				else
				{
					SetBGColor(LAM_SANG);
					printf("%d ",BM[y][x]);
				}
				break;
	case DANH_DAU : printf("C ");break;
	case NGHI_NGO : printf("? ");break;
	}
	SetBGColor(DEN);
}
void xoalamnoi8(int x,int y)
{

	if (x!=toadox) xoalamnoi(x-2,y);
	if (x+2!=Cot*2+toadox) xoalamnoi(x+2,y);
	if (y!=toadoy) xoalamnoi(x,y-1);
	if (y+1!=Hang+toadoy) xoalamnoi(x,y+1);
	if(x!=toadox && y!=toadoy) xoalamnoi(x-2,y-1);
	if(x+2!=Cot*2+toadox && y!=toadoy) xoalamnoi(x+2,y-1);
	if(x!=toadox && y+1!=Hang+toadoy) xoalamnoi(x-2,y+1);
	if(x+2!=Cot*2+toadox  && y+1!=Hang+toadoy) xoalamnoi(x+2,y+1);
	xoalamnoi(x,y);
}