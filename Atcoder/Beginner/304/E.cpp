#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef pair<int,int> P;
int n,m,k,q,p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
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
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        unite(u,v);
    }
    set<P> s;
    bool f=true;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int u,v; scanf("%d%d",&u,&v);
        u=find(u); v=find(v);
        if(u>v) swap(u,v);
        if(u==v) {f=false; continue;}
        s.insert(P(u,v));
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int u,v; scanf("%d%d",&u,&v);
        u=find(u); v=find(v);
        if(u>v) swap(u,v);
        if(!f) {puts("No"); continue;}
        if(s.count(P(u,v))) puts("No"); else puts("Yes");
    }
    return 0;
}
