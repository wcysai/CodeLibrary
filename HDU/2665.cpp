/*************************************************************************
    > File Name: 2665.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 08:37:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,tot,cnt,a[MAXN],root[MAXN],v[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM];
void merge(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    sum[k]=0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
}
void insert(int &k,int last,int l,int r,int p)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]++; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p);
    else insert(rson[k],rson[last],mid+1,r,p);
    merge(k);
}
int query(int k1,int k2,int l,int r,int num)
{
    if(l==r) return l;
    int x=sum[lson[k2]]-sum[lson[k1]];
    int mid=(l+r)/2;
    if(num>x) return query(rson[k1],rson[k2],mid+1,r,num-x);
    else return query(lson[k1],lson[k2],l,mid,num);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        tot=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            v[i]=a[i];
        }
        sort(v+1,v+n+1);
        int p=unique(v+1,v+n+1)-v-1;
        build(root[cnt],1,p);
        for(int i=1;i<=n;i++)
        {
            cnt++;
            int x=lower_bound(v+1,v+p+1,a[i])-v;
            insert(root[cnt],root[cnt-1],1,p,x);
        }
        for(int i=1;i<=q;i++)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",v[query(root[l-1],root[r],1,p,k)]);
        }
    }
    return 0;
}
