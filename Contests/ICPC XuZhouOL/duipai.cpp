/*************************************************************************
    > File Name: duipai.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-09 14:17:47
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
int n,k,a[MAXN],ans;
void solve()
{
    for(int i=0;i<n;i++)
    {
        int res=a[i]^a[(i+1)%n];
        if((res&((1<<k)-1))==((1<<k)-1)) return;
    }
    ans++;
    if(ans==MOD) ans=0;
}
void dfs(int now)
{
    if(now==n) {solve(); return;}
    for(int i=0;i<(1<<k);i++) a[now]=i,dfs(now+1);
}
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}

