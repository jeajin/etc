#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void mk(int *ro,int l);
void pr(int *ro,int l);
int main()
{
	srand((unsigned int)time(NULL));
	unsigned int ro[6],base[7],i,j,c,n,ct=0,l,f=0,s=0,t=0,fo=0,e=0,d=0,a=0,b=0,cu=0 ;
	scanf_s("%d", &n);
	mk(base,7);
	pr(base, 7);
	
	while(n != ct)
	{
		c = 0;
		l = 0;
		ct++ ;
		mk(ro, 6);
		/*pr(ro, 6);*/
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 6; j++)
			{
				if (base[i] == ro[j])
				{
					c++;
					j = 5;
				}
			}
			if ((i == 5) || (c == 5))
			{
				for (j = 0; j < 6; j++)
				{
					if (base[6] == ro[j])
					{
						l++;
						j = 5;
					}
				}
			}
		}
		/*printf("%d %d \n", c,l);*/
		switch(c)
		{
		case 6:
			f++;
			break;
		case 5:
			if (l == 1)
			{
				s++;
			}
			else
				t++;
			break;
		case 4:
			fo++;
			break;
		case 3:
			e++;
			break;
		default:
			d++;
			break;
		}
	}
	printf("1등: %d\n2등: %d\n3등: %d\n4등: %d\n5등: %d\n미당첨: %d\n", f, s, t, fo, e, d);
	printf("사용금액:%i억%i만%i원\n", n/100000,(n%100000)/10, ((n % 10000) % 10)*1000);
	cu = f * 8453 + s * 5213 + t * 8623 + e * 5000;
	b = cu / 10000 + f*6416+s*5893+t*153+fo*5;
	cu = cu % 10000;
	a = b / 10000 + f * 20;
	b = b % 10000;
	printf("당첨금액: %i억%i만%i원\n", a,b,cu);


}
void pr(int *ro,int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		printf("%2d ", *(ro + i));
	}
	printf("\n");
}
void mk(int*ro,int l)
{

	int i, j;
	for (i = 0; i < l; i++)
	{
		ro[i] = (rand() % 45) + 1;
		for (j = 0; j < i ; j++)
		{
			if (ro[i] == ro[j])
			{
				i--;
			}
		}
	}
	
}