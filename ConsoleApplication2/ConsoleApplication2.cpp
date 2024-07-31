//牛客 gcd 超时做法（defeat）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>
#include <iterator>
using namespace std;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b):a;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    { 
        set<int> s;
        set<int>s2;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            s.insert(temp);
        }
        for (set<int>::iterator j = s.begin(); j != s.end(); ++j)
        {
            for (set<int>::iterator k = next(j); k != s.end(); ++k)
            {
                s2.insert(gcd(*j, *k));
            }
        }
        for (int i = 0; i < m; i++)
        {
            bool found = false;
            int num;
            scanf("%d", &num);
            if (s.count(num))
            {
                found = true;
            }
            else if(s2.count(num))
            {
                found = true;
                /*
                for (set<int>::iterator j = s.begin(); j != s.end(); ++j)
                {
                    for (set<int>::iterator k = next(j); k != s.end(); ++k)
                    {
                        if (gcd(*k, *j) == num)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (found == true)break;
                }
                */
            }
            if(!found)
            printf("NO\n");
			else
				printf("YES\n");
        }
    }
}