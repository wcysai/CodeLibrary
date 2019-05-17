#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define BASE1 21391
#define BASE2 19260817
#define MOD1 1000000009
#define MOD2 998244353
#define CONS1 4920132
#define CONS2 432094
#define ST1 930213
#define ST2 39029301
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,tot;
unsigned long long hsh1[MAXN],hsh2[MAXN];
vector<int> v;
map<P,int> mp;
void dfs(int v,int p)
{
    hsh1[v]=ST1; hsh2[v]=ST2;
    vector<ll> v1,v2;
    v1.clear(); v2.clear();
    for(auto to:G[v]) 
    {
        if(to==p) continue;
        dfs(to,v);
        v1.push_back(hsh1[to]);
        v2.push_back(hsh2[to]);
    }
    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
    for(int i=0;i<(int)v1.size();i++)
    {
        hsh1[v]=(1LL*hsh1[v]*BASE1+v1[i]+CONS1)%MOD1;
        hsh2[v]=(1LL*hsh2[v]*BASE2+v2[i]+CONS2)%MOD2;
    }
    hsh1[v]=1LL*hsh1[v]*hsh1[v]%MOD1;
    hsh2[v]=1LL*hsh2[v]*hsh2[v]%MOD2;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p; scanf("%d",&p);
        G[p].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(mp.find(P(hsh1[i],hsh2[i]))==mp.end()) mp[P(hsh1[i],hsh2[i])]=++tot;
        printf("%d ",mp[P(hsh1[i],hsh2[i])]);
    }
    return 0;
}
