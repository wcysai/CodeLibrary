#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 50001
using namespace std;
int par[3*MAXN],rank[3*MAXN];
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
    int x,y,d,n,k,cnt;
    cnt=0;
    scanf("%d %d",&n,&k);
    init(3*n);
    for(int i=0;i<k;i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        x--;
        y--;
        if(x<0||x>=n||y<0||y>=n)
        {
            cnt++;
            continue;
        }
        if(d==1)
        {
            if(same(x,y+n)||same(x,y+2*n)) cnt++;
            else
            {
                unite(x,y);
                unite(x+n,y+n);
                unite(x+2*n,y+2*n);
            }
        }
        else
        {
            if(same(x,y)||same(x,y+2*n)) cnt++;
            else
            {
                unite(x,y+n);
                unite(x+n,y+2*n);
                unite(x+2*n,y);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}