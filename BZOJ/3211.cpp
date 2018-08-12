/*************************************************************************
    > File Name: 3211.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-10 11:16:07
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
int n,q,a[MAXN];
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
struct segtree
{
    int val[4*MAXN];
    ll sum[4*MAXN];
    void merge(int k)
    {
        val[k]=max(val[k*2],val[k*2+1]);
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r) {val[k]=sum[k]=a[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k);
    }
    void update(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(val[k]<=1) return;
        if(l==r)
        {
            val[k]=sum[k]=(int)sqrt(val[k]);
            return;
        }
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y);update(k*2+1,mid+1,r,x,y);
        merge(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return 0LL;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    seg.build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,l,r;
        read(x);read(l);read(r);
        if(x==2) seg.update(1,1,n,l,r);
        else printf("%lld\n",seg.query(1,1,n,l,r));
    }
    return 0;
}

