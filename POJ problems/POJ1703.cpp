#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100001
using namespace std;
int par[2*MAXN],rank[2*MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y) return;
    if(rank[x]<rank[y])
        par[x]=y;
    else
    {
      par[y]=x;
      if(rank[x]==rank[y]) rank[x]++;
    }
    return;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int n,m,x,y,t;
    char c;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
    scanf("%d %d",&n,&m);getchar();
    init(2*n);
    if(n==2)
    {
        unite(1,2+n);
        unite(2+n,1);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%c %d %d",&c,&x,&y);getchar();
        if(c=='D')
        {
            unite(x,y+n);
            unite(x+n,y);
        }
        if(c=='A')
        {

                if(same(x,y)) printf("In the same gang.\n");
                else if(same(x,y+n))printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
    }
    }
    return 0;
}