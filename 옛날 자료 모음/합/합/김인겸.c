
#define ESC 27
#define DefaultTimer 60 // 스테이지마다 부여되는 타이머
#define MaxBoss 15	// 최종 스테이지
#define BulletMax 200	// 초기 플레이어 총알 개수
#define BossDefaultDelay 320	// 보스의 초기 움직임 속도
#define DefaultEBFrame 150	// 보스 총알의 초기 움직임 속도
#define MaxEnemyBullet 7	// 화면에 출력되는 보스 총알의 개수
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "game.h"


int nStage = 1;	// 현재 스테이지
int PlayerX = 30; // 플레이어 좌표
int BulletX = -1, BulletY; // 총알 좌표
int BossHp = 1;	// 보스의 초기 HP
int BossX;	// 보스의 좌표
int HitBoss = 0;	// 보스 타격 횟수
int nBullet = BulletMax;	// 남은 총알의 개수
int BossDelay = BossDefaultDelay;	// 보스의 움직임 속도

clock_t StartTime, EndTime;	// Timer를 구하기 위한 변수
double PrintTime;	// Log창에 띄울 남은 timer
int OperateTime, NowTime;	// 보스의 움직임 속도를 제한하기 위한 timer

int EnemyBulletF = DefaultEBFrame;	// 보스 총알의 속도

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void gotoxy2(int x, int y)	// 좌표 값 이동 함수
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcursortype(CURSOR_TYPE c)	// 콘솔의 커너모양을 변경하는 함수
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void DrawInfo()	// 조작 방법 및 실시간 정보를 출력
{
	gotoxy2(56, 3);
	printf("┌──────┐");
	gotoxy2(56, 4);
	printf("│  Log Info  │");
	gotoxy2(56, 5);
	printf("└──────┘");

	gotoxy2(56, 7);
	printf("보스 체력 : ");
	gotoxy2(56, 8);
	printf("보스 격퇴 수 : ");
	gotoxy2(56, 9);
	printf("남은 총알 수 : ");
	gotoxy2(56, 10);
	printf("남은 시간 : ");

	gotoxy2(56, 12);
	printf("┌──────┐");
	gotoxy2(56, 13);
	printf("│  조작방법  │");
	gotoxy2(56, 14);
	printf("└──────┘");

	gotoxy2(56, 16);
	printf("미사일 발사 : space");
	gotoxy2(56, 17);
	printf("방향키 : ← , →");
	gotoxy2(56, 18);
	printf("게임 종료 : ESC");

	gotoxy2(56, 20);
	printf("┌──────┐");
	gotoxy2(56, 21);
	printf("│  게임오버  │");
	gotoxy2(56, 22);
	printf("└──────┘");

	gotoxy2(56, 24);
	printf("Timer가 0이 될 시");
	gotoxy2(56, 25);
	printf("총알을 모두 소진할 시");
}




struct {
	int TFcheck;	// 보스 총알의 존재 여부
	int x, y;	// 보스 총알의 좌표
	int nFrame;	// 보스 총알의 속도를 저장할 변수

} EnemyBullet[MaxEnemyBullet];	// 구조체 배열로 개수를 설정



void EraseBullet()	// 총알 지우기
{
	gotoxy2(BulletX, BulletY);
	printf(" ");
}

void DrawBullet()	// 총알 그리기
{
	gotoxy2(BulletX, BulletY);
	printf("*");
}

void ErasePlayer()	// 플레이어 지우기
{
	gotoxy2(PlayerX - 2, 29);
	printf("      ");
}

void DrawPlayer()	// 플레이어 그리기
{
	gotoxy2(PlayerX - 2, 29);
	printf("≪Δ≫");
}


void DrawEnemyBullet(int j)	// 보스 총알 그리기
{
	gotoxy2(EnemyBullet[j].x, EnemyBullet[j].y);
	printf("│");
}

