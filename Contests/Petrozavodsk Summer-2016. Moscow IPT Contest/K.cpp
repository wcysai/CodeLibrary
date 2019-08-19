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
vector<int> v[MAXN];
int n,M,a[MAXN],p[MAXN],cnt;
ll ans;
vector<P> dis;
set<P> s;
P best[MAXN];
int nxt[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        v[i].push_back(i);
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void unite(int x,int y,int w)
{
    x=find(x); y=find(y);
    if(x==y) return;
    cnt++; ans+=w;
    if((int)v[x].size()>(int)v[y].size()) swap(x,y);
    p[x]=y;
    v[y].insert(v[y].end(),v[x].begin(),v[x].end());
    v[x].clear();
}
void go()
{
    for(int i=1;i<=n;i++) best[i]=P(INF,-1);
    nxt[n-1]=n;
    for(int i=n-2;i>=0;i--)
    {
        if(find(dis[i].S)!=find(dis[i+1].S)) nxt[i]=i+1; else nxt[i]=nxt[i+1];
    }
    for(int i=0;i<n;i++)
    {
        int cmp=find(dis[i].S);
        if(cmp==find(dis[0].S)) best[cmp]=min(best[cmp],P(dis[i].F+dis[nxt[0]].F,dis[nxt[0]].S));
        else best[cmp]=min(best[cmp],P(dis[i].F+dis[0].F,dis[0].S));
    }
    int now=0;
    for(int i=n-1;i>=0;i--)
    {
        while(now<n&&(now==i||dis[now].F+dis[i].F<M)) now++;
        if(now>=n) break;
        int cmp=find(dis[i].S);
        if(cmp==find(dis[now].S))
        {
            if(nxt[now]<n) best[cmp]=min(best[cmp],P(dis[i].F+dis[nxt[now]].F-M,dis[nxt[now]].S));
        }
        else best[cmp]=min(best[cmp],P(dis[i].F+dis[now].F-M,dis[now].S));
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i].size()) continue;
        unite(i,best[i].S,best[i].F);
    }
}
int main()
{
    scanf("%d%d",&n,&M);
    init(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dis.push_back(P(a[i],i));
    }
    sort(dis.begin(),dis.end());
    while(cnt<n-1)
    {
        go();
        //printf("cnt=%d\n",cnt);
    }
    printf("%lld\n",ans);
    return 0;
}
