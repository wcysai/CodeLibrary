/*************************************************************************
    > File Name: 5634.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-11 00:12:53
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXP 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,a[MAXN];
int prime[MAXP],phi[MAXP];
bool is_prime[MAXP];
void genphi(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    memset(phi,0,sizeof(phi));
    prime[0]=prime[1]=false;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            if(i%prime[j]==0) break;
        }
    }
}
struct segtree
{
    int sum[4*MAXN],mx[4*MAXN],lazy[4*MAXN];
    void Lazy(int k,int l,int r)
    {
        if(!lazy[k]) return;
        int mid=(l+r)/2;
        mx[k*2]=mx[k*2+1]=lazy[k];
        sum[k*2]=(mid-l+1)*lazy[k];
        sum[k*2+1]=(r-mid)*lazy[k];
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        lazy[k]=0;
    }
    void merge(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
        mx[k]=max(mx[k*2],mx[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r) {sum[k]=mx[k]=a[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        merge(k);
    }
    void update1(int k,int l,int r,int x,int y)
    {
        if(x>r||y<l) return;
        if(mx[k]<=1) return;
        if(l>=x&&r<=y&&sum[k]==(r-l+1)*mx[k])
        {
            mx[k]=phi[mx[k]];
            sum[k]=(r-l+1)*mx[k];
            lazy[k]=mx[k];
            return;
        }
        Lazy(k,l,r);
        int mid=(l+r)/2;
        update1(k*2,l,mid,x,y);update1(k*2+1,mid+1,r,x,y);
        merge(k);
    }
    void update2(int k,int l,int r,int x,int y,int val)
    {
        if(x>r||y<l) return;
        if(l>=x&&r<=y)
        {
            sum[k]=(r-l+1)*val;
            mx[k]=val;
            lazy[k]=val;
            return;
        }
        Lazy(k,l,r);
        int mid=(l+r)/2;
        update2(k*2,l,mid,x,y,val);update2(k*2+1,mid+1,r,x,y,val);
        merge(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        Lazy(k,l,r);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
int main()
{
    genphi(10000000);
    for(int i=1;i<=20;i++) printf("%d %d\n",i,phi[i]);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        seg.build(1,1,n);
        int type,l,r,x;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d%d",&l,&r);
                seg.update1(1,1,n,l,r);
            }
            else if(type==2)
            {
                scanf("%d%d%d",&l,&r,&x);
                seg.update2(1,1,n,l,r,x);
            }
            else 
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",seg.query(1,1,n,l,r));
            }
        }
    }
    return 0;
}

