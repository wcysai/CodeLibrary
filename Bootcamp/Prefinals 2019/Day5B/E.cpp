#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,tot,cnt,a[MAXN],root[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM];
int last[MAXN];
void pushup(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) {sum[k]=0; return;}
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
    pushup(k);
}
void insert(int &k,int last,int l,int r,int p,int v)
{
    k=++tot;
    sum[k]=sum[last];
    if(l==r) 
    {
        sum[k]+=v; 
        return;
    }
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    pushup(k);
}
int query(int &k,int l,int r,int v)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(sum[lson[k]]>=v) return query(lson[k],l,mid,v);
    else return query(rson[k],mid+1,r,v-sum[lson[k]]);
}
char str[10];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) last[i]=n+1;
    build(root[n+1],1,n+1);
    for(int i=n;i>=1;i--)
    {
        insert(root[i],root[i+1],1,n+1,i,1);
        if(last[a[i]]!=n+1) insert(root[i],root[i],1,n+1,last[a[i]],-1);
        last[a[i]]=i;
    }
    int p=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,k,l;
        scanf("%d%d",&x,&y);
        l=(x+p)%n+1; k=(y+p)%m+1;
        p=query(root[l],1,n+1,k);
        if(p==n+1) p=0;
        printf("%d\n",p);
    }
    return 0;
}


