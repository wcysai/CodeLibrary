/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-20 15:03:27
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
int n,k,a[MAXN],sum[MAXN],ans;
vector<int> G[MAXN];
map<int,int> mp[MAXN];
void solve(int v,int p)
{
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        solve(to,v);
        if(mp[to].size()>mp[v].size()) {swap(mp[to],mp[v]); swap(sum[to],sum[v]);}
    }
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        for(auto it:mp[to])
        {
            sum[v]-=mp[v][it.F];if(sum[v]<0) sum[v]+=MOD;
            mp[v][it.F]=1LL*(mp[v][it.F]+1)*(it.S+1)%MOD;
            mp[v][it.F]--;
            sum[v]+=mp[v][it.F];if(sum[v]>=MOD) sum[v]-=MOD;
        }
    }
   /* if(v==1)
    {
        for(auto it:mp[v]) printf("%d %d\n",it.F,it.S);
    }*/
    //printf("%d %d\n",v,sum);
    ans=ans+sum[v]+1;if(ans>=MOD) ans-=MOD;
    (mp[v][a[v]]+=sum[v]+1)%=MOD;
    (sum[v]+=sum[v]+1)%=MOD;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d%d",&x,&a[i]);
        if(x==-1) continue;
        G[x].push_back(i);G[i].push_back(x);
    }
    solve(1,0);
    printf("%d\n",ans);
    return 0;
}

