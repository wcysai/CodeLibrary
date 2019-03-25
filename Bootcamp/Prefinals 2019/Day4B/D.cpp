#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 12000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot,cnt,a[MAXN],root[MAXN];
int lson[MAXM],rson[MAXM],sum[MAXM],dif[MAXM],uni[MAXM];
void pushup(int k)
{
    sum[k]=sum[lson[k]]+sum[rson[k]];
    dif[k]=dif[lson[k]]+dif[rson[k]];
    uni[k]=uni[lson[k]]+uni[rson[k]];
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) {sum[k]=dif[k]=0; return;}
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
        dif[k]=(sum[k]==0?0:1);
        uni[k]=(sum[k]==1?1:0);
        return;
    }
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    pushup(k);
}
int querysum(int &k,int l,int r,int x,int y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return sum[k];
    int mid=(l+r)/2;
    return querysum(lson[k],l,mid,x,y)+querysum(rson[k],mid+1,r,x,y);
}
int querydif(int &k,int l,int r,int x,int y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return dif[k];
    int mid=(l+r)/2;
    return querydif(lson[k],l,mid,x,y)+querydif(rson[k],mid+1,r,x,y);
}
int queryuni(int &k,int l,int r,int x,int y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return uni[k];
    int mid=(l+r)/2;
    return queryuni(lson[k],l,mid,x,y)+queryuni(rson[k],mid+1,r,x,y);
}
char str[10];
int main()
{
    scanf("%d%d",&n,&m);
    build(root[0],1,m);
    ll sumans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int old,p,v;
        if(str[0]=='a')
        {
            scanf("%d",&p);
            insert(root[i],root[i-1],1,m,p,1);
        }
        else if(str[0]=='r')
        {
            scanf("%d",&p);
            if(querysum(root[i-1],1,m,p,p)>=1) insert(root[i],root[i-1],1,m,p,-1); else root[i]=root[i-1];
        }
        else if(str[0]=='d')
        {
            scanf("%d",&old); old=(old+sumans)%i;
            printf("%d\n",querydif(root[old],1,m,1,m));
            sumans+=querydif(root[old],1,m,1,m);
            root[i]=root[i-1];
        }
        else if(str[0]=='u')
        {
            scanf("%d",&old); old=(old+sumans)%i;
            printf("%d\n",queryuni(root[old],1,m,1,m));
            sumans+=queryuni(root[old],1,m,1,m);
            root[i]=root[i-1];
        }
        else
        {
            scanf("%d%d",&v,&old); old=(old+sumans)%i;
            printf("%d\n",querysum(root[old],1,m,v,v));
            sumans+=querysum(root[old],1,m,v,v);
            root[i]=root[i-1];
        }
    }
    return 0;
}


