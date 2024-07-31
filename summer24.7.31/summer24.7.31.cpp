//acwing 197 阶乘分解

//超时做法
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[100000] = { 0 };
int main()
{
    int n;
    int num = 0;
    scanf("%d", &n);
    for (int i = n; i >= 2; i--)
    {
        int temp = i;
        if (arr[i] != 0)
        {
            arr[i]++;
            continue;
        }
        for (int j = 2; j <= temp; j++)
        {
            if (temp % j == 0)
            {
                while (temp % j == 0)
                {
                    arr[j]++;
                    temp /= j;
                }
            }
        }
        if (temp > 1)arr[temp]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d %d\n", i, arr[i]);
        }
    }
}
*/

//做法二
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int notprime[1000000] = { 0 };
int prime[1000000] = { 0 };
int primecount = 0;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (notprime[i])continue;
        for (int j = 2; j <= n / i; j++)
        {
            notprime[i * j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!notprime[i])prime[++primecount] = i;
    }
    for (int i = 1; i <= primecount; i++)
    {
        int tempn = n, tempprime = prime[i], ans = 0;
        while (tempn)
        {
            ans += (tempn / tempprime);
            tempn /= tempprime;
        }
        printf("%d %d\n", tempprime, ans);
    }
}