void EraseEnemyBullet(int j)	// 보스 총알 지우기
{
	gotoxy2(EnemyBullet[j].x, EnemyBullet[j].y);
	printf(" ");
}

void EnemyBulletCheck()	// 화면에 출력되는 보스의 총알 확인
{
	int j;

	if (PrintTime == 60)	// stage가 초기화 될때, 총알들 초기화
	{
		for (j = 0; j < MaxEnemyBullet; j++)
		{
			EnemyBullet[j].TFcheck = 0;
		}
	}

	// 만일 정해진 총알 구조체 배열이 화면에 존재할 경우 해당 사항을 스킵함
	for (j = 0; j < MaxEnemyBullet&&EnemyBullet[j].TFcheck == 1; j++);

	// 존재하지 않으면 보스보다 한 칸 아래에서 발사하게 하며, 
	// 총알의 존재값인 TFcheck를 1로 설정
	if (j != MaxEnemyBullet)
	{
		EraseEnemyBullet(j);
		EnemyBullet[j].x = BossX;
		EnemyBullet[j].y = 5;
		// 총알의 발사를 랜덤한 시간으로 설정
		EnemyBullet[j].nFrame = EnemyBulletF*(rand() % 10 + 1);
		EnemyBullet[j].TFcheck = 1;
	}
}


void MoveEnemyBullet()	// 보스의 총알 이동 함수
{
	int i;

	for (i = 0; i < MaxEnemyBullet; i++)
	{
		if (EnemyBullet[i].TFcheck == 0)	// 존재하지 않으면 스킵
			continue;
		if (EnemyBullet[i].nFrame <= 0)
		{
			// 총알이 존재할 시에, 이동속도를 초기화 한후, 좌표를 수정
			EnemyBullet[i].nFrame = EnemyBulletF;
			EraseEnemyBullet(i);

			if (EnemyBullet[i].y > 28)
			{
				// 바닥과 충돌시 총알을 지움
				EnemyBullet[i].TFcheck = 0;
			}
			else
			{
				EnemyBullet[i].y++;
				DrawEnemyBullet(i);
			}

		}
		// 총알이 움직이는 속도를 조정
		EnemyBullet[i].nFrame -= 30;
	}
}


void DrawBoss()	// 보스의 화면 출력 및 움직임 조종 함수
{
	int x = (rand() % (2));
	gotoxy2(BossX - 2, 4);
	printf("      ");

	if (x % 2 == 1)
	{
		BossX += 2;
	}
	else
	{
		BossX -= 2;
	}

	if (BossX <= 3)
		BossX = 4;
	else if (BossX >= 47)
		BossX = 46;


	gotoxy2(BossX - 2, 4);
	printf("≤∀≥");

	Sleep(10);

	EnemyBulletCheck();	// 화면에 출력되는 보스의 총알을 확인

}

void Delay(int i)	// 보스의 움직임을 제한
{
	if (NowTime - OperateTime>i)
	{
		OperateTime = clock();
		DrawBoss();
	}
}

void BossCrash()	// 보스와 총알의 충돌값을 계산
{
	if ((BossX == BulletX&&BulletY == 4) ||
		(BossX == BulletX + 1 && BulletY == 4) ||
		(BossX == BulletX - 1 && BulletY == 4))
	{
		gotoxy2(BulletX - 2, BulletY);
		printf("보스힛");
		Sleep(50);
		gotoxy2(BulletX - 2, BulletY);
		printf("      ");
		BulletX = -1;	// 충돌시에 총알을 없앰
		HitBoss += 1;	// 충돌시에 보스 타격 횟수 증가
	}

}




void Map()	// 플레이 화면과 Log창 화면의 경계선을 그음
{
	int i;
	StartTime = clock();	// Map을 생성함과 동시에 Timer 작동

	for (i = 0; i < 32; i++)
	{
		gotoxy2(52, i);
		printf("│");
	}

	for (i = 0; i < 52; i += 2)
	{
		gotoxy2(i, 32);
		printf("─");
	}

	gotoxy2(52, 32);
	printf("┘");
}

