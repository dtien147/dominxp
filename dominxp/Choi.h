#include "ChuotvaPhim2.h"
#include "BaiMin.h"
#include "HighScores.h"
#define LAM_NOI 0
#define MO_O 1
#define DANH_DAU 2
#define XEM_O_XQ 3
#define MO_O_XQ 4
#define QUAY_LAI 5
#define SAVE 6
#define EXIT 7
void Choi(int Hang,int Cot,int Bom);										//Choi
bool KhongDuocVao(int x,int xmin, int xmax,int y,int ymin, int ymax);		//Kiem tra xem o toa do x,y co vuot ra khoi bai min chua																									