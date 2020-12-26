#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "game.h"

#pragma warning(disable:4996)

void gt(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
ddd()
{
	
	gt(3, 0);
	printf("Enter나 space를 누르시면 실행이 됨니다.");
	gt(3, 2);
	printf(" 1번 보물찾기_____________김민준 ");
	gt(3, 4);
	printf(" 2번 invader _____________김인겸 ");
	gt(3, 6);
	printf(" 3번 슈퍼마리오___________김재진 ");
	gt(3, 8);
	printf(" 4번 하늘청소게임_________김정환");
	gt(3, 10);
	printf(" 5번 야구게임_____________김호용 ");
	gt(3, 12);
	printf(" 6번 기억력 길찾기 게임___박진호");
	gt(3, 14);
	printf(" 7번 오투젬_______________백승민");
	gt(3, 16);
	printf(" 8번 보물찾기___________선우성웅");
	gt(3, 18);
	printf(" 9번 뱀게임_______________신은규 ");
	gt(3, 20);
	printf("10번 슈팅게임_____________안성원");
	gt(3, 22);
	printf("11번 무제_________________안효정 ");
	gt(3, 24);
	printf("12번 loop slot____________양민하");
	gt(3, 26);
	printf("13번 보물찾기_____________오승헌");
	gt(3, 28);
	printf("14번 총알로공중벽경파게임_이상민 ");
	gt(3, 30);
	printf("15번 오목_________________이주상");
	gt(3, 32);
	printf("16번 무제_________________임권일");
	gt(3, 34);
	printf("17번 길찾기_______________최룡 ");
	gt(3, 36);
	printf("18번 똥피하기_____________윤대은 ");
	gt(3, 38);
	printf("19번 무제_________________홍성재");
}
int main()
{
	int i = 2, kb = 0;
	ddd();
	system("mode con cols=80 lines=41");
	gt(2, 2);
	printf("*");
	while(1)
	{
		
		ddd();
		kb = getch();
			if (kb == 72)
			{
				gt(2, i);
				printf(" ");
				i -= 2;
			}
			else if (kb == 80)
			{
				gt(2, i);
				printf(" ");
				i += 2;
			}
			if (i > 38)
			{
				i = i % 38 ;
			}
			else if (i < 2)
			{
				i += 38;
			}
			
		gt(2, i);
		printf("*");
		if (kb == 32||kb==13)
		{
			system("cls");
			if (i == 2)
			{
				main1();
			}
			else if (i ==4 )
			{
				main2();
			}
			else if (i ==6 )
			{
				main3();
			}
			else if (i ==8 )
			{
				main4();
			}
			else if (i == 10)
			{
				main5();
			}
			else if (i ==12 )
			{
				main6();
			}
			else if (i == 14)
			{
				main7();
			}
			else if (i ==16 )
			{
				main8();
			}
			else if (i == 18)
			{
				main9(); 
			}
			else if (i ==20 )
			{
				main10();
			}
			else if (i == 22)
			{
				main11();
			}
			else if (i == 24)
			{
				main12();
			}
			else if (i == 26)
			{
				main13();
			}
			else if (i == 28)
			{
				main14();
			}
			else if (i == 30)
			{
				main15();
			}
			else if (i == 32)
			{
				main16();
			}
			else if (i == 34)
			{
				main17();
			}
			else if (i ==36 )
			{
				main18();
			}
			else if (i == 38)
			{
				main19();
			}
			system("mode con cols=80 lines=41");
			system("cls");
		}
	}
}
