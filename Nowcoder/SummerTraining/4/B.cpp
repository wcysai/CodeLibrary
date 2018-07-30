/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-28 12:37:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
struct node
{
    int l,r,w;
}a[MAXN];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
struct segtree
{
    int sum[4*MAXN];
    bool lazy[4*MAXN];
    void build(int k,int l,int r)
    {
        sum[k]=0;lazy[k]=false;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void Lazy(int k)
    {
        lazy[k*2]|=lazy[k];lazy[k*2+1]|=lazy[k];
        lazy[k]=false;
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l>y||r<x) return;
        if(l>=x&&r<=y)
        {
            sum[k]=(r-l+1);
            lazy[k]=true;
            return;
        }
        Lazy(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y);update(k*2+1,mid+1,r,x,y);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    bool Query()
    {
        if(sum[1]==m) return true; else return false;
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        seg.build(1,1,m);
        for(int i=0;i<n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
        sort(a,a+n,cmp);bool f=false;
        for(int i=0;i<n;i++)
        {
            seg.update(1,1,m,a[i].l,a[i].r);
            if(seg.Query())
            {
                f=true;
                printf("%d\n",a[i].w);
                break;
            }
        }
        if(!f) puts("-1");
    }
    return 0;
}

