#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<double> vec;
int n,x,tot;
int a[MAXN];
vector<pair<int,double> > save[4*MAXN];
map<P,int> mp;
double tmp[MAXM];
bool vis[MAXN][MAXN];
bool vv[MAXM];
void combine(int x,int y,int z)
{
    vector<int> id;
    for(auto i:save[x])
        for(auto j:save[y])
        {
            if(!tmp[i.F]) id.push_back(i.F);
            if(!tmp[j.F]) id.push_back(j.F);
            tmp[i.F]+=i.S*j.S*(double)(i.F)/(double)(i.F+j.F);
            tmp[j.F]+=i.S*j.S*(double)(j.F)/(double)(i.F+j.F);
        }
    
    for(auto x:id) 
    {
        if(!vv[x]) save[z].push_back(make_pair(x,tmp[x]));
        vv[x]=true;
    }
    for(auto x:id) vv[x]=false,tmp[x]=0;
}
int compute(int l,int r)
{
    int k;
    if(vis[l][r]) return mp[P(l,r)];
    vis[l][r]=true;
    if(l==r||((r-l)&1))
    {
        mp[P(l,r)]=++tot; 
        k=mp[P(l,r)];
    }
    if(l==r)
    {
        save[k].push_back(make_pair(a[l],1.0));
        return k;
    }
    if((r-l)&1)
    {
        int mid=(l+r)/2;
        int lid=compute(l,mid); int rid=compute(mid+1,r);
        combine(lid,rid,k);
    }
    else
    {
        int mid=(l+r)/2;
        compute(l,mid); compute(mid+1,r);
        compute(mid,r); compute(l,mid-1);
    }
    return k;
}
double ans;
void solve(int l,int r,int d)
{
    if(l==1&&r==n) return;
    int nl,nr,id;
    if(r%(d<<1)==0)
    {
        nr=l-1,nl=(nr-d+1);
        id=mp[P(nl,nr)];
        l-=d;
    }
    else
    {
        nl=r;nr=nl+d-1;
        id=mp[P(nl,nr)];
        r+=d;
    }
    double nans=0.0;
    for(auto p:save[id]) nans+=p.S*(double)x/(double)(x+p.F);
    ans=ans*nans;
    solve(l,r,d<<1);
}
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    compute(1,n-1);
    for(int i=1;i<=n;i++)
    {
        ans=1.0;
        solve(i,i,1);
        printf("%.10f\n",ans);
    }
    return 0;
}