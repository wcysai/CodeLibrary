#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dep[MAXN],fa[MAXN];
vector<int> G[MAXN];
ll flen[MAXN],f[MAXN],glen[MAXN],g[MAXN];
ll ans;
void dfs(int v,int p)
{
    fa[v]=p;
    flen[v]=f[v]=a[v];
    vector<ll> vec;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        flen[v]=max(flen[v],a[v]+flen[to]);
        f[v]=max(f[v],f[to]);
        vec.push_back(flen[to]);
    }
    sort(vec.begin(),vec.end(),greater<ll>());
    if(vec.size()>=1) f[v]=max(f[v],vec[0]+a[v]);
    if(vec.size()>=2) f[v]=max(f[v],vec[0]+vec[1]+a[v]);
}
void dfs2(int v,int p)
{
    multiset<ll> sf,sflen;
    for(auto to:G[v])
    {
        if(to==p) continue;
        sflen.insert(flen[to]);
        sf.insert(f[to]);
    }
    sflen.insert(glen[p]);
    int tot=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        //printf("to=%d\n",to);
        sf.erase(sf.find(f[to]));
        sflen.erase(sflen.find(flen[to]));
        glen[to]=a[to]+glen[v];
        if(sflen.size()) glen[to]=max(glen[to],a[to]+a[v]+(*(--sflen.end())));
        if(sf.size()) ans=max(ans,f[to]+(*(--sf.end())));
        ans=max(ans,f[to]+g[v]);
        if(sflen.size()>=2) 
        {
            auto it=sflen.end(); it--;
            ll tmp=*it; it--; tmp+=(*it);
            ans=max(ans,f[to]+a[v]+tmp);
        }
        g[to]=glen[to];
        if(sf.size()) g[to]=max(g[to],*(--sf.end()));
        sf.insert(f[to]);
        sflen.insert(flen[to]);
    }
    if(sflen.size()>=4) 
    {
        auto it=sflen.end();
        ll res=0;
        for(int i=0;i<4;i++) {it--; res+=(*it);}
        ans=max(ans,res);
    }
    //printf("v=%lld flen=%lld f=%lld glen=%lld g=%lld\n",v,flen[v],f[v],glen[v],g[v]);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    g[1]=glen[1]=a[1];
    dfs2(1,0);
    printf("%lld\n",ans);
    return 0;
}

