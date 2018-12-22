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
int n=1000000,lim=1;
mt19937 wcy(time(NULL));
int main()
{
    freopen("test120.txt","w",stdout);
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
        printf("%d%c",wcy()%lim+1,i==n?'\n':' ');
    return 0;
}

