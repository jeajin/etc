#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "game.h"
int main5(void)
{
	int i, y, z;
	int STRIKE, BALL;
	int MUN[3], DAB[3];

	do {
		//����
		printf(" ��ǻ�Ϳ��� ���ھ߱� ����.:");
		printf("\n");
		printf("���ӽ����� '1'�� ��������� �ƹ�Ű�� �����ּ���.:");//���۸޴�
		printf("\n\n");
		printf("�����Ͻðڽ��ϱ� :");
		scanf_s("%d", &i);
		if (i != 1) {
			printf("\n");
			printf(" ���� ��ȸ�� :\n");
			printf("\n\n");
			break;
		}
		printf("\n");
		printf("���� ����:");
		printf("\n\n");
		//������ ���ڸ� ����
		srand((unsigned int)time(NULL));
		MUN[0] = rand() % 10;
		do {
			MUN[1] = rand() % 10;
		} while (MUN[1] == MUN[0]);
		do {
			MUN[2] = rand() % 10;
		} while (MUN[2] == MUN[0] || MUN[2] == MUN[1]);

		printf(" ��ǻ�Ͱ� ������ ��������ϴ�!");
		printf("\n");
		printf(" ��~ ���� ���纸����.");
		printf("\n\n");

		y = 0;

		do {
			y++;
			printf("-------%d��° �õ� -------", y);

			//����� �����Է�
			do {
				printf("\n\n");
				printf("[0~9]������ ���� ������ �Է��ϼ���.");
				printf("\n");
				scanf_s("%d", &DAB[0]);
				printf("     ");
				scanf_s("%d", &DAB[1]);
				printf("        ");
				scanf_s("%d", &DAB[2]);
				if (DAB[0] == DAB[1] || DAB[0] == DAB[2] || DAB[1] == DAB[2]) {
					printf("���ڰ� �ߺ��Ǹ� �ȵ˴ϴ�.");
					printf("\n");
				}
			} while (DAB[0] == DAB[1] || DAB[0] == DAB[2] || DAB[1] == DAB[2] || (DAB[0]>9 || DAB[1]>9 || DAB[2]>9));
			STRIKE = BALL = 0;

			//�Է��� �� �Ǵ�
			for (i = 0; i<3; i++) {
				if (DAB[i] == MUN[i]) {
					STRIKE++;
				}
				else if (DAB[(i + 1) % 3] == MUN[i]) {
					BALL++;
				}
				else if (DAB[(i + 2) % 3] == MUN[i]) {
					BALL++;
				}
			}
			//����ڿ��� ��� �˷���
			printf("\n");
			printf("%d STRIKE %d BALL", STRIKE, BALL);
			printf("\n");
			if (STRIKE<3) {
				printf("�ٽ� �õ� �ϼ���.");
				printf("\n");
			}
		} while (STRIKE<3);
		printf("�����մϴ�.");
		printf("\n");
		printf("�ѹ��� �Ͻðڽ��ϱ�?");
		printf("\n");
		printf("�ٽ��Ϸ��� '1'�� �׸��Ϸ��� �ƹ�Ű�� �����ÿ�");
		printf("\n");
		scanf_s("%d", &z);
		if (z != 1) {
			break;
		}
	} while (z == 1);
	return 0;
}




