#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<assert.h>
#define MAXV 100005
#define MAXN 3005
#define MAXNUM 1000005
using namespace std;
int n,p;
int match[MAXV];
bool used[MAXV];
int prime[MAXV];
bool is_prime[MAXNUM];
int a[MAXV];
vector<int> G[MAXV];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}

void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=p;v<p+n;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
        if(res<v-p+1) return res;
    }
    return res;
}
int main()
{
    p=sieve(1000000);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for(int j=0;j<p;j++)
        {
            if(a[i]%prime[j]==0)
            {
                add_edge(j,p+i);
                while(a[i]%prime[j]==0) a[i]=a[i]/prime[j];
            }
            if(a[i]==1) break;
        }
    }
    printf("%d\n",bipartite_matching());
    return 0;
}
