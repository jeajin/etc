#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <list>

using namespace std;
#define MAX 2
////////////////////////////////////////////////////
void gotoxy(int x, int y);
//////////////////////////////////////////////////

class Reservation
{
protected:
	int place[40]; // �¼� ǥ��
	int able ; // ���� �¼��� ����

public:
	Reservation() // ����Ʈ ������
	{
		able=40; // ���� �¼��� 0 ���� �ʱ�ȭ
		for(int i=0 ; i<40 ; i++)
			place[i] =0; // �¼��� ������(0)���� �ʱ�ȭ
	}
	Reservation(int able_num)
	{
		able = able_num ;
		for(int i=0 ; i<able ; i++)
			place[i] =0; // �¼��� ������(0)���� �ʱ�ȭ
	}
	~Reservation() // �Ҹ���  
	{
		system("cls");
		gotoxy(20,5);
		cout << "�̿��� �ּż� �����մϴ�.";
		gotoxy(20,6);
	}
	int remain() ; // �����ִ� �¼� ���
	void ticket(const char l ,int r); // �¼��� �����ϴ� �Լ�
	virtual void place_situation(int x, int y); // �����Լ�
	int USE(char l, int r); // �ش� �¼��� ��������� Ȯ��
};
class VIP_Reservation : public Reservation
{
protected:
	int coupon;
public:
	VIP_Reservation()
	{
		coupon = rand()%3+1; 
		coupon = coupon*10; // 10 20 30% �������� ����

		for(int i=0 ; i<40 ; i++)
			place[i] =0; // �¼��� ������(0)���� �ʱ�ȭ

		for(int j=0 ; j<4 ; j++)
		{
				place[23+j] = 9; // �����ڸ�(9) ǥ��
				place[33+j] = 9;
		}
	}
	void discount();
	void place_situation(int x, int y); // (+���)�����ڸ� ǥ��
};