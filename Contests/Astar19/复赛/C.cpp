#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
int l[MAXN],r[MAXN];
bool isson[MAXN];
int root,sz[MAXN],mini[MAXN],label[MAXN];
int p[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v)
{
    sz[v]=1; mini[v]=v;
    if(l[v])
    {
        dfs(l[v]); sz[v]+=sz[l[v]]; mini[v]=min(mini[v],mini[l[v]]);
    }
    if(r[v])
    {
        dfs(r[v]); sz[v]+=sz[r[v]]; mini[v]=min(mini[v],mini[r[v]]);
    }
}
void solve(int v,int lb,int rb)
{
    if(!v) return;
    if(v<mini[l[v]]&&v<mini[r[v]])
    {
        if(sz[l[v]]<sz[r[v]])
        {
            label[v]=lb+sz[l[v]];
            solve(l[v],lb,lb+sz[l[v]]-1);
            solve(r[v],lb+sz[l[v]]+1,rb);
            return;
        }
        else if(sz[r[v]]<sz[l[v]])
        {
            label[v]=lb+sz[r[v]];
            solve(r[v],lb,lb+sz[r[v]]-1);
            solve(l[v],lb+sz[r[v]]+1,rb);
            return;
        }
    }
    if(mini[l[v]]<mini[r[v]])
    {
        label[v]=lb+sz[l[v]];
        solve(l[v],lb,lb+sz[l[v]]-1);
        solve(r[v],lb+sz[l[v]]+1,rb);
    }
    else
    {
        label[v]=lb+sz[r[v]];
        solve(r[v],lb,lb+sz[r[v]]-1);
        solve(l[v],lb+sz[r[v]]+1,rb);
    }
}
int main()
{
    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=233LL*p[i-1]%MOD;
    mini[0]=INF;
    memset(l,0,sizeof(l)); memset(r,0,sizeof(r));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) mini[i]=0;
        for(int i=1;i<=n;i++) isson[i]=false;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            if(l[i]) isson[l[i]]=true;
            if(r[i]) isson[r[i]]=true;
        }
        for(int i=1;i<=n;i++) if(!isson[i]) root=i;
        dfs(root);
        solve(root,1,n);
        int ans=0;
        for(int i=1;i<=n;i++) add(ans,1LL*(label[i]^i)*p[i]%MOD);
        printf("%d\n",ans);
    }
    return 0;
}
