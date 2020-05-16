#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,dep[MAXN],f[MAXN],p[MAXN];
vector<int> G[MAXN];
vector<P> ans;
vector<int> tmp1;
vector<int> tmp2;
bool vis[MAXN];
bool flag;
bool cmp(int x,int y)
{
    return dep[x]>dep[y];
}
void dfs(int v,int fa,int d)
{
    vis[v]=true; f[v]=fa; dep[v]=d;
    tmp1.push_back(v);
    tmp2.push_back(p[v]);
    for(auto to:G[v])
    {
        if(vis[to]) continue;
        dfs(to,v,d+1);
    }
}
void solve(int v)
{
    dfs(v,0,0);
    if(!flag) return;
    sort(tmp1.begin(),tmp1.end());
    sort(tmp2.begin(),tmp2.end());
    if(tmp1.size()!=tmp2.size()) {flag=false; return;}
    for(int i=0;i<(int)tmp1.size();i++)
    {
        if(tmp1[i]!=tmp2[i])
        {
            flag=false;
            return;
        }
    }
    sort(tmp1.begin(),tmp1.end(),cmp);
    for(int i=0;i<(int)tmp1.size();i++)
    {
        int v=tmp1[i],u;
        for(int j=0;j<(int)tmp1.size();j++)
        {
            if(p[tmp1[j]]==v)
            {
                u=tmp1[j];
                break;
            }
        }
        int save=u;
        vector<int> vv,uu;
        while(dep[v]>dep[u]) {vv.push_back(v); v=f[v];}
        while(v!=u) {vv.push_back(v); uu.push_back(u); v=f[v]; u=f[u];}
        uu.push_back(u);
        u=save;
        for(int i=1;i<(int)uu.size();i++)
        {
            ans.push_back(P(u,uu[i]));
            swap(p[u],p[uu[i]]);
            u=uu[i];
        }
        for(int i=(int)vv.size()-1;i>=0;i--)
        {
            ans.push_back(P(u,vv[i]));
            swap(p[u],p[vv[i]]);
            u=vv[i];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    flag=true;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) if(!vis[i]) solve(i);
    if(!flag) puts("-1");
    else
    {
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    
    return 0;
}
