#include "R.h"

void Reservation::ticket(const char l,int r) // �ش� �¼��� �����ϴ� �Լ�
{
	r--; // �迭�� 0���� �����̹Ƿ� -1 ���ش�.

	if(l == 'A') // A�� 0���� ����
		r;
	else if(l == 'B') // B���� 10���� ����
		r+=10;
	else if(l == 'C') // C���� 20���� ����
		r+=20;
	else if( l =='D') // D���� 30���� ����
		r+=30;
	else // A~D ������ �ƴҰ�� ���� �޼���
		cout << "����" ; // ���

	place[r] = 1; // �ش��ڸ� ���(1)���� ǥ��
	able--; // ���� �¼� ���� -1
}
int Reservation::remain() // ���� �����ִ� �¼� ������ �����ϴ� �Լ�
{
	return able; // ���� �¼����� ����
}
void Reservation::place_situation(int x, int y) // ���� �¼� ��Ȳ ǥ���ϴ� �Լ�
{
	char alpa = 65; // A~D ���ڸ� ��Ÿ�� ����
	int j=0;
	gotoxy(x+5,y); // Ŀ�� �̵�
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
		if(place[i]==0) // ��� ����(0) �ڸ��� �� ���� ǥ��
			cout << "��";
		else if (place[i] ==1) // �����(1) �ڸ��� �� ���� ǥ��
			cout << "��";
	}

	gotoxy(x,y+2);
}
int Reservation::USE(char l, int r) // �ش��ڸ��� ��������� �������ִ� �Լ�
{	
	r--;

	if(l == 'A')
		r;
	else if(l == 'B')
		r+=10;
	else if(l == 'C')
		r+=20;
	else if( l =='D')
		r+=30;

	return place[r]; // �ش� �ڸ� ���� ��� (����� 1, ������ 0) 
}