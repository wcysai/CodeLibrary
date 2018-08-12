/*************************************************************************
    > File Name: 1453.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-10 21:50:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,mp[MAXN*MAXN];
int fa[MAXN*MAXN];
struct segtree
{
    int up[4*MAXN][MAXN],down[4*MAXN][MAXN],w[4*MAXN],b[4*MAXN];
    int find(int x)
    {
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int k,int l,int r)
    {
        int mid=(l+r)/2;
        w[k]=w[k*2]+w[k*2+1];
        b[k]=b[k*2]+b[k*2+1];
        for(int i=1;i<=n;i++) fa[up[k*2][i]]=up[k*2][i],fa[down[k*2][i]]=down[k*2][i];
        for(int i=1;i<=n;i++) fa[up[k*2+1][i]]=up[k*2+1][i],fa[down[k*2+1][i]]=down[k*2+1][i];
        for(int i=1;i<=n;i++)
        {
            if(mp[(mid-1)*n+i]==mp[mid*n+i])
            {
                int x=find(down[k*2][i]),y=find(up[k*2+1][i]);
                if(x!=y)
                {
                    if(mp[(mid-1)*n+i]) b[k]--; else w[k]--;
                    fa[y]=x;
                }
            }
        }
        for(int i=1;i<=n;i++) up[k][i]=find(up[k*2][i]),down[k][i]=find(down[k*2+1][i]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            b[k]=w[k]=0;
            for(int i=1;i<=n;i++) up[k][i]=down[k][i]=(l-1)*n+i;
            for(int i=1;i<=n;i++) 
            {
                if(i!=1&&mp[(l-1)*n+i]==mp[(l-1)*n+i-1]) up[k][i]=down[k][i]=up[k][i-1];
                else {if(mp[(l-1)*n+i]) b[k]++; else w[k]++;}
            }
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k,l,r);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l==r)
        {
            mp[(l-1)*n+y]=1-mp[(l-1)*n+y];
            b[k]=w[k]=0;
            for(int i=1;i<=n;i++) up[k][i]=down[k][i]=(l-1)*n+i;
            for(int i=1;i<=n;i++) 
            {
                if(i!=1&&mp[(l-1)*n+i]==mp[(l-1)*n+i-1]) up[k][i]=down[k][i]=up[k][i-1];
                else {if(mp[(l-1)*n+i]) b[k]++; else w[k]++;}
            }
            return;
        }
        int mid=(l+r)/2;
        if(x<=mid) update(k*2,l,mid,x,y); else update(k*2+1,mid+1,r,x,y);
        merge(k,l,r);
    }
    void query()
    {
        printf("%d %d\n",b[1],w[1]);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&mp[(i-1)*n+j]);
    seg.build(1,1,n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        seg.update(1,1,n,x,y);
        seg.query();
    }
    return 0;
}

