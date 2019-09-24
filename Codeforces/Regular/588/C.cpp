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
int n,m,q,deg[MAXN];
vector<int> G[MAXN];
bool isbig[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[u]++; deg[v]++;
        if(u>v) res[u]++,ser[v]++; else res[v]++,ser[u]++;
    }
    for(int i=1;i<=n;i++)
        for(auto to:G[i])
            if(val[i]>val[to]) st[v]+=res[to]; else ed[v]+=ser[to];
    int blocks=400;
    for(int i=1;i<=n;i++)
    {
        for(auto to:G[i])
        {
            if(deg[to]>=blocks)
            {
                BG[i].push_back(to);
                sum[to]+=res[i];
            }
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int v;
        scanf("%d",&v);
        if(deg[v]<blocks)
        {
            int last=res[v];
            ans-=1LL*res[v]*(deg[v]-res[v]);
            ans-=st[v]; ans-=ed[v];
            for(auto to:G[v])
            {
                if(val[to]>val[v])
                {
                    ans-=res[v];
                    res[to]--;
                }
            }
            val[v]=n+i;
            for(auto to:G[v]) ans+=res[to];
            for(auto to:BG[v])
            {
                sum[to]+=deg[v]-res[v];
            }
        }
    }
}
