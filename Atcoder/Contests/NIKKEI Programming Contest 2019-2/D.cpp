#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
#define exit dskosad
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,l[MAXN],r[MAXN],c[MAXN];
vector<P> enter[MAXN];
vector<ll> exit[MAXN];
multiset<ll> ms;
ll dp[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&c[i]);
        enter[l[i]].push_back(P(r[i],c[i]));
    }
    dp[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
            if(ms.size()) dp[i]=*ms.begin();
            else dp[i]=INF;
        }
        for(auto p:enter[i])
        {
            ll res=dp[i]+p.S;
            ms.insert(res);
            exit[p.F].push_back(res);
        }
        for(auto x:exit[i]) ms.erase(ms.find(x));
    }
    if(dp[n]>=INF) puts("-1"); else printf("%lld\n",dp[n]);
    return 0;
}
