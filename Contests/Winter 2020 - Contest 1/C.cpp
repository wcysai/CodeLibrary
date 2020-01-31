#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P x[MAXN];
vector<pair<P,P> > v;
vector<int> G[MAXN];
int color[MAXN];
bool dfs(int v,int c)
{
    color[v]=c;
    for(auto to:G[v])
    {
        if(color[to]==c) return false;
        if(!color[to]&&!dfs(to,-c)) return false; 
    }
    return true;
}
bool check(ll dist)
{
    v.clear();
    double sl=sqrt(dist);
    for(int i=1;i<=n;i++)
    {
        int xid=(int)floor(x[i].F/sl),yid=(int)floor(x[i].S/sl);
        v.push_back(make_pair(P(xid,yid),x[i]));
    }
    sort(v.begin(),v.end());
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(v[i].F==v[i-1].F) cnt++;
        else cnt=1;
        if(cnt>=10) return false;
    }
    for(int i=0;i<n;i++) G[i].clear();
    for(int i=0;i<n;i++)
    {
        for(int x=v[i].F.F-1;x<=v[i].F.F+1;x++)
            for(int y=v[i].F.S-1;y<=v[i].F.S+1;y++)
            {
                int id=lower_bound(v.begin(),v.end(),make_pair(P(x,y),P(0,0)))-v.begin();
                for(int j=id;j<n&&v[j].F==P(x,y);j++)
                {
                    if(i==j) continue;
                    if(1LL*(v[j].S.F-v[i].S.F)*(v[j].S.F-v[i].S.F)+1LL*(v[j].S.S-v[i].S.S)*(v[j].S.S-v[i].S.S)<dist) G[i].push_back(j);
                }
            }
    }
    for(int i=0;i<n;i++) color[i]=0;
    for(int i=0;i<n;i++)
    {
        if(!color[i]&&!dfs(i,1)) return false;
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i].F,&x[i].S);
        sort(x+1,x+n+1);
        ll l=0,r=INF;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}