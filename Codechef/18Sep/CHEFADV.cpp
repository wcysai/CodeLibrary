/*************************************************************************
    > File Name: CHEFADV.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-11 16:47:13
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
int T,N,M,X,Y;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&N,&M,&X,&Y);
        bool f=false;
        if((N-1)%X==0&&(M-1)%Y==0&&N>=1&&M>=1) f=true;
        if((N-2)%X==0&&(M-2)%Y==0&&N>=2&&M>=2) f=true;
        if(f) puts("Chefirnemo"); else puts("Pofik");
    }
    return 0;
}

