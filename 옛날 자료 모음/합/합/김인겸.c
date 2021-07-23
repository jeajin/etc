
#define ESC 27
#define DefaultTimer 60 // ������������ �ο��Ǵ� Ÿ�̸�
#define MaxBoss 15	// ���� ��������
#define BulletMax 200	// �ʱ� �÷��̾� �Ѿ� ����
#define BossDefaultDelay 320	// ������ �ʱ� ������ �ӵ�
#define DefaultEBFrame 150	// ���� �Ѿ��� �ʱ� ������ �ӵ�
#define MaxEnemyBullet 7	// ȭ�鿡 ��µǴ� ���� �Ѿ��� ����
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "game.h"


int nStage = 1;	// ���� ��������
int PlayerX = 30; // �÷��̾� ��ǥ
int BulletX = -1, BulletY; // �Ѿ� ��ǥ
int BossHp = 1;	// ������ �ʱ� HP
int BossX;	// ������ ��ǥ
int HitBoss = 0;	// ���� Ÿ�� Ƚ��
int nBullet = BulletMax;	// ���� �Ѿ��� ����
int BossDelay = BossDefaultDelay;	// ������ ������ �ӵ�

clock_t StartTime, EndTime;	// Timer�� ���ϱ� ���� ����
double PrintTime;	// Logâ�� ��� ���� timer
int OperateTime, NowTime;	// ������ ������ �ӵ��� �����ϱ� ���� timer

int EnemyBulletF = DefaultEBFrame;	// ���� �Ѿ��� �ӵ�

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void gotoxy2(int x, int y)	// ��ǥ �� �̵� �Լ�
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcursortype(CURSOR_TYPE c)	// �ܼ��� Ŀ�ʸ���� �����ϴ� �Լ�
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
void DrawInfo()	// ���� ��� �� �ǽð� ������ ���
{
	gotoxy2(56, 3);
	printf("����������������");
	gotoxy2(56, 4);
	printf("��  Log Info  ��");
	gotoxy2(56, 5);
	printf("����������������");

	gotoxy2(56, 7);
	printf("���� ü�� : ");
	gotoxy2(56, 8);
	printf("���� ���� �� : ");
	gotoxy2(56, 9);
	printf("���� �Ѿ� �� : ");
	gotoxy2(56, 10);
	printf("���� �ð� : ");

	gotoxy2(56, 12);
	printf("����������������");
	gotoxy2(56, 13);
	printf("��  ���۹��  ��");
	gotoxy2(56, 14);
	printf("����������������");

	gotoxy2(56, 16);
	printf("�̻��� �߻� : space");
	gotoxy2(56, 17);
	printf("����Ű : �� , ��");
	gotoxy2(56, 18);
	printf("���� ���� : ESC");

	gotoxy2(56, 20);
	printf("����������������");
	gotoxy2(56, 21);
	printf("��  ���ӿ���  ��");
	gotoxy2(56, 22);
	printf("����������������");

	gotoxy2(56, 24);
	printf("Timer�� 0�� �� ��");
	gotoxy2(56, 25);
	printf("�Ѿ��� ��� ������ ��");
}




struct {
	int TFcheck;	// ���� �Ѿ��� ���� ����
	int x, y;	// ���� �Ѿ��� ��ǥ
	int nFrame;	// ���� �Ѿ��� �ӵ��� ������ ����

} EnemyBullet[MaxEnemyBullet];	// ����ü �迭�� ������ ����



void EraseBullet()	// �Ѿ� �����
{
	gotoxy2(BulletX, BulletY);
	printf(" ");
}

void DrawBullet()	// �Ѿ� �׸���
{
	gotoxy2(BulletX, BulletY);
	printf("*");
}

void ErasePlayer()	// �÷��̾� �����
{
	gotoxy2(PlayerX - 2, 29);
	printf("      ");
}

void DrawPlayer()	// �÷��̾� �׸���
{
	gotoxy2(PlayerX - 2, 29);
	printf("��ġ�");
}


