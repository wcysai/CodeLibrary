/*************************************************************************
    > File Name: dabiao.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-20 15:34:14
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
int main()
{
    for(int n=1;n<=1000;n++)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int g=sqrt(i*j);
                if(g*g==i*j) ans++;
            }
        printf("%d %d\n",n,ans);
    }
    return 0;
}

