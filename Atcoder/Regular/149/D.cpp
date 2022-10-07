#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x[MAXN],d[MAXN];
int l,r,shift,ans[MAXN],p[MAXN];
void init()
{
    for(int i=1;i<=2000000;i++) p[i]=i;
}
int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;
    p[x]=y;
}
void go(int x,int y,int c)
{
    assert(x>=1&&x<=1000000);
    assert(y>=1&&y<=1000000);
    if(c==0)
    {
        unite(x,y);
        unite(1000000+x,1000000+y);
    }
    else
    {
        unite(x,1000000+y);
        unite(1000000+x,y);
    }
}
P query(int x)
{
    assert(x>=1&&x<=1000000);
    int fa=find(x),fb=fa;
    if(fa>1000000) fa-=1000000;
    if(ans[fa]) return P(0,ans[fa]);
    P p=P(1,fa-shift);
    if(fb>1000000) p.S=-p.S;
    return p;
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&d[i]);
    l=1,r=1000000,shift=0;//shift: l+shift is at l
    for(int i=1;i<=m;i++)
    {
        if(l>r) break;
        if(l>0)
        {
            if(l>d[i]||r<d[i]) {l-=d[i]; r-=d[i]; shift+=d[i];}
            else
            {
                int m=d[i];
                ans[m+shift]=i;
                int len1=m-l,len2=r-m;
                if(len1<=len2)
                {
                    for(int j=l;j<m;j++) go(j+shift,2*m-j+shift,1);
                    shift=m+shift;
                    l=1; r-=d[i];
                }
                else
                {
                    for(int j=m+1;j<=r;j++) go(j+shift,2*m-j+shift,1);
                    shift+=d[i];
                    l-=d[i]; r=-1;
                }
            }
        }
        else
        {
            if(r<-d[i]||l>-d[i]) {l+=d[i]; r+=d[i]; shift-=d[i];}
            else
            {
                int m=-d[i];
                ans[m+shift]=i;
                int len1=m-l,len2=r-m;
                if(len1<=len2)
                {
                    for(int j=l;j<m;j++) go(j+shift,2*m-j+shift,1);
                    shift=m+shift;
                    l=1; r+=d[i];
                }
                else
                {
                    for(int j=m+1;j<=r;j++) go(j+shift,2*m-j+shift,1);
                    shift-=d[i];
                    l+=d[i]; r=-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        P p=query(x[i]);
        if(p.F==0) printf("Yes "); else printf("No ");
        printf("%d\n",p.S);
    }
    return 0;
}

