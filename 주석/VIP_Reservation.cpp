#include "R.h"

void VIP_Reservation::discount() // �������� ���� ���� ����
{
	cout <<"(VIP)"<< coupon <<"% ���ε� �������� ����˴ϴ�.";
}
void VIP_Reservation::place_situation(int x, int y) // �������ε�
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
		if(place[i]==0) // ��� ����(0)�� �� ���� ǥ��
			cout << "��";
		else if (place[i] ==1) // �����(1) �� �� ���� ǥ��
			cout << "��";
		else if (place[i] == 9) // �����ڸ��� �� ���� ǥ��
			cout << "��";
	}
	gotoxy(x,y+2);
}