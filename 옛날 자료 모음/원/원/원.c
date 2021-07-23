#include<stdio.h>
#include<math.h>
#define g1 13 //Ãà±æÀÌ
#define s1 13
#define x1 21 //ÁÂÇ¥
#define y1 21
#define g2 13 //Ãà±æÀÌ
#define s2 13
#define x2 13 //ÁÂÇ¥
#define y2 13
#define g3 13 //Ãà±æÀÌ
#define s3 13
#define x3 21//ÁÂÇ¥
#define y3 13
#define g4 13 //Ãà±æÀÌ
#define s4 13
#define x4 13 //ÁÂÇ¥
#define y4 21
#define g5 13 //Ãà±æÀÌ
#define s5 13
#define x5 17 //ÁÂÇ¥
#define y5 17
int main(void)
{
	int X, Y;
	char cir[s1 + y1 + 1][g1 + x1 + 1] = { NULL };
	for (Y = 0; Y < s1 + y1 + 1; Y++)
	{
		for (X = 0; X < g1 + x1 + 1; X++)
		{
			if (s1*s1*pow(X-x1,2)+g1*g1*pow(Y-y1,2)-pow(s1*g1,2) <= 0)
			{ 
				cir[X][Y] = '*';
			}
		}
	}
	for (Y = 0; Y < s2 + y2 + 1; Y++)
	{
		for (X = 0; X < g2 + x2 + 1; X++)
		{
			if (s2*s2*pow(X - x2, 2) + g2*g2*pow(Y - y2, 2) - pow(s2*g2, 2) <= 0)
			{
				if (cir[X][Y] == '*')
					cir[X][Y] = ' ';
				else
					cir[X][Y] = '*';
			}
		}
	}
	for (Y = 0; Y < s3 + y3 + 1; Y++)
	{
		for (X = 0; X < g3 + x3 + 1; X++)
		{
			if (s3*s3*pow(X - x3, 2) + g3*g3*pow(Y - y3, 2) - pow(s3*g3, 2) <= 0)
			{
				if (cir[X][Y] == '*')
					cir[X][Y] = ' ';
				else
					cir[X][Y] = '*';
			}
		}
	}
	for (Y = 0; Y < s4 + y4 + 1; Y++)
	{
		for (X = 0; X < g4 + x4 + 1; X++)
		{
			if (s4*s4*pow(X - x4, 2) + g4*g4*pow(Y - y4, 2) - pow(s4*g4, 2) <= 0)
			{
				if (cir[X][Y] == '*')
					cir[X][Y] = ' ';
				else
					cir[X][Y] = '*';
			}
		}
	}
	for (Y = 0; Y < s5 + y5 + 1; Y++)
	{
		for (X = 0; X < g5 + x5 + 1; X++)
		{
			if (s5*s5*pow(X - x5, 2) + g5*g5*pow(Y - y5, 2) - pow(s5*g5, 2) <= 0)
			{
				if (cir[X][Y] == '*')
					cir[X][Y] = ' ';
				else
					cir[X][Y] = '*';
			}
		}
	}

	for (Y = 0; Y < s1 + y1 + 1 ; Y++)
	{
		for (X = 0; X < g1 + x1 + 1; X++)
		{
			printf("%c ",cir[Y][X]);
		}
		printf("\n");
	}
}