void Stage()	// Stage 화면의 네모 박스를 생성 및 플레이 진행 여부 확인
{
	int i;
	char ch;

	gotoxy2(10, 4);
	printf("┌");

	for (i = 10; i < 50; i += 2)
	{
		printf("─");
	}

	gotoxy2(50, 4);
	printf("┐");

	for (i = 5; i < 15; i++)
	{
		gotoxy2(50, i);
		printf("│");
	}

	gotoxy2(50, 15);
	printf("┘");

	for (i = 2; i < 40; i += 2)
	{
		gotoxy2(50 - i, 15);
		printf("─");
	}

	gotoxy2(10, 15);
	printf("└");

	for (i = 1; i < 11; i++)
	{
		gotoxy2(10, 15 - i);
		printf("│");
	}

	gotoxy2(24, 9);
	printf("%d번째 스테이지\n", nStage);	// 플레이어의 해당 스테이지를 출력
	gotoxy2(12, 17);
	printf("플레이를 원하시면 y, 아니면 n을 입력하세요\n");


	while (1)	// 플레이어의 진행 희망 여부를 확인하며, 
				// 무조건 'y'나 'n'만을 입력하게끔 유도
	{
		ch = _getch();

		if (ch == 'y')
		{
			fflush(stdin);
			break;
		}

		else if (ch == 'n')
		{
			fflush(stdin);
			nStage = 17;
			break;
		}

		else
		{
			fflush(stdin);
		}
	}
}

void RealLog()	// 실시간 정보를 출력시킴
{

	EndTime = clock();
	// 초 단위로 형변환
	PrintTime = (StartTime - EndTime) / (CLOCKS_PER_SEC)+DefaultTimer;

	gotoxy2(71, 7);
	printf("%d", BossHp);	// 남은 보스의 HP
	gotoxy2(71, 8);
	printf("%d", HitBoss);	// 보스 타격 횟수
	if (nBullet == 99)	// 총알이 99개가 됐을때, 100으로 출력되던 숫자 0을 지움
	{
		gotoxy2(71, 9);
		printf("   ");
	}
	gotoxy2(71, 9);
	printf("%d", nBullet);	// 남은 총알
	gotoxy2(71, 10);
	printf("%2.0f", PrintTime);	// 남은 시간


}


void PlayerBullet()	// 총알의 움직임을 제한
{
	if (BulletX != -1)
	{
		EraseBullet();		// 총알을 지움
		if (BulletY == 0)	// 총알이 최상단 좌표와 충돌시 트리거
		{
			BulletX = -1;
		}
		else				// 총알이 위로 올라가는 걸 표현 
		{
			BulletY--;		// 총알의 y축 좌표를 수정
			DrawBullet();	// 총알을 그림
		}
	}
}

void PlayerMove()	// 플레이어의 움직임을 담당
{
	char cha;

	if (GetAsyncKeyState(VK_LEFT) < 0 && PlayerX > 3)	// 왼쪽키를 입력 받을때, 
														// 왼쪽 끝과 충돌하지 않았다면
														// 왼쪽으로 이동시킴
	{
		ErasePlayer();
		PlayerX--;
		DrawPlayer();
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0 && PlayerX < 47)	// 오른쪽키를 입력 받을때, 
																// 오른쪽 끝과 충돌하지 않았다면
																// 오른쪽으로 이동시킴
	{
		ErasePlayer();
		PlayerX++;
		DrawPlayer();
	}

	if (_kbhit())	// 미사일 발사 트리거, 버퍼에 값이 있는지를 확인
	{
		fflush(stdin);
		cha = _getch();
		switch (cha)
		{
		case ' ':	// 스페이스 키로 트리거 작동
			if (BulletX == -1)	// 총알을 하나만 발사하게함, 존재 여부를 확인
			{
				BulletX = PlayerX;
				BulletY = 28;
				nBullet -= 1;
			}
			break;

		case ESC:	// 게임 종료를 위한 키 ESC를 입력
			gotoxy2(12, 34);
			exit(0);
		}
	}
}

