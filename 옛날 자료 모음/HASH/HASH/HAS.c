#include<stdio.h>

int main(void)
{
	int a, b, hash[80][32] = { 1 };
	hash[0][1] = 1;
	hash[0][4] = 1;
	hash[0][6] = 1;
	hash[0][7] = 1;
	hash[0][9] = 1;
	hash[0][10] = 1;
	hash[0][12] = 1;
	hash[0][15] = 1;
	hash[0][17] = 1;
	hash[0][18] = 1;
	hash[0][20] = 1;
	hash[0][21] = 1;
	hash[0][23] = 1;
	hash[0][25] = 1;
	hash[0][27] = 1;
	hash[0][29] = 1;
	hash[1][1] = 1;
	hash[1][2] = 1;
	hash[1][7] = 1;
	hash[1][9] = 1;
	hash[1][10] = 1;
	hash[1][13] = 1;
	hash[1][15] = 1;
	hash[1][17] = 1;
	hash[1][20] = 1;
	hash[1][25] = 1;
	hash[1][26] = 1;
	hash[1][28] = 1;
	hash[1][29] = 1;
	hash[1][30] = 1;
	hash[1][31] = 1;
	hash[2][1] = 1;
	hash[2][2] = 1;
	hash[2][4] = 1;
	hash[2][5] = 1;
	hash[2][6] = 1;
	hash[2][7] = 1;
	hash[2][9] = 1;
	hash[2][10] = 1;
	hash[2][12] = 1;
	hash[2][13] = 1;
	hash[2][14] = 1;
	hash[15][25] = 1;
	hash[15][27] = 1;
	for (a = 16; a < 80; a++)
	{
		for (b = 1; b < 32; b++)
		{
			hash[a][b - 1] = hash[a - 16][b] ^ hash[a - 14][b] ^ hash[a - 8][b] ^ hash[a - 3][b];
		}
		hash[a][31] = hash[a - 16][0] ^ hash[a - 14][0] ^ hash[a - 8][0] ^ hash[a - 3][0];

	}
	for (a = 16; a < 80; a++)
	{
		printf("%d:", a);
		for (b = 0; b < 32; b++)
		{
			printf("%d", hash[a][b]);
			if ((b + 1) % 8 == 0)
			{
				printf(" ");
			}

		}
		printf("\n\n");


	}
}