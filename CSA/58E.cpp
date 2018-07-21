#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define REV 500000004
using namespace std;
typedef long long ll;
struct edge{ll to,length;};
ll N,K;
vector<edge> G[MAXN];
bool centroid[MAXN];
ll subtree_size[MAXN];
ll ans;
ll compute_subtree_size(ll v,ll p)
{
    ll c=1;
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        ll w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        c+=compute_subtree_size(G[v][i].to,v);
    }
    subtree_size[v]=c;
    return c;
}
pair<ll,ll> search_centroid(ll v,ll p,ll t)
{
    pair<ll,ll> res=make_pair((ll)INT_MAX,(ll)-1);
    ll s=1,m=0;
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        ll w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair((ll)m,(ll)v));
    return res;
}
void enumerate_paths(ll v,ll p,ll d,vector<int> &ds)
{
    ds.push_back(d);
    for(ll i=0;i<(ll)G[v].size();i++)
    {
        ll w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        enumerate_paths(w,v,d+G[v][i].length,ds);
    }
}
ll count_pairs(vector<int> &ds)
{
    ll res=0;
    sort(ds.begin(),ds.end());
    ll j=ds.size();
    for(ll i=0;i<(ll)ds.size();i++)
    {
        while(j>0&&ds[i]+ds[j-1]>K) j--;
        res+=j-(j>i?1:0);
    }
    return res/2;
}
void solve_subproblem(ll v)
{
    compute_subtree_size(v,-1);
    ll s=search_centroid(v,-1,subtree_size[v]).second;
    centroid[s]=true;
    for(ll i=0;i<(ll)G[s].size();i++)
    {
        if(centroid[G[s][i].to]) continue;
        solve_subproblem(G[s][i].to);
    }
    vector<int> ds;
    ds.push_back(0);
    for(ll i=0;i<(ll)G[s].size();i++)
    {
        if(centroid[G[s][i].to]) continue;
        vector<int> tds;
        enumerate_paths(G[s][i].to,s,G[s][i].length,tds);
        ans-=count_pairs(tds);
        ds.insert(ds.end(),tds.begin(),tds.end());
    }
    ans+=count_pairs(ds);
    centroid[s]=false;
}
void solve()
{
    ans=0;
    solve_subproblem(0);
    ll res=ans;
    K--;
    ans=0;
    solve_subproblem(0);
    K++;
    printf("%lld\n",(res-ans)*K%MOD*(K+1)%MOD*REV%MOD);
}
int main()
{
    while(scanf("%lld%lld",&N,&K)==2)
    {
        if(!N&&!K) break;
        for(ll i=0;i<N;i++)
            G[i].clear();
        for(ll i=0;i<N-1;i++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            x--;
            y--;
            G[x].push_back((edge){y,1});
            G[y].push_back((edge){x,1});
        }
        memset(centroid,false,sizeof(centroid));
        solve();
        break;
    }
    return 0;
}