void PlayerCrash()	// 보스의 총알과 플레이어의 충돌값 검사
{
	int i;

	for (i = 0; i < MaxEnemyBullet; i++)
	{
		if (EnemyBullet[i].TFcheck == 0)	// 존재하지 않으면 continue
			continue;
		// 존재하며, 좌표가 일치할 경우
		if ((EnemyBullet[i].x == PlayerX&&EnemyBullet[i].y == 29) ||
			(EnemyBullet[i].x == PlayerX + 1 && EnemyBullet[i].y == 29))
		{
			gotoxy2(PlayerX - 2, 29);
			printf("기체 파괴");
			Sleep(1000);
			nStage = MaxBoss + 2;	// 게임 종료 트리거 작동
		}
	}
}



void GameOver()	// 게임 자동 종료
{
	if (nBullet <= 0)	// 총알을 모두 소진시
	{
		nStage = MaxBoss + 2;
	}
	else if (PrintTime <= 0)	// Timer가 0 이 될 시
	{
		nStage = MaxBoss + 2;
	}
}



int main2(void)
{	
	setcursortype(NOCURSOR);	// 콘솔의 커서를 없앰
	system("mode con: cols=80 lines=36");	// 콘솔 사이즈를 80*36으로 변경
	OperateTime = clock();	// 보스 등장 기준시간 초기화
	srand((unsigned)time(NULL));	// 랜덤함수를 위한 srand


	while (1)	// 무한루프
	{
		NowTime = clock();	// 보스 등장 비교값 설정

		if (nStage >= MaxBoss + 2)	// 게임이 종료되는 조건
		{
			system("cls");
			gotoxy2(12, 17);
			printf("게임을 종료합니다.\n");
			gotoxy2(12, 18);
			Sleep(1000);
			return -1;
		}

		else if (nStage == MaxBoss + 1)	// 스테이지를 모두 클리어 할때 작동
		{
			gotoxy2(12, 17);
			printf("스테이지를 모두 클리어하였습니다.\n");
			break;
		}

		else if (nStage < MaxBoss + 1)	// 스테이지 진행 가능 조건
		{
			if (HitBoss == 0 && nStage == BossHp)	// 보스의 체력이 0이 될시에 
													// 다음 스테이지로 진행
			{
				system("cls");
				Sleep(500);
				Stage();	// 스테이지 화면을 출력
				nStage++;
				system("cls");
				Sleep(1000);
				Map();	// 플레이 화면을 출력

				do {
					BossX = (rand() % (46));
				} while (BossX <= 3);	// 보스를 랜덤한 x축 위치에 출현시킴

				DrawInfo();	// 조작법을 출력
			}

			RealLog();	// 실시간 정보 출력
			PlayerMove();	// 플레이어 움직임 확인
			PlayerBullet();	// 총알 확인
			Delay(BossDelay);	// 보스 움직임 확인
			MoveEnemyBullet();	// 보스 총알 이동

			BossCrash();	// 총알과 보스의 충돌값 확인
			PlayerCrash();	// 보스의 총알과 플레이의 충돌값 확인
			GameOver();		// 게임 종료 조건을 검사

			Sleep(20);
		}

		if (HitBoss == BossHp&&BossHp < MaxBoss)	// 보스의 HP와 타격 횟수가 일치할 시 
													// 다음 스테이지로 넘어가는 트리거
		{
			HitBoss = 0;
			BossHp++;
			BossDelay -= 20;	// 보스의 움직임 속도를 줄임(난이도 향상)
			EnemyBulletF -= 8; // 보스의 총알 속도를 줄임(난이도 향상)
		}
	}

	return 0;
}