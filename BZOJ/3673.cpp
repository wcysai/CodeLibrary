/*************************************************************************
    > File Name: 3673.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-17 14:43:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot,root[MAXN];
int lson[MAXM],rson[MAXN],p[MAXM],rk[MAXM];
inline int read()
{
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
void build(int &k,int l,int r)
{
    k=++tot;
    if(l==r) {p[k]=l; return;}
    int mid=(l+r)/2;
    build(lson[k],l,mid);build(rson[k],mid+1,r);
}
void insert(int &k,int last,int l,int r,int pos,int val)
{
    k=++tot;
    if(l==r) {p[k]=val; rk[k]=rk[last]; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(pos<=mid) insert(lson[k],lson[last],l,mid,pos,val);
    else insert(rson[k],rson[last],mid+1,r,pos,val);
}
int query(int k,int l,int r,int pos)
{
    if(l==r) return k;
    int mid=(l+r)/2;
    if(pos<=mid) return query(lson[k],l,mid,pos);
    else return query(rson[k],mid+1,r,pos);
}
void add(int k,int l,int r,int pos)
{
    if(l==r) {rk[k]++; return;}
    int mid=(l+r)/2;
    if(pos<=mid) add(lson[k],l,mid,pos);
    else add(rson[k],mid+1,r,pos);
}
int find(int k,int x)
{
    int q=query(k,1,n,x);
    if(x==p[q]) return q;
    return find(k,p[q]);
}
int main()
{
    scanf("%d%d",&n,&m);
    build(root[0],1,n);
    for(int i=1;i<=m;i++)
    {
        int type,x,y;
        scanf("%d",&type);
        if(type==1)
        {
            root[i]=root[i-1];
            scanf("%d%d",&x,&y);
            int a=find(root[i],x),b=find(root[i],y);
            if(p[a]==p[b]) continue;
            if(rk[a]>rk[b]) swap(a,b);
            insert(root[i],root[i-1],1,n,p[a],p[b]);
            if(rk[a]==rk[b]) add(root[i],1,n,p[b]);
        }
        else if(type==2)
        {
            scanf("%d",&x);
            root[i]=root[x];
        }
        else
        {
            root[i]=root[i-1];
            scanf("%d%d",&x,&y);
            int a=find(root[i],x),b=find(root[i],y);
            if(p[a]==p[b]) puts("1"); else puts("0");
        }
    }
    return 0;
}

