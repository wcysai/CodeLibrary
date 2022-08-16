#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,e,q,cur;
int u[MAXN],v[MAXN],ans[MAXN],cnt[MAXN];
int p[MAXN],r[MAXN],res[MAXN];
bool good[MAXN],asked[MAXN];
void init()
{
    cur=0;
    for(int i=1;i<=n+m;i++)
    {
        p[i]=i;
        r[i]=0;
        cnt[i]=(i<=n?1:0);
        good[i]=(i<=n?false:true);
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
    bool g=(good[x]||good[y]);
    if(r[x]<r[y]) 
    {
        p[x]=y; 
        if(g&&(!good[x])) cur+=cnt[x]; 
        if(g&&(!good[y])) cur+=cnt[y]; 
        cnt[y]+=cnt[x]; 
        good[y]=good[x]=g;
    }
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        if(g&&(!good[x])) cur+=cnt[x]; 
        if(g&&(!good[y])) cur+=cnt[y]; 
        cnt[x]+=cnt[y]; 
        good[x]=good[y]=g;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d%d",&n,&m,&e);
    init();
    for(int i=0;i<e;i++) scanf("%d%d",&u[i],&v[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++) {scanf("%d",&res[i]); res[i]--; asked[res[i]]=true;}
    for(int i=0;i<e;i++) if(!asked[i]) unite(u[i],v[i]);
    ans[q-1]=cur;
    for(int i=q-1;i>=1;i--) {unite(u[res[i]],v[res[i]]); ans[i-1]=cur;}
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

