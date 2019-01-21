/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 16:33:58
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
int main()
{
    scanf("%lld%lld",&n,&m);
    if(n==m)
    {
        puts("1");
        printf("1 ");
        for(int i=0;i<n;i++) printf("9");
        puts("");
    }
    else if(n<m)
    {
        puts("3");
        printf("0 ");
        for(int i=0;i<m-n;i++) printf("9");
        printf(" 1 ");
        for(int i=0;i<n;i++) printf("9");
        puts("");
    }
    else
    {
        if(n%m==0)
        {
            puts("1");
            for(int i=0;i<(n/m)-1;i++)
            {
                printf("1");
                for(int j=0;j<m-1;j++) printf("0");
            }
            printf("1 ");
            for(int i=0;i<m;i++) printf("9");
            puts("");
        }
        else
        {
            puts("3");
            int r=n%m;
            for(int i=0;i<(n/m)-1;i++)
            {
                printf("1");
                for(int j=0;j<m-1;j++) printf("0");
            }
            printf("1");
            for(int i=0;i<r;i++) printf("0");
            printf(" ");
            for(int i=0;i<m-r;i++) printf("9");
            printf(" 1 ");
            for(int i=0;i<r;i++) printf("9");
            puts("");
        }
    }
    return 0;
}