void DrawEnemyBullet(int j)	// ���� �Ѿ� �׸���
{
	gotoxy2(EnemyBullet[j].x, EnemyBullet[j].y);
	printf("��");
}

void EraseEnemyBullet(int j)	// ���� �Ѿ� �����
{
	gotoxy2(EnemyBullet[j].x, EnemyBullet[j].y);
	printf(" ");
}

void EnemyBulletCheck()	// ȭ�鿡 ��µǴ� ������ �Ѿ� Ȯ��
{
	int j;

	if (PrintTime == 60)	// stage�� �ʱ�ȭ �ɶ�, �Ѿ˵� �ʱ�ȭ
	{
		for (j = 0; j < MaxEnemyBullet; j++)
		{
			EnemyBullet[j].TFcheck = 0;
		}
	}

	// ���� ������ �Ѿ� ����ü �迭�� ȭ�鿡 ������ ��� �ش� ������ ��ŵ��
	for (j = 0; j < MaxEnemyBullet&&EnemyBullet[j].TFcheck == 1; j++);

	// �������� ������ �������� �� ĭ �Ʒ����� �߻��ϰ� �ϸ�, 
	// �Ѿ��� ���簪�� TFcheck�� 1�� ����
	if (j != MaxEnemyBullet)
	{
		EraseEnemyBullet(j);
		EnemyBullet[j].x = BossX;
		EnemyBullet[j].y = 5;
		// �Ѿ��� �߻縦 ������ �ð����� ����
		EnemyBullet[j].nFrame = EnemyBulletF*(rand() % 10 + 1);
		EnemyBullet[j].TFcheck = 1;
	}
}


void MoveEnemyBullet()	// ������ �Ѿ� �̵� �Լ�
{
	int i;

	for (i = 0; i < MaxEnemyBullet; i++)
	{
		if (EnemyBullet[i].TFcheck == 0)	// �������� ������ ��ŵ
			continue;
		if (EnemyBullet[i].nFrame <= 0)
		{
			// �Ѿ��� ������ �ÿ�, �̵��ӵ��� �ʱ�ȭ ����, ��ǥ�� ����
			EnemyBullet[i].nFrame = EnemyBulletF;
			EraseEnemyBullet(i);

			if (EnemyBullet[i].y > 28)
			{
				// �ٴڰ� �浹�� �Ѿ��� ����
				EnemyBullet[i].TFcheck = 0;
			}
			else
			{
				EnemyBullet[i].y++;
				DrawEnemyBullet(i);
			}

		}
		// �Ѿ��� �����̴� �ӵ��� ����
		EnemyBullet[i].nFrame -= 30;
	}
}


void DrawBoss()	// ������ ȭ�� ��� �� ������ ���� �Լ�
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
	printf("�¢���");

	Sleep(10);

	EnemyBulletCheck();	// ȭ�鿡 ��µǴ� ������ �Ѿ��� Ȯ��

}

void Delay(int i)	// ������ �������� ����
{
	if (NowTime - OperateTime>i)
	{
		OperateTime = clock();
		DrawBoss();
	}
}

void BossCrash()	// ������ �Ѿ��� �浹���� ���
{
	if ((BossX == BulletX&&BulletY == 4) ||
		(BossX == BulletX + 1 && BulletY == 4) ||
		(BossX == BulletX - 1 && BulletY == 4))
	{
		gotoxy2(BulletX - 2, BulletY);
		printf("������");
		Sleep(50);
		gotoxy2(BulletX - 2, BulletY);
		printf("      ");
		BulletX = -1;	// �浹�ÿ� �Ѿ��� ����
		HitBoss += 1;	// �浹�ÿ� ���� Ÿ�� Ƚ�� ����
	}

}




void Map()	// �÷��� ȭ��� Logâ ȭ���� ��輱�� ����
{
	int i;
	StartTime = clock();	// Map�� �����԰� ���ÿ� Timer �۵�

	for (i = 0; i < 32; i++)
	{
		gotoxy2(52, i);
		printf("��");
	}

	for (i = 0; i < 52; i += 2)
	{
		gotoxy2(i, 32);
		printf("��");
	}

	gotoxy2(52, 32);
	printf("��");
}

