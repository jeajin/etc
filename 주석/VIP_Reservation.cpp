#include "R.h"

void VIP_Reservation::discount() // 랜덤으로 쿠폰 할인 적용
{
	cout <<"(VIP)"<< coupon <<"% 할인된 가격으로 적용됩니다.";
}
void VIP_Reservation::place_situation(int x, int y) // 동적바인딩
{
	char alpa = 65;
	int j=0;
	gotoxy(x+5,y);
	cout << "S C R E E N";
	y++;
	gotoxy(x,y);
	for(int i=0;i<40;i++)
	{
		if(i%10 == 0)
		{
			if(j==0)
				cout << " 1 2 3 4 5 6 7 8 9 10";
			y++;
			gotoxy(x,y);
			cout << alpa;
			alpa++;
			j++;
		}
		if(place[i]==0) // 사용 안함(0)은 □ 으로 표시
			cout << "□";
		else if (place[i] ==1) // 사용중(1) 은 ■ 으로 표시
			cout << "■";
		else if (place[i] == 9) // 좋은자리는 ☆ 으로 표시
			cout << "☆";
	}
	gotoxy(x,y+2);
}