#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,K,M;
ll p10[19];
vector<ll> a,b;
ll dp[20][20][2][2];
void add(ll &a,ll b) {a+=b;}
ll solve(ll cur,ll now,ll less1,ll less2)
{
    ll szb=(int)b.size();
    ll &ret=dp[cur][now][less1][less2];
    if(ret!=-1) return ret;
    if(less2) 
    {
        if(less1) return p10[(int)b.size()-cur];
        else
        {
            ret=0;
            for(ll k=cur;k<(int)b.size();k++) ret+=b[k]*p10[szb-k-1];
            ret++;
            return ret;
        }
    }
    if(now==(int)a.size()) return 0;
    if(cur==(int)b.size()) return now?1:0;
    ret=0;
    int limit=less1?a[now]:min(b[cur],a[now]);
    for(int i=0;i<=limit;i++) add(ret,solve(cur+1,(!now&&!i)?0:now+1,(less1||(i<b[cur]))?1:0,((now||i)&&(i<a[now]))?1:0));
    return ret;
}
ll count(ll x)
{
    b.clear();
    ll dummy=x;
    while(dummy) b.push_back(dummy%10),dummy/=10;
    reverse(b.begin(),b.end());
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    dp[i][j][k][l]=-1;
    return solve(0,0,0,0);
}
int main()
{
    p10[0]=1;
    for(ll i=1;i<=18;i++) p10[i]=10*p10[i-1];
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&K,&M); a.clear();
        ll dummy=K;
        while(dummy) a.push_back(dummy%10),dummy/=10;
        reverse(a.begin(),a.end());
        if(count(K)>=M) {puts("0"); continue;}
        ll l=K-1,r=INF;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(count(mid)>=M-1) r=mid; else l=mid;
        }
        if(r==INF) puts("0"); else printf("%lld\n",r);
    }
    return 0;
}

