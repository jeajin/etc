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
	int place[40]; // 좌석 표시
	int able ; // 남은 좌석의 갯수

public:
	Reservation() // 디폴트 생성자
	{
		able=40; // 남은 좌석을 0 으로 초기화
		for(int i=0 ; i<40 ; i++)
			place[i] =0; // 좌석을 사용안함(0)으로 초기화
	}
	Reservation(int able_num)
	{
		able = able_num ;
		for(int i=0 ; i<able ; i++)
			place[i] =0; // 좌석을 사용안함(0)으로 초기화
	}
	~Reservation() // 소멸자  
	{
		system("cls");
		gotoxy(20,5);
		cout << "이용해 주셔서 감사합니다.";
		gotoxy(20,6);
	}
	int remain() ; // 남아있는 좌석 출력
	void ticket(const char l ,int r); // 좌석을 예매하는 함수
	virtual void place_situation(int x, int y); // 가상함수
	int USE(char l, int r); // 해당 좌석이 사용중인지 확인
};
class VIP_Reservation : public Reservation
{
protected:
	int coupon;
public:
	VIP_Reservation()
	{
		coupon = rand()%3+1; 
		coupon = coupon*10; // 10 20 30% 랜덤으로 할인

		for(int i=0 ; i<40 ; i++)
			place[i] =0; // 좌석을 사용안함(0)으로 초기화

		for(int j=0 ; j<4 ; j++)
		{
				place[23+j] = 9; // 좋은자리(9) 표시
				place[33+j] = 9;
		}
	}
	void discount();
	void place_situation(int x, int y); // (+기능)좋은자리 표시
};