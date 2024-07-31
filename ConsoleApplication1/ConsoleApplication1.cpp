#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int notprime[10000000];
int prime[10000000];
int cnt = 0;
int main()
{
	int p;
	scanf("%d", &p);
	for (int s = 0; s < p; s++)
	{
		int n, count = 1;
		scanf("%d", &n);
		for (int i = 2; i <= 10000000; i++)
		{
			if (notprime[i])continue;
			for (int j = 2; j <= 10000000 / i; j++)
			{
				notprime[i * j] = 1;
			}
		}
		for (int i = 2; i < 10000000; i++)
		{
			if (!notprime[i])
			{
				prime[++cnt] = i;
			}
		}
		if (n != 1)count++;
		for (int j = 1; prime[j] < n; j++)
		{
			if (n % prime[j] == 0)count++;
		}
		printf("%d\n", count);
	}
}