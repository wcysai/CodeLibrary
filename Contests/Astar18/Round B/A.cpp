/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 14:01:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,M,K;
int deg[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<N;i++) deg[i]=0;
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
        }
        int mx=0;
        for(int i=0;i<N;i++) mx=max(mx,deg[i]);
        printf("%d\n",min(mx+K+(N-M-1),N-1));
    }
    return 0;
}

