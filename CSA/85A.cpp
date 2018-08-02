/*************************************************************************
    > File Name: 85A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 23:04:00
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
int n,x,q;
int main()
{
    scanf("%d%d%d",&n,&q,&x);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(v==x) x=u;
        else if(u==x) x=v;
    }
    printf("%d\n",x);
    return 0;
}

