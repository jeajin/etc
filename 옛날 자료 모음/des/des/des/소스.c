#include<stdio.h>
#include<conio.h>
#include<windows.h>
#pragma warning(disable:4996)
void paritydrop(int *firstkey, int *kk, int *key_position);
void round_ED(int(*roundkey)[48], int(*roundcipher)[64], int *ip, int s);
void initial(int *plain, int*ip);
void final(int *roundcipher, int *finalcipher);
void roundkey_generator(int(*roundkey)[48], int *firstkey);

int main(void)
{
	system("mode con cols=100 lines=80");
	char pl[8];
	int i;
	printf("이름을 적으세요:");
	for (i = 0; i < 8; i++)
	{
		scanf("%c", &pl[i]);
	}
	int plain[64] = { 0 } /*{
						  0,1,1,0,1,0,1,0,
						  0,1,1,0,0,1,0,1,
						  0,1,1,0,0,0,0,1,
						  0,1,1,0,1,0,1,0,
						  0,1,1,0,1,0,0,1,
						  0,1,1,0,1,1,1,0,
						  0,1,1,0,1,0,1,1,
						  0,1,1,0,1,0,0,1
						  }*/;
	for (i = 0; i < 8; i++)
	{
		plain[i * 8 + 1] = (int)pl[i] % 128;
		plain[i * 8 + 0] = plain[i * 8 + 0] / 128;
		plain[i * 8 + 2] = plain[i * 8 + 1] % 64;
		plain[i * 8 + 1] = plain[i * 8 + 1] / 64;
		plain[i * 8 + 3] = plain[i * 8 + 2] % 32;
		plain[i * 8 + 2] = plain[i * 8 + 2] / 32;
		plain[i * 8 + 4] = plain[i * 8 + 3] % 16;
		plain[i * 8 + 3] = plain[i * 8 + 3] / 16;
		plain[i * 8 + 5] = plain[i * 8 + 4] % 8;
		plain[i * 8 + 4] = plain[i * 8 + 4] / 8;
		plain[i * 8 + 6] = plain[i * 8 + 5] % 4;
		plain[i * 8 + 5] = plain[i * 8 + 5] / 4;
		plain[i * 8 + 7] = plain[i * 8 + 6] % 2;
		plain[i * 8 + 6] = plain[i * 8 + 6] / 2;
	}

	int ip[64] = { 0 };
	int key[64] = {
		0,1,1,1,0,0,1,1,
		0,1,1,0,1,1,1,1,
		0,1,1,0,1,1,1,1,
		0,1,1,0,1,1,1,0,
		0,1,1,0,0,1,1,1,
		0,1,1,1,0,0,1,1,
		0,1,1,0,1,0,0,1,
		0,1,1,0,1,1,0,0 };
	int key_position[56] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	int firstkey[56] = { 0 };
	int roundkey[16][48] = { 0 };
	int roundcipher[16][64] = { 0 };
	int finalcipher[64] = { 0 };
	int finalplain[64] = { 0 };
	//암호화//
	printf("평문 \n");
	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%3d", plain[i]);
	}printf("\n\n");
	/* initial*/
	initial(plain, ip);
	printf("이니셜 \n");
	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%3d", ip[i]);
	}
	printf("\n\n");
	/* 패리티제거*/
	paritydrop(firstkey, key, key_position);
	printf("패리티 \n");
	for (i = 0; i < 56; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%3d", firstkey[i]);
	}printf("\n");
	getch();
	system("cls");
	/*라운별 키 생성*/
	roundkey_generator(roundkey, firstkey);

	/* round 16 */
	round_ED(roundkey, roundcipher, ip, 0);
	/* final*/
	final(roundcipher[15], finalcipher);
	printf("final:\n");
	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%2d", finalcipher[i]);
	}
	getch();
	//복호화//
	printf("\n\n");
	/* initial*/
	initial(finalcipher, ip);
	/* round 16 */
	round_ED(roundkey, roundcipher, ip, 1);
	/* final*/
	final(roundcipher[15], finalplain);

	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%2d", finalplain[i]);
	}
	return 0;
}
void paritydrop(int *firstkey, int *kk, int *key_position)
{
	int i;
	for (i = 0; i < 56; i++)
	{
		firstkey[i] = kk[key_position[i] - 1];
	}
}
void roundkey_generator(int(*roundkey)[48], int *firstkey)
{
	int rkey[28] = { 0 }, lkey[28] = { 0 }, i, j;
	int keyposition[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
	int subkey[56] = { 0 };
	int r1, r2, l1, l2;
	for (i = 0; i < 28; i++)
	{
		lkey[i] = firstkey[i];
		rkey[i] = firstkey[i + 28];
	}
	for (j = 0; j < 16; j++)
	{
		if (j == 0 || j == 1 || j == 8 || j == 15)
		{
			r1 = rkey[0];
			l1 = lkey[0];
			for (i = 0; i < 27; i++)
			{
				rkey[i] = rkey[i + 1];
				lkey[i] = lkey[i + 1];
			}
			rkey[27] = r1;
			lkey[27] = l1;
		}
		else
		{
			r1 = rkey[0];
			l1 = lkey[0];
			r2 = rkey[1];
			l2 = lkey[1];
			for (i = 0; i < 26; i++)
			{
				rkey[i] = rkey[i + 2];
				lkey[i] = lkey[i + 2];
			}
			rkey[26] = r1;
			lkey[26] = l1;
			rkey[27] = r2;
			lkey[27] = l2;
		}
		for (i = 0; i < 28; i++)
		{
			subkey[i] = lkey[i];
			subkey[i + 28] = rkey[i];
		}
		for (i = 0; i < 48; i++)
		{
			roundkey[j][i] = subkey[keyposition[i] - 1];
		}

	}
}
void round_ED(int(*roundkey)[48], int(*roundcipher)[64], int *ip, int s)
{
	int i, j = 0;
	int leftcipher[32] = { 0 }, rightcipher[32] = { 0 }, ep_box[48] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	int ep_sub[48] = { 0 };
	int s_boxposition[8][4][16] =
	{ { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{ 0, 15, 7, 4, 14, 2, 13, 10, 3, 6, 12, 11, 9, 5, 3, 8 },
	{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
	{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } },

	{ { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
	{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
	{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
	{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } },

	{ { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
	{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
	{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
	{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } },

	{ { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
	{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
	{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
	{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } },

	{ { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
	{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
	{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
	{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } },

	{ { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
	{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
	{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
	{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 10, 0, 8, 13 } },

	{ { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
	{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
	{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
	{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } },

	{ { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
	{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 10, 14, 9, 2 },
	{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 10, 15, 3, 5, 8 },
	{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 9, 3, 5, 6, 11 } } };
	int sub_sbox[32] = { 0 };
	int ss_boxposition[32] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };
	int ss_sub[32] = { 0 };
	for (i = 0; i < 32; i++)
	{
		leftcipher[i] = ip[i];
		rightcipher[i] = ip[i + 32];
	}
	for (j = 0; j < 16; j++)
	{
		printf("Left: \n");
		for (i = 0; i < 32; i++)
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d ", leftcipher[i]);
		}printf("\n\n");
		printf("Right: \n");
		for (i = 0; i < 32; i++)
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d ", rightcipher[i]);
		}printf("\n\n");

		for (i = 0; i < 48; i++)
		{
			if (s == 0)
			{
				ep_sub[i] = rightcipher[ep_box[i] - 1];
			}
			else if (s == 1)
			{
				ep_sub[i] = rightcipher[ep_box[i] - 1] ^ roundkey[15 - j][i];
			}
		}
		printf("확장 p-box: \n");
		for (i = 0; i < 48; i++) //확장 p-box
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d ", ep_sub[i]);
		}printf("\n\n");
		printf("%d라운드 키\n", j + 1);
		for (i = 0; i < 48; i++)
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d", roundkey[j][i]);
		}
		printf("\n\n");
		for (i = 0; i < 48; i++)
		{
			ep_sub[i] ^= roundkey[j][i];
		}
		printf("라운드 키Xor:  \n");
		for (i = 0; i < 48; i++)
		{
			if (i % 6 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d ", ep_sub[i]);
		}      printf("\n\n");
		for (i = 0; i < 8; i++)
		{
			sub_sbox[i * 4] = s_boxposition[i][ep_sub[i * 6 + 0] * 2 + ep_sub[i * 6 + 5]][ep_sub[i * 6 + 1] * 8 + ep_sub[i * 6 + 2] * 4 + ep_sub[i * 6 + 3] * 2 + ep_sub[i * 6 + 4]];
		}
		printf("축소:  \n");
		for (i = 0; i < 8; i++)
		{
			printf("%3d", sub_sbox[i * 4]);
		}   printf("\n\n");
		for (i = 0; i < 8; i++)
		{
			sub_sbox[i * 4 + 1] = sub_sbox[i * 4 + 0] % 8;
			sub_sbox[i * 4 + 0] = sub_sbox[i * 4 + 0] / 8;
			sub_sbox[i * 4 + 2] = sub_sbox[i * 4 + 1] % 4;
			sub_sbox[i * 4 + 1] = sub_sbox[i * 4 + 1] / 4;
			sub_sbox[i * 4 + 3] = sub_sbox[i * 4 + 2] % 2;
			sub_sbox[i * 4 + 2] = sub_sbox[i * 4 + 2] / 2;
		}
		printf("축소2진:  \n");
		for (i = 0; i < 32; i++)
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d", sub_sbox[i]);
		}printf("\n\n");
		for (i = 0; i < 32; i++)
		{
			ss_sub[i] = sub_sbox[ss_boxposition[i] - 1];
		}
		printf("단순치환:  \n");
		for (i = 0; i < 32; i++)
		{
			if (i % 8 == 0 && i != 0)
			{
				printf("\n");
			}
			printf("%3d", ss_sub[i]);
		}printf("\n\n");
		if (j != 15)
		{
			for (i = 0; i < 32; i++)
			{
				ss_sub[i] = ss_sub[i] ^ leftcipher[i];
				leftcipher[i] = rightcipher[i];
				rightcipher[i] = ss_sub[i];
			}
			printf("xor:  \n");
			for (i = 0; i < 32; i++)
			{
				if (i % 8 == 0 && i != 0)
				{
					printf("\n");
				}
				printf("%3d", rightcipher[i]);
			}printf("\n\n");
		}

		else if (j == 15)
		{
			for (i = 0; i < 32; i++)
			{
				leftcipher[i] = ss_sub[i] ^ leftcipher[i];
			}
			printf("xor:  \n");
			for (i = 0; i < 32; i++)
			{
				if (i % 8 == 0 && i != 0)
				{
					printf("\n");
				}
				printf("%3d", leftcipher[i]);
			}printf("\n\n");
		}


		for (i = 0; i < 32; i++)
		{
			roundcipher[j][i] = leftcipher[i];
			roundcipher[j][i + 32] = rightcipher[i];
		}
		getch();
		system("cls");
	}
}
void initial(int *plain, int*ip)
{
	int i, initial[64] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,06,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
	for (i = 0; i < 64; i++)
	{
		ip[i] = plain[initial[i] - 1];
	}
}
void final(int *roundcipher, int *finalcipher)
{
	int i, final[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	for (i = 0; i < 64; i++)
	{
		finalcipher[i] = roundcipher[final[i] - 1];
	}
}