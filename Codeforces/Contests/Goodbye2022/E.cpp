#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],ans;
int pr[MAXN],has[MAXN];
int u[MAXN],v[MAXN],invall;
int pu[MAXN],pv[MAXN];//pu: prob from u to v, pv: prob from v to u
int sz[MAXN];
vector<P> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int vv,int p,int id)
{
    sz[vv]=(has[vv]?1:0); 
    for(auto e:G[vv])
    {
        int to=e.F,toid=e.S;
        if(to==p) continue;
        dfs(to,vv,toid);
        sz[vv]+=sz[to];
    }
    if(id!=-1) 
    {
        int mvup=(vv==u[id]?pu[id]:pv[id]);
        int mvdown=(vv==u[id]?pv[id]:pu[id]);
        int rem=1; dec(rem,mvup); dec(rem,mvdown);
        add(ans,1LL*(sz[vv]-1)*(k-sz[vv]+1)%MOD*mvup%MOD);
        add(ans,1LL*(sz[vv]+1)*(k-sz[vv]-1)%MOD*mvdown%MOD);
        add(ans,1LL*sz[vv]*(k-sz[vv])%MOD*rem%MOD);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) 
    {
        scanf("%d",&a[i]);
        pr[a[i]]=1; has[a[i]]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(P(v[i],i)); G[v[i]].push_back(P(u[i],i));
    }
    int inv=pow_mod(2,MOD-2);
    for(int i=0;i<n-1;i++)
    {
        int s=pr[u[i]]; add(s,pr[v[i]]); s=1LL*s*inv%MOD;
        pu[i]=1LL*pr[u[i]]*(MOD+1-pr[v[i]])%MOD*inv%MOD;
        pv[i]=1LL*pr[v[i]]*(MOD+1-pr[u[i]])%MOD*inv%MOD;
        pr[u[i]]=pr[v[i]]=s;
    }
    invall=(1LL*k*(k-1)/2)%MOD;
    invall=pow_mod(invall,MOD-2);
    dfs(1,0,-1);
    ans=1LL*ans*invall%MOD;
    printf("%d\n",ans);
    return 0;
}

