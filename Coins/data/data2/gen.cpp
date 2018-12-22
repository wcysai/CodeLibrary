/*************************************************************************
    > File Name: gen.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-19 10:43:53
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
int n=1000000,lim=1000000000;
mt19937 wcy(time(NULL));
int main()
{
    freopen("test50.txt","w",stdout);
    printf("%d\n",n);
    int s=0;
    for(int i=1;i<=n-1;i++)
    {
        int x=wcy()%lim+1;if(x&1) s=s^1;
        printf("%d ",x);
    }
    if(s==1) printf("0\n"); else printf("1\n");
    return 0;
}

