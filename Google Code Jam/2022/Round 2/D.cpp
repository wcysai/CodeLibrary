#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,c,a[MAXN];
ll dp[2*MAXN],ndp[2*MAXN];
vector<P> l,r;
int x,y;
ll solve(vector<P> &v)
{
    sort(v.begin(),v.end(),greater<P>());
    int shift=(int)v.size();
    for(int i=0;i<=2*shift;i++) dp[i]=INF;
    dp[shift]=0;
    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=0;j<=2*shift;j++) ndp[j]=INF;
        for(int j=0;j<=2*shift;j++)
        {
            if(dp[j]==INF) continue;
            //do nothing
            int id=v[i].S;
            if(id==0) {if(j>shift) ndp[j-1]=min(ndp[j-1],dp[j]); else ndp[j-1]=min(ndp[j-1],dp[j]+2*v[i].F); }
            if(id==1) {if(j<shift) ndp[j+1]=min(ndp[j+1],dp[j]); else ndp[j+1]=min(ndp[j+1],dp[j]+2*v[i].F); }
            //flip
            if(id==0) {if(j<shift) ndp[j+1]=min(ndp[j+1],dp[j]+c); else ndp[j+1]=min(ndp[j+1],dp[j]+2*v[i].F+c);}
            if(id==1) {if(j>shift) ndp[j-1]=min(ndp[j-1],dp[j]+c); else ndp[j-1]=min(ndp[j-1],dp[j]+2*v[i].F+c);}
        }
        swap(dp,ndp);
    }
    ll ans=INF;
    for(int j=0;j<=2*shift;j++) ans=min(ans,dp[j]);
    return ans;
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        x=0; y=0;
        scanf("%d%d",&n,&c);
        l.clear(); r.clear();
        for(int i=1;i<=n;i++) 
        {
            int pos,type;
            scanf("%d%d",&pos,&type);
            if(pos<0) l.push_back(P(-pos,type));
            else r.push_back(P(pos,type));
        }
        ll ans=solve(l);
        ans+=solve(r);
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}

