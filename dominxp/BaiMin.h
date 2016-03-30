#pragma comment(lib,"winmm.lib")
#include "Player.h"
#include "Time.h"
#define CO_BOM 9
#define NGHI_NGO 4
#define DANH_DAU 3
#define DA_MO 2
#define O_TRONG 0
#define CHUA_MO 0
void loang(int x, int y);					//Mo nhung o xung quanh o so 0
void khoitao(int BOOM,int x,int y);			//Tao bai min voi y hang, x cot va BOOM bom
void Save();								//Luu bang chon va bai min cua nguoi choi
int Load(int &Y,int &X,int &B);				//Lay bang chon va bai min cua nguoi choi
void xuatbm();								//Xuat bai min voi nhung o nguoi choi da chon
void xuatbm2();								//Xuat toan bo cac o bai min
void xuatSoBom();							//Xuat so bom
void DanhDau(int x,int y);					//Cam co vao o o hang y va cot x
void Mo(int x,int y);						//Mo o o hang y va cot x
void lamnoi(int x,int y);					//Lam noi o co toa do x,y
void Mo8(int x,int y);						//Mo nhung o xung quanh o o hang y va cot x
void WIN();									//In ra dong chu Win va bat am thanh chien thang, luu thanh tich cua nguoi choi
void GAMEOVER();							//In ra dong chu "Game Over" va am thanh thua cuoc							
void lamnoi8(int x,int y);					//Lam noi nhung o xung quanh o o hang y cot x
bool DuCo(int x,int y);						//Kiem tra xem da du so o duoc danh dau xung quanh o o hang y cot x
void kiemtra(int x,int y);					//Neu o o hang y va cot x duoc danh dau la co bom thi giam so o can danh dau di 1
void chuyendoi(int &x);						//Chuyen doi toa do x tren man hinh sang toa do cot tren bang
void xoalamnoi(int x,int y);				//Xoa lam noi 1 o
void xoalamnoi8(int x,int y);				//Mo nhung o xung quanh o o hang y va cot x