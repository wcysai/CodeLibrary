#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 998244353
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,a[MAXN],prime[MAXN],mu[MAXN],phi[MAXN];
bool is_prime[MAXN];
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    mu[1]=1; phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=MOD-1; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=i%prime[j]?phi[i]*(prime[j]-1):phi[i]*prime[j];
            mu[i*prime[j]]=i%prime[j]?MOD-mu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<int> v[MAXN];
vector<int> divi[MAXN];
bool vis[MAXN],has[MAXN];
int sz[MAXN];
vector<int> tmp;
void dfs(int v)
{
    vis[v]=true; sz[v]=1; tmp.push_back(v);
    for(auto to:G[v])
    {
        if(!vis[to]&&has[to]) 
        {
            dfs(to);
            sz[v]+=sz[to];
        }
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
    int p=sieve(100000);
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            divi[j].push_back(i);
    for(int i=1;i<=n;i++)
        for(auto x:divi[a[i]])
            v[x].push_back(i);
    int ans=0;
    for(int i=1;i<=100000;i++)
    {
        // printf("%d %d\n",i,(int)v[i].size());
        for(auto x:v[i]) has[x]=true;
        int ret=0;
        for(auto x:v[i])
        {
            if(!vis[x])
            {
                tmp.clear();
                dfs(x);
                int res=0;
                for(auto x:tmp) add(res,1LL*sz[x]*((int)tmp.size()-sz[x])%MOD);
                add(res,(1LL*(int)tmp.size()*((int)tmp.size()-1)/2)%MOD);
                add(ret,1LL*res*phi[i]%MOD);
            }
        }
        //if(ret) printf("i=%d ret=%d\n",i,ret);
        add(ans,ret);
        for(auto x:v[i]) has[x]=false,vis[x]=false;
    }
    printf("%d\n",ans);
    return 0;
}

