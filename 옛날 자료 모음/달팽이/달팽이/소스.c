#include<stdio.h>
#define garo 5
#define sero 9

int main(void)
{
	int  p, q, j, k, s,m,num,dar[sero][garo] = { 0 };
	p = 0; q = -1; m = 1; num = 1;
	s = 1; 
	k = garo;
	j = sero;
	for (; k > 0 || j > 0;)
	{
		for (m=1; m <= k; m++)
		{
			q += s;
			dar[p][q] = num++;
						
		}
		k -= 1;
		j -= 1;
		for (m=1; m <= j; m++)
		{
			p += s;
			dar[p][q] = num++;
		}
		s *= -1;
		
	}
	for (p = 0; p != sero; p++)
	{
		for (q = 0; q != garo; q++)
		{
			printf("%3d ", dar[p][q]);
		}
		printf("\n");
	}
}

