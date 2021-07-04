#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,q;
int p[MAXN],r[MAXN],sz[MAXN];
ll ans=0;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=1;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    ans+=1LL*sz[x]*sz[y];
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else
    {
        p[y]=x;
        sz[x]+=sz[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<pair<int,P> > event;
ll res[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        init(n);
        event.clear();
        for(int i=0;i<m;i++)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            event.push_back(make_pair(k,P(x,y)));
        }
        for(int i=0;i<q;i++)
        {
            int p;
            scanf("%d",&p);
            event.push_back(make_pair(p,P(-INF,i)));
        }
        sort(event.begin(),event.end(),greater<pair<int,P> >());
        ans=0;
        for(auto x:event)
        {
            if(x.S.F==-INF) res[x.S.S]=ans;
            else unite(x.S.F,x.S.S);
        }
        for(int i=0;i<q;i++) printf("%lld\n",res[i]);
    }
    return 0;
}