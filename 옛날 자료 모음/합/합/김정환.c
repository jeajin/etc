#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
#pragma warning(disable:4996)
void gotoxy4(int x, int y);
void nonc(void);
void roadmap(void);
void roadcloud(void);
void score4(void);
void mymisile(void);
void mypmisile(void);
void rain(void);
void prain(void);
void movement(char key);
void puser(void);
void clean(void);
void start4(void);
void quit(void);
void success(void);
void die(void);
int point = 0;//파괴한 구름 수 
int cloud[40] = { 1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0 };//적군 위치 
int count4 = 0;//몇발 쐈는지 체크 
int px = 31;	//플레이어 x 좌표
int py = 24;  //플레이어 y 좌표
int mybx = 0;//내 총알 x좌표 
int myby = 0;//내 총알 y좌표 
int ry = 5;//비 y좌표 
int over = 0;//죽었는지 여부 
int speed = 40;//게임 진행 속도 

void gotoxy4(int x, int y) {                         //좌표이동함수 
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void nonc(void) {                                     //커서 지우는 함수 
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);
}

void roadmap(void) {                               //맵띄우는 함수 
	int x, y;
	for (y = 1; y<26; y++) {
		for (x = 1; x<50; x += 2) {
			gotoxy4(1, y);
			printf("■");
			gotoxy4(49, y);
			printf("■");
			gotoxy4(x, 1);
			printf("■");
			gotoxy4(x, 25);
			printf("■");
		}
	}
}

void roadcloud(void) {                             //구름 띄우는 함수 
	int x;
	for (x = 5; x<45; x += 2) {
		gotoxy4(x, 4);
		printf("▣");
	}
}

void score4(void) {                                 //점수 띄우는 함수 
	gotoxy4(55, 4);
	printf("지운 구름 포인트 : %d", point);
	gotoxy4(55, 7);
	printf("미사일 발사 횟수 : %d", count4);
}
void mymisile(void) {            //나의 미사일 움직임 함수 
	myby--;
	if (myby == 3 && cloud[mybx - 5] == 1) {//충돌 검사
		cloud[mybx - 5] = 0;
		point += 10;
		gotoxy4(mybx, myby + 1);
		printf("  ");
		mybx = 0;
		myby = 0;
		speed--;
	}

	else if (myby<4) {		//충돌 검사
		gotoxy4(mybx, myby + 1);
		printf("  ");
		myby = 0;
	}
}

void mypmisile(void) {           //나의 미사일 출력 함수 
	if (myby>3) {
		gotoxy4(mybx, myby);
		printf("▲");
		gotoxy4(mybx, myby + 1);
		printf("  ");
	}
}

void rain(void) {             //비의 움직임 함수 
	int i;
	ry++;

	for (i = 0; i<40; i += 2) {
		if (ry == myby&&mybx == (i + 5)) {
			cloud[i] = 0;
		}
		if (ry == 24) {
			if (cloud[px - 5] == 1) { //비와 플레이어 충돌검사
				over = 1;
			}
			gotoxy4(i + 5, ry);
			printf("  ");
			ry = 6;
		}
	}
}

void prain(void) {            //비 출력 함수 
	int i;
	for (i = 0; i<40; i += 2) {
		if (cloud[i] == 1) {
			{	//구름 배열에 값이 있으면 비 출력
				gotoxy4(i + 5, ry);
				printf("＊"); }
			gotoxy4(i + 5, ry - 1);
			printf("  ");
		}

		else {				//값 없으면 공백 출력
			gotoxy4(i + 5, ry);
			printf("  ");
		}
	}
}

void movement(char key) {//키 받아서 행동  
	gotoxy4(px, py);
	printf("  ");
	switch (key) {
	case 75:		//왼쪽 방향키               
		px = px - 2;
		if (px<3)	//충돌 검사
			px = 3;
		break;
	case 77:		//오른쪽 방향키
		px = px + 2;
		if (px>47)	//충돌 검사
			px = 47;
		break;
	case 32:		//스페이스 바
		count4++;
		mybx = px;	//플레이어의 바로 위
		myby = py - 1;  //좌표값을 미사일 변수에 대입
		break;
	default:
		break;
	}
}

void puser(void) {                                     //유저 위치 출력 
	gotoxy4(px, py);
	printf("♠");
}

void clean(void) {
	int i;
	for (i = 5; i<45; i++) {
		gotoxy4(i, 23);
		printf("  ");
	}
}

void start4(void) {                                     //시작 화면 함수 
	roadmap();
	roadcloud();
	gotoxy4(7, 6);
	printf("오늘은 데이트 날!");
	gotoxy4(7, 8);
	printf("하지만 날씨가 흐립니다 ㅠ.ㅠ");
	gotoxy4(7, 10);
	printf("그녀가 깨어나기 전에,");
	gotoxy4(7, 12);
	printf("하늘을 청소하세요!");
	gotoxy4(7, 18);
	printf("아무 키를 입력하면 게임이 시작됩니다.");
	while (1) {
		if (kbhit())
			break;
	}
	system("cls");
}

void quit(void) {                                     //중지 화면 함수 
	system("cls");
	roadmap();
	gotoxy4(10, 13);
	printf("게임 종료! 최종 스코어 : %d\n\n", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

void success(void) {                                   //성공 화면 함수 
	system("cls");
	gotoxy4(32, 15);
	printf("어 머 나 !!!!");
	Sleep(1000);
	system("cls");
	roadmap();
	gotoxy4(7, 6);
	printf("하늘을 보세요!");
	gotoxy4(7, 8);
	printf("햇살이 따스합니다 ^___^");
	gotoxy4(7, 10);
	printf("그녀가 일어나기 전에 하늘을 청소했군요.");
	gotoxy4(7, 12);
	printf("데이트는 성공적일 것입니다!");
	gotoxy4(7, 18);
	printf("당신의 점수는 : %d점!", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

void die(void) {                             //죽음 화면 함수 
	system("cls");
	gotoxy4(32, 15);
	printf("아 이 고 !!!!");
	Sleep(1000);
	system("cls");
	roadmap();
	roadcloud();
	gotoxy4(7, 6);
	printf("오, 이런!");
	gotoxy4(7, 8);
	printf("비에 맞아 옷이 젖었군요...");
	gotoxy4(7, 10);
	printf("그녀를 만나기엔 무리입니다.");
	gotoxy4(7, 12);
	printf("데이트에 실패했습니다.");
	gotoxy4(7, 18);
	printf("당신의 점수는 : %d점!", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

int main4(void) {
	char key; //입력 키 
	system("mode con: cols=80 lines=32");
	nonc();          //커서 안보이게하기
	start4();	     //시작화면 띄우기
	roadmap();		 //맵 그리기
	roadcloud();	 //구름 그리기	

	do {
		if (kbhit())		//키가 눌렸는지 검사		
		{
			key = getch();
			movement(key);
		} //입력된 키값을 함수로

		else {
			puser();	//플레이어 위치 출력
			if (point >= 30 && point<200) {
				rain();		//비 한칸씩 증가
				prain();
			}	//비 출력
			mymisile();		//나의 미사일 한칸증가
			mypmisile();	//나의 미사일 출력
			clean();

			score4();
		}		//게임 종료 검사식
		if (point == 200)
			break;
		if (over == 1)
			break;
		Sleep(speed);	//게임 진행 속도 컨트롤 
	} while (key != 27);		//ESC키 받으면 종료

	if (point == 200)
		success();
	if (over == 1)			//각각 엔딩창 구분
		die();
	if (key == 27)
		quit();
	return 0;
}
