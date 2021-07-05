#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int k,sz;
vector<int> v;
ll p9[20],p10[20];
map<int,ll> dp[20][2][2];
ll solve(int now,int less,int zero,int k)
{
    if(now==sz) return (k!=0?1:0);
    if(sz-now<=18&&(k>=p9[sz-now]||k==INF)&&less) return p10[sz-now];
    int rb=less?9:v[now];
    if(dp[now][less][zero].find(k)!=dp[now][less][zero].end()) return dp[now][less][zero][k];
    ll ans=0;
    if(k==0) 
    {
        ans+=solve(now+1,less|(rb>0),0,INF);//choose 0
        if(rb>0)
        {
            ans+=(rb-1)*solve(now+1,1,0,0);
            ans+=solve(now+1,less,0,0);
        }
    }
    else if(k==INF)
    {
        ans+=solve(now+1,less|(rb>0),0,INF);//choose 0
        if(rb>0)
        {
            ans+=(rb-1)*solve(now+1,1,0,INF);
            ans+=solve(now+1,less,0,INF);
        }
    }
    else
    {
        for(int i=0;i<=rb;i++)
        {
            if(i==0)
            {
                if(zero) ans+=solve(now+1,less|(rb>i),1,k);
                else ans+=solve(now+1,less|(rb>i),0,INF);
            }
            else ans+=solve(now+1,less|(rb>i),0,k/i);
        }
    }
    return dp[now][less][zero][k]=ans;
}
int main()
{
    p9[0]=p10[0]=1;
    for(int i=1;i<=18;i++) p9[i]=9LL*p9[i-1];
    for(int i=1;i<=18;i++) p10[i]=10LL*p10[i-1];
    scanf("%lld%d",&n,&k);
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    sz=(int)v.size();
    printf("%lld\n",solve(0,0,1,k)-1);
    return 0;
}