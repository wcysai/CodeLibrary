/*************************************************************************
    > File Name: 50D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 15:16:41
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
int n,k,a[MAXN];
int bit[MAXN+1],dp[MAXN];
int sum(int i)
{
    int s=0;
    while(i)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int x,int i)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[v]=u;
    }
    fill(dp,dp+n,INF);
    for(int i=n;i>=1;i--)
        *upper_bound(dp,dp+n,a[i])=a[i];
    printf("%d\n",(int)(lower_bound(dp,dp+n,INF)-dp));
    return 0;
}

