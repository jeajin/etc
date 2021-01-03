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
		//시작
		printf(" 컴퓨터와의 숫자야구 게임.:");
		printf("\n");
		printf("게임시작은 '1'을 게임종료는 아무키나 눌러주세요.:");//시작메뉴
		printf("\n\n");
		printf("시작하시겠습니까 :");
		scanf_s("%d", &i);
		if (i != 1) {
			printf("\n");
			printf(" 다음 기회에 :\n");
			printf("\n\n");
			break;
		}
		printf("\n");
		printf("게임 시작:");
		printf("\n\n");
		//임의의 숫자를 생성
		srand((unsigned int)time(NULL));
		MUN[0] = rand() % 10;
		do {
			MUN[1] = rand() % 10;
		} while (MUN[1] == MUN[0]);
		do {
			MUN[2] = rand() % 10;
		} while (MUN[2] == MUN[0] || MUN[2] == MUN[1]);

		printf(" 컴퓨터가 문제를 만들었습니다!");
		printf("\n");
		printf(" 자~ 이제 맞춰보세요.");
		printf("\n\n");

		y = 0;

		do {
			y++;
			printf("-------%d번째 시도 -------", y);

			//사용자 숫자입력
			do {
				printf("\n\n");
				printf("[0~9]범위의 숫자 세개를 입력하세요.");
				printf("\n");
				scanf_s("%d", &DAB[0]);
				printf("     ");
				scanf_s("%d", &DAB[1]);
				printf("        ");
				scanf_s("%d", &DAB[2]);
				if (DAB[0] == DAB[1] || DAB[0] == DAB[2] || DAB[1] == DAB[2]) {
					printf("숫자가 중복되면 안됩니다.");
					printf("\n");
				}
			} while (DAB[0] == DAB[1] || DAB[0] == DAB[2] || DAB[1] == DAB[2] || (DAB[0]>9 || DAB[1]>9 || DAB[2]>9));
			STRIKE = BALL = 0;

			//입력한 수 판단
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
			//사용자에게 결과 알려줌
			printf("\n");
			printf("%d STRIKE %d BALL", STRIKE, BALL);
			printf("\n");
			if (STRIKE<3) {
				printf("다시 시도 하세요.");
				printf("\n");
			}
		} while (STRIKE<3);
		printf("축하합니다.");
		printf("\n");
		printf("한번더 하시겠습니까?");
		printf("\n");
		printf("다시하려면 '1'을 그만하려면 아무키나 누르시오");
		printf("\n");
		scanf_s("%d", &z);
		if (z != 1) {
			break;
		}
	} while (z == 1);
	return 0;
}




