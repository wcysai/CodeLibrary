/*************************************************************************
    > File Name: METEORS.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 22:52:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n,m,q,l[MAXN],r[MAXN],v[MAXN],a[MAXN];
int ans[MAXN];
vector<int> G[MAXN],owners;
struct segtree
{
    ull val[4*MAXN];
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>=x&&r<=y) 
        {
            val[k]+=v; 
            return;
        }
        int mid=(l+r)/2;
        if(val[k]!=0) {val[k*2]+=val[k];val[k*2+1]+=val[k];val[k]=0;}
        if(mid>=x) update(k*2,l,mid,x,y,v);
        if(mid+1<=y) update(k*2+1,mid+1,r,x,y,v);
    }
    ull query(int k,int l,int r,int pos)
    {
        if(l==r) return val[k];
        int mid=(l+r)/2;
        if(val[k]!=0) {val[k*2]+=val[k];val[k*2+1]+=val[k];val[k]=0;}
        if(pos<=mid) return query(k*2,l,mid,pos); else return query(k*2+1,mid+1,r,pos);
    }
}seg;
void add(int pos,int vv)
{
    int val=vv*v[pos];
    if(l[pos]<=r[pos]) seg.update(1,1,m,l[pos],r[pos],val);
    else
    {
        seg.update(1,1,m,l[pos],m,val);
        seg.update(1,1,m,1,r[pos],val);
    }
}
void solve(int ll,int rr,vector<int> &vv,int &now)
{
    if(vv.empty()) return;
    int mid=(ll+rr)/2;
    while(now<mid) add(++now,1);
    while(now>mid) add(now--,-1);
    vector<int> L,R;
    for(int i:vv)
    {
        ull res=0;
        for(int j:G[i])
        {
            res+=seg.query(1,1,m,j);
            if(res>=(ull)a[i]) break;
        }
        if(res>=(ull)a[i])
        {
            L.push_back(i);
            ans[i]=rr;
        }
        else R.push_back(i);
    }
    vv.clear();vv.shrink_to_fit();
    if(ll<rr)
    {
        solve(ll,mid,L,now);
        solve(mid+1,rr,R,now);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) 
    {
        int x;
        scanf("%d",&x);
        G[x].push_back(i);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) scanf("%d%d%d",&l[i],&r[i],&v[i]);
    for(int i=1;i<=n;i++) owners.push_back(i);
    int act_tree=0;
    solve(1,q,owners,act_tree);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) printf("%d\n",ans[i]);
        else puts("NIE");
    }
    return 0;
}

