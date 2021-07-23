#include "R.h"

void Reservation::ticket(const char l,int r) // 해당 좌석을 예매하는 함수
{
	r--; // 배열은 0부터 시작이므로 -1 해준다.

	if(l == 'A') // A는 0부터 시작
		r;
	else if(l == 'B') // B줄은 10부터 시작
		r+=10;
	else if(l == 'C') // C줄은 20부터 시작
		r+=20;
	else if( l =='D') // D줄은 30부터 시작
		r+=30;
	else // A~D 범위가 아닐경우 오류 메세지
		cout << "오류" ; // 출력

	place[r] = 1; // 해당자리 사용(1)으로 표시
	able--; // 현재 좌석 갯수 -1
}
int Reservation::remain() // 현재 남아있는 좌석 갯수를 리턴하는 함수
{
	return able; // 남은 좌석갯수 리턴
}
void Reservation::place_situation(int x, int y) // 현재 좌석 상황 표시하는 함수
{
	char alpa = 65; // A~D 문자를 나타낼 변수
	int j=0;
	gotoxy(x+5,y); // 커서 이동
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
		if(place[i]==0) // 사용 안함(0) 자리는 □ 으로 표시
			cout << "□";
		else if (place[i] ==1) // 사용함(1) 자리는 ■ 으로 표시
			cout << "■";
	}

	gotoxy(x,y+2);
}
int Reservation::USE(char l, int r) // 해당자리가 사용중인지 리턴해주는 함수
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

	return place[r]; // 해당 자리 상태 출력 (사용함 1, 사용안함 0) 
}