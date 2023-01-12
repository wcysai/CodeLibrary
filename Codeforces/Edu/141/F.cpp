#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> G[MAXN];
int match[MAXN];
bool used[MAXN];
int num[2][MAXN],tot;
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
    for(int v=1;v<=tot;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            int now=i; tot++;
            while(!used[now]){
                num[0][now]=tot; used[now]=true;
                now=a[now];
            }
        }
    }
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            int now=i; tot++;
            while(!used[now]){
                num[1][now]=tot; used[now]=true;
                now=b[now];
            }
        }
    }
    for(int i=1;i<=n;i++) add_edge(num[0][i],num[1][i]);
    printf("%d\n",n-bipartite_matching());
    set<P> s; vector<int> ans;
    for(int i=1;i<=tot;i++) if(match[i]&&match[i]>i) s.insert(P(i,match[i]));
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=1;i<=n;i++){
        if(s.count(P(num[0][i],num[1][i]))){
            s.erase(P(num[0][i],num[1][i]));
            used[i]=true;
        }
    }
    for(int x=1;x<=n;x++) if(!used[x]) printf("%d ",x);
    puts("");
    return 0;
}

