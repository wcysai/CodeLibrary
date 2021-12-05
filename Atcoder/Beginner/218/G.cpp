#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 2000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],u[MAXN],v[MAXN];
vector<int> G[MAXN];
multiset<int> l,r;
int val[MAXN],dp[MAXN];
void adjust()
{
    if(l.size()>=r.size()+2) {r.insert(*(--l.end())); l.erase(--l.end());}
    if(r.size()>=l.size()+2) {l.insert(*(r.begin())); r.erase(r.begin());}
}
void add(int v)
{
    if(!l.size()||(*(--l.end())<=v)) r.insert(v); else l.insert(v);
    adjust();
}
void erase(int v)
{
    if(l.count(v)) l.erase(l.find(v)); else r.erase(r.find(v));
    adjust();
}
int get_median()
{
    if(l.size()==r.size()) return (*(--l.end())+*(r.begin()))/2;
    else if(l.size()==r.size()+1) return *(--l.end());
    else return *r.begin();
}
void dfs(int v,int p,int d)
{
    add(a[v]);
    if(d&1) dp[v]=INF; else dp[v]=-INF;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
        if(d&1) dp[v]=min(dp[v],dp[to]); else dp[v]=max(dp[v],dp[to]);
    }
    if(dp[v]==-INF||dp[v]==INF) dp[v]=get_median();
    erase(a[v]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++) 
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    dfs(1,0,0);
    printf("%d\n",dp[1]);
    return 0;
}