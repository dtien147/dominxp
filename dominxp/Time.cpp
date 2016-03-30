#include "Time.h"
int t=0;
void thoigian(int ms)
{
	while (!EndGame())
	{
		Sleep(1000-ms);
		PAUSE();
		Sleep(ms);
		{
			textcolor(TRANG);
			gotoxy(72,3);
			printf("%d",t);
		}
		t++;
		RESUME();
	}
}
void ganTime(int a)
{
	t=a;
}
int Time()
{
	return t;
}