#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<P> v;
vector<P> l,r;
ll dp[MAXN][MAXN];
bool cmp(P x,P y)
{
    return 1LL*x.S*y.F>1LL*y.S*x.F;
}
vector<ll> max_knapsack(int w,vector<P> &tmp)
{
    vector<ll> dp(w+1),ndp(w+1);
    int n=(int)tmp.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
            if(j<tmp[i-1].F) ndp[j]=dp[j]; else ndp[j]=max(dp[j],dp[j-tmp[i-1].F]+tmp[i-1].S);
        swap(dp,ndp);
    }
    return dp;
}
vector<ll> min_knapsack(int w,vector<P> &tmp)
{
    vector<ll> dp(w+1),ndp(w+1);
    for(int i=1;i<=w;i++) dp[i]=INF;
    int n=(int)tmp.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
            if(j<tmp[i-1].F) ndp[j]=dp[j]; else ndp[j]=min(dp[j],dp[j-tmp[i-1].F]+tmp[i-1].S);
        swap(dp,ndp);
    }
    return dp;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        v.clear(); l.clear(); r.clear();
        for(int i=1;i<=n;i++)
        {
            int w,val;
            scanf("%d%d",&w,&val);
            v.push_back(P(w,val));
        }
        sort(v.begin(),v.end(),cmp);
        l.clear(); r.clear();
        int s=0,need=0;
        bool f=true;
        ll ans=0;
        for(int i=0;i<(int)v.size();i++)
        {
            s+=v[i].F;
            ans+=v[i].S;
            if(s>m)
            {
                s-=v[i].F;
                ans-=v[i].S;
                f=false;
                need=m-s;
            }
            if(f) l.push_back(v[i]); else r.push_back(v[i]);
        }
        if(f) printf("%lld\n",ans);
        else
        {
            vector<ll> lhs=max_knapsack(200,r),rhs=min_knapsack(200,l);
            ll res=0;
            for(int i=0;i<=200-need;i++) res=max(res,lhs[need+i]-rhs[i]);
            printf("%lld\n",ans+res);
        }
        
    }
    return 0;
}