#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define prev adkoadlpsa
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
ll n;
pair<ll,VI> GetMinCut(VVI &weights)
{
    ll N=weights.size();
    VI used(N),cut,best_cut;
    ll best_weight=-1;
    for(ll phase=N-1;phase>=0;phase--)
    {
        VI w=weights[0];
        VI added=used;
        ll prev,last=0;
        for(ll i=0;i<phase;i++)
        {
            prev=last;
            last=-1;
            for(ll j=1;j<N;j++) if(!added[j]&&(last==-1||w[j]>w[last])) last=j;
            if(i==phase-1)
            {
                for(ll j=0;j<N;j++) weights[prev][j]+=weights[last][j];
                for(ll j=0;j<N;j++) weights[j][prev]=weights[prev][j];
                used[last]=true;
                cut.push_back(last);
                if(best_weight==-1||w[last]<best_weight)
                {
                    best_cut=cut;
                    best_weight=w[last];
                }
            }
            else
            {
                for(ll j=0;j<N;j++) w[j]+=weights[last][j];
                added[last]=true;
            }
        }
    }
    return make_pair(best_weight,best_cut);
}
VVI G,dummy;
char str[MAXN][MAXN];
bool cut[MAXN];
bool vis[MAXN];
ll res;
int nodecnt;
void dfs(int v)
{
    vis[v]=true; nodecnt++;
    for(int i=0;i<n;i++)
    {
        if(!G[v][i]) continue;
        if(!vis[i]) dfs(i);
    }
}
void printans()
{
    for(ll i=1;i<=n;i++) if(cut[i]) printf("%lld ",i);
    puts("");
    for(ll i=1;i<=n;i++) if(!cut[i]) printf("%lld ",i);
}
bool check()
{
    ll cnt=0;
    for(ll i=0;i<n;i++)
        for(ll j=i+1;j<n;j++)
        {
            if(!dummy[i][j]) continue;
            if(cut[i+1]^cut[j+1]) cnt++;
        }
    return (res==cnt);
}
bool solve2(int n,int k) //all subsets of (1<<n) of size k
{
    int comb=(1<<k)-1;
    while(comb<(1<<n))
    {
        //operation here
        for(int i=0;i<n;i++)
        {
            if(comb&(1<<i)) cut[i+1]=true; else cut[i+1]=false;
        }
        if(check()) return true;
        int x=comb&-comb,y=comb+x;
        comb=((comb&~y)/x>>1)|y;
    }
    return false;
}
int main()
{
    scanf("%lld",&n); assert(n>=2&&n<=50); 
    for(ll i=0;i<n;i++) scanf("%s",str[i]);
    G.resize(n);dummy.resize(n);
    for(ll i=0;i<n;i++) G[i].resize(n),dummy[i].resize(n);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            G[i][j]=dummy[i][j]=str[i][j]-'0';
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        {
            if(i==j) assert(!G[i][j]);
            assert(G[i][j]==G[j][i]);
            assert(G[i][j]>=0&&G[i][j]<=1);
        }
    memset(vis,false,sizeof(vis));
    dfs(0);
    if(nodecnt<n)
    {
        for(int i=0;i<n;i++) if(vis[i]) printf("%d ",i+1);
        puts("");
        for(int i=0;i<n;i++) if(!vis[i]) printf("%d ",i+1);
        return 0;
    }
    auto ans=GetMinCut(G);
    assert(ans.F!=-1);
    assert((ll)ans.S.size()!=0); assert((ll)ans.S.size()!=n);
    memset(cut,false,sizeof(cut));
    sort(ans.S.begin(),ans.S.end());
    for(auto x:ans.S) cut[x+1]=true;
    res=ans.F;
    if(!check())
    {
        //assert(n==20);
        for(int k=1;k<=10;k++) if(solve2(n,k)) break;
        printans(); return 0;
    }
    printans();
    return 0;
}
