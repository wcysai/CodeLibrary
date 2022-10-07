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
int T,n,m,q;
vector<P> G[MAXN],gr[MAXN];
int deg[MAXN],r[MAXN],a[MAXN];
vector<int> save[MAXN];
map<P,ll> mp;
bool cmp(int x,int y)
{
    return deg[x]<deg[y];
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        mp.clear();
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++) G[i].clear(),gr[i].clear();;
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            mp[P(x,y)]+2*z; mp[P(y,x)]+=2*z;
            G[x].push_back(P(y,z)); G[b].push_back(P(x,z));
            deg[x]++; deg[y]++;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) r[a[i]]=i;
        for(int i=1;i<=n;i++)
            for(auto p:G[i]) if(r[p.F]>r[i]) gr[i].push_back(p);
        for(int i=1;i<=n;i++) 
        {
            for(auto u:gr[i]) save[u.F].push_back(u.S);
            for(auto u:gr[i])
                for(auto v:gr[u])
                    for(auto cost:save[v.F])
                    {
                        mp[P(i,u.F)]+=min(v.S,cost); mp[P(u.F,i)]+=min(v.S,cost);

                    }
        }
    }
    return 0;
}

