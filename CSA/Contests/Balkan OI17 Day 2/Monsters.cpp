#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 755
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,M,t,a[MAXN][MAXN],U[MAXN][MAXN];
ll ans[MAXN][MAXN];
char str[MAXN][MAXN];
void prefix_sum_col()
{
    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            ans[i][j]+=ans[i-1][j];
}
void prefix_sum_row()
{
    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            ans[i][j]+=ans[i][j-1];
}
int main()
{
    scanf("%lld%lld",&N,&M);
    for(ll i=1;i<=N;i++) scanf("%s",str[i]+1);
    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            a[i][j]=str[i][j]-'0';
    for(ll i=1;i<=M;i++)
    {
        ll now=0;
        for(ll j=1;j<=N;j++)
        {
            if(a[j][i]==1) U[j][i]=++now;
            else
            {
                U[j][i]=0;
                now=0;
            }
        }
    }
    ll res=0;
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=M;j++)
        {
            if(a[i][j]==0) continue;
            ll cnt=INF,len=0;
            for(ll k=j;k<=M;k++)
            {
                if(a[i][k]==0) break;
                len++; cnt=min(cnt,U[i][k]);
                res+=cnt;
                ll x=i-cnt+1,y=j+len;
                ans[x][y]--; ans[x][j]++; ans[i+1][j]-=(cnt+1); ans[i+1][y]+=(cnt+1);
                ans[i+2][j]+=cnt; ans[i+2][y]-=cnt;
            }
        }
    }
    ll cnt=0;
    prefix_sum_col();prefix_sum_col();prefix_sum_row();
    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=M;j++)
            cnt=max(cnt,ans[i][j]); 
    printf("%lld\n",res-cnt);
    return 0;
}

