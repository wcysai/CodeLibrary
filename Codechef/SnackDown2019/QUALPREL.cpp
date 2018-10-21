/*************************************************************************
    > File Name: QUALPREL.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-16 19:10:28
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
int T,N,K;
int a[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;i++) 
        {
            scanf("%d",&a[i]);
            a[i]=INF-a[i];
        }
        sort(a,a+N);
        int ans=upper_bound(a,a+N,a[K-1])-a;
        printf("%d\n",ans);
    }
    return 0;
}

