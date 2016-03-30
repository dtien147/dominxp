#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#include "ManHinh.h"
struct Player
{
	char Ten[10];
	float Diem;
};
void NhapNguoiChoi();				//Nhap thong tin nguoi choi khi choi van moi
void luuThongTin(float Diem);		//luu thong tin nguoi choi de sap xep thanh tich
void layThongTin();					//Lay thong tin nguoi choi truoc tu file neu chon choi tiep
void xemNguoiChoiHienTai();			//Xem ten nguoi choi hien tai
void luuBangThanhTich();			//Luu bang thanh tich vao file
void sapxepNguoiChoi();				//Sap xep bang thanh tich dua vao diem cua nguoi choi
void layBangThanhTich();			//Lay bang thanh tich tu file
void taoBangThanhTich();			//Tao bang thanh tich neu chua co
bool coBangThanhTich();				//Kiem tra xem co file BangThanhTich.txt hay chua
void xemBangThanhTich();			//Xem bang thanh tich
void luuNguoiChoi();				//Luu nguoi choi hien tai vao file
#endif PLAYER_H