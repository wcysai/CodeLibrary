#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,m,p[MAXN],r[MAXN];
bool ok[MAXN];
struct prc
{
    int w,a,b;
}save[MAXN];
bool cmp(prc x,prc y)
{
    return x.w>y.w;
}
void init(int n)
{
    for(int i=0;i<n;i++)
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
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&save[i].a,&save[i].b,&save[i].w);
    sort(save,save+m,cmp);
    int ans=0;
    init(n);
    for(int i=0;i<m;i++)
    {
        int x=find(save[i].a);
        int y=find(save[i].b);
		if(ok[x]&&ok[y])continue;
		if(x==y) ok[x]=true; else p[x]=y, ok[y]=ok[x]||ok[y];
		ans+=save[i].w;
    }
    printf("%d\n",ans);
    return 0;
}

