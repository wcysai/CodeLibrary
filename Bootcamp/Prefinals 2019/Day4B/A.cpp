#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 8000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,cnt,a[MAXN],res[MAXN],root[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM];
void merge(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) {sum[k]=a[l]; return;}
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    merge(k);
}
void insert(int &k,int last,int l,int r,int p,int v)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]=v; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    merge(k);
}
int query(int &k,int l,int r,int x,int y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return sum[k];
    int mid=(l+r)/2;
    return max(query(lson[k],l,mid,x,y),query(rson[k],mid+1,r,x,y));
}
int main()
{
    scanf("%d",&n);
    build(root[cnt],1,n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int t,x;
        scanf("%d%d",&t,&x);
        if(x==0)
        {
            insert(root[i],root[t],1,n,res[t],0);
            ans+=query(root[i],1,n,1,n);
            res[i]=res[t]-1;
        }
        else
        {
            insert(root[i],root[t],1,n,res[t]+1,x);
            ans+=query(root[i],1,n,1,n);
            res[i]=res[t]+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


