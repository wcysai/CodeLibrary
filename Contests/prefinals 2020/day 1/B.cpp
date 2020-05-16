#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,s[MAXN];
vector<P> dp[MAXN];
void solve(int k,int l,int r)
{
    if(l==r)
    {
        dp[k].push_back(P(l,0));
        return;
    }
    int mid=(l+r)/2;
    solve(k*2,l,mid); solve(k*2+1,mid+1,r);
    for(auto x:dp[k*2])
    {
        ll tmp=INF;
        for(auto y:dp[k*2+1]) if(s[y.F]<=s[x.F]) tmp=min(tmp,x.S+y.S); else tmp=min(tmp,x.S+y.S+1LL*(s[y.F]-s[x.F])*(s[y.F]-s[x.F]));
        dp[k].push_back(P(x.F,tmp));
    }
    for(auto x:dp[k*2+1])
    {
        ll tmp=INF;
        for(auto y:dp[k*2]) if(s[y.F]<=s[x.F]) tmp=min(tmp,x.S+y.S); else tmp=min(tmp,x.S+y.S+1LL*(s[y.F]-s[x.F])*(s[y.F]-s[x.F]));
        dp[k].push_back(P(x.F,tmp));
    }        
}
int main()
{
    freopen("B.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) scanf("%d",&s[i]);
    solve(1,0,(1<<n)-1);
    for(auto p:dp[1]) if(p.F==0) printf("%lld\n",p.S);
    return 0;
}