void Stage()	// Stage ȭ���� �׸� �ڽ��� ���� �� �÷��� ���� ���� Ȯ��
{
	int i;
	char ch;

	gotoxy2(10, 4);
	printf("��");

	for (i = 10; i < 50; i += 2)
	{
		printf("��");
	}

	gotoxy2(50, 4);
	printf("��");

	for (i = 5; i < 15; i++)
	{
		gotoxy2(50, i);
		printf("��");
	}

	gotoxy2(50, 15);
	printf("��");

	for (i = 2; i < 40; i += 2)
	{
		gotoxy2(50 - i, 15);
		printf("��");
	}

	gotoxy2(10, 15);
	printf("��");

	for (i = 1; i < 11; i++)
	{
		gotoxy2(10, 15 - i);
		printf("��");
	}

	gotoxy2(24, 9);
	printf("%d��° ��������\n", nStage);	// �÷��̾��� �ش� ���������� ���
	gotoxy2(12, 17);
	printf("�÷��̸� ���Ͻø� y, �ƴϸ� n�� �Է��ϼ���\n");


	while (1)	// �÷��̾��� ���� ��� ���θ� Ȯ���ϸ�, 
				// ������ 'y'�� 'n'���� �Է��ϰԲ� ����
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

void RealLog()	// �ǽð� ������ ��½�Ŵ
{

	EndTime = clock();
	// �� ������ ����ȯ
	PrintTime = (StartTime - EndTime) / (CLOCKS_PER_SEC)+DefaultTimer;

	gotoxy2(71, 7);
	printf("%d", BossHp);	// ���� ������ HP
	gotoxy2(71, 8);
	printf("%d", HitBoss);	// ���� Ÿ�� Ƚ��
	if (nBullet == 99)	// �Ѿ��� 99���� ������, 100���� ��µǴ� ���� 0�� ����
	{
		gotoxy2(71, 9);
		printf("   ");
	}
	gotoxy2(71, 9);
	printf("%d", nBullet);	// ���� �Ѿ�
	gotoxy2(71, 10);
	printf("%2.0f", PrintTime);	// ���� �ð�


}


void PlayerBullet()	// �Ѿ��� �������� ����
{
	if (BulletX != -1)
	{
		EraseBullet();		// �Ѿ��� ����
		if (BulletY == 0)	// �Ѿ��� �ֻ�� ��ǥ�� �浹�� Ʈ����
		{
			BulletX = -1;
		}
		else				// �Ѿ��� ���� �ö󰡴� �� ǥ�� 
		{
			BulletY--;		// �Ѿ��� y�� ��ǥ�� ����
			DrawBullet();	// �Ѿ��� �׸�
		}
	}
}

void PlayerMove()	// �÷��̾��� �������� ���
{
	char cha;

	if (GetAsyncKeyState(VK_LEFT) < 0 && PlayerX > 3)	// ����Ű�� �Է� ������, 
														// ���� ���� �浹���� �ʾҴٸ�
														// �������� �̵���Ŵ
	{
		ErasePlayer();
		PlayerX--;
		DrawPlayer();
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0 && PlayerX < 47)	// ������Ű�� �Է� ������, 
																// ������ ���� �浹���� �ʾҴٸ�
																// ���������� �̵���Ŵ
	{
		ErasePlayer();
		PlayerX++;
		DrawPlayer();
	}

	if (_kbhit())	// �̻��� �߻� Ʈ����, ���ۿ� ���� �ִ����� Ȯ��
	{
		fflush(stdin);
		cha = _getch();
		switch (cha)
		{
		case ' ':	// �����̽� Ű�� Ʈ���� �۵�
			if (BulletX == -1)	// �Ѿ��� �ϳ��� �߻��ϰ���, ���� ���θ� Ȯ��
			{
				BulletX = PlayerX;
				BulletY = 28;
				nBullet -= 1;
			}
			break;

		case ESC:	// ���� ���Ḧ ���� Ű ESC�� �Է�
			gotoxy2(12, 34);
			exit(0);
		}
	}
}

void PlayerCrash()	// ������ �Ѿ˰� �÷��̾��� �浹�� �˻�
{
	int i;

	for (i = 0; i < MaxEnemyBullet; i++)
	{
		if (EnemyBullet[i].TFcheck == 0)	// �������� ������ continue
			continue;
		// �����ϸ�, ��ǥ�� ��ġ�� ���
		if ((EnemyBullet[i].x == PlayerX&&EnemyBullet[i].y == 29) ||
			(EnemyBullet[i].x == PlayerX + 1 && EnemyBullet[i].y == 29))
		{
			gotoxy2(PlayerX - 2, 29);
			printf("��ü �ı�");
			Sleep(1000);
			nStage = MaxBoss + 2;	// ���� ���� Ʈ���� �۵�
		}
	}
}



void GameOver()	// ���� �ڵ� ����
{
	if (nBullet <= 0)	// �Ѿ��� ��� ������
	{
		nStage = MaxBoss + 2;
	}
	else if (PrintTime <= 0)	// Timer�� 0 �� �� ��
	{
		nStage = MaxBoss + 2;
	}
}



int main2(void)
{	
	setcursortype(NOCURSOR);	// �ܼ��� Ŀ���� ����
	system("mode con: cols=80 lines=36");	// �ܼ� ����� 80*36���� ����
	OperateTime = clock();	// ���� ���� ���ؽð� �ʱ�ȭ
	srand((unsigned)time(NULL));	// �����Լ��� ���� srand


	while (1)	// ���ѷ���
	{
		NowTime = clock();	// ���� ���� �񱳰� ����

		if (nStage >= MaxBoss + 2)	// ������ ����Ǵ� ����
		{
			system("cls");
			gotoxy2(12, 17);
			printf("������ �����մϴ�.\n");
			gotoxy2(12, 18);
			Sleep(1000);
			return -1;
		}

		else if (nStage == MaxBoss + 1)	// ���������� ��� Ŭ���� �Ҷ� �۵�
		{
			gotoxy2(12, 17);
			printf("���������� ��� Ŭ�����Ͽ����ϴ�.\n");
			break;
		}

		else if (nStage < MaxBoss + 1)	// �������� ���� ���� ����
		{
			if (HitBoss == 0 && nStage == BossHp)	// ������ ü���� 0�� �ɽÿ� 
													// ���� ���������� ����
			{
				system("cls");
				Sleep(500);
				Stage();	// �������� ȭ���� ���
				nStage++;
				system("cls");
				Sleep(1000);
				Map();	// �÷��� ȭ���� ���

				do {
					BossX = (rand() % (46));
				} while (BossX <= 3);	// ������ ������ x�� ��ġ�� ������Ŵ

				DrawInfo();	// ���۹��� ���
			}

			RealLog();	// �ǽð� ���� ���
			PlayerMove();	// �÷��̾� ������ Ȯ��
			PlayerBullet();	// �Ѿ� Ȯ��
			Delay(BossDelay);	// ���� ������ Ȯ��
			MoveEnemyBullet();	// ���� �Ѿ� �̵�

			BossCrash();	// �Ѿ˰� ������ �浹�� Ȯ��
			PlayerCrash();	// ������ �Ѿ˰� �÷����� �浹�� Ȯ��
			GameOver();		// ���� ���� ������ �˻�

			Sleep(20);
		}

		if (HitBoss == BossHp&&BossHp < MaxBoss)	// ������ HP�� Ÿ�� Ƚ���� ��ġ�� �� 
													// ���� ���������� �Ѿ�� Ʈ����
		{
			HitBoss = 0;
			BossHp++;
			BossDelay -= 20;	// ������ ������ �ӵ��� ����(���̵� ���)
			EnemyBulletF -= 8; // ������ �Ѿ� �ӵ��� ����(���̵� ���)
		}
	}

	return 0;
}