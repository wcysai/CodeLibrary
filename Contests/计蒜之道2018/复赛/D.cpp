/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 14:57:39
 ************************************************************************/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXV 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,V;
vector<int> G[MAXV],GG[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV],usd[MAXV];
int cmp[MAXV],cnt[MAXV],ans;
bool f1,f2;
int a[MAXN],b[MAXN];
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    f1=str[0]=='C'? false:true;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cin>>str;
    f2=str[0]=='C'?false:true;
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    if(!f1&&!f2)
    {
        bool f=true;
        for(int i=0;i<n;i++)
            if(a[i]!=b[i])
            {
                f=false;
                break;
            }
        if(f) puts("0"); else puts("-1");
        return 0;
    }
    if(f1&&f2)
    {
        init(100000);
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(same(a[i],b[i])) continue;
            unite(a[i],b[i]);
            ans++;
        }
        printf("%d\n",ans);
        return 0;
    }
    if(f2)
    {
        for(int i=0;i<n;i++)
            swap(a[i],b[i]);
    }
    memset(usd,false,sizeof(usd));
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i]) 
        {
            add_edge(a[i],b[i]);
            add_edge(b[i],a[i]);
        }
    }
    V=100000;
    int num=scc();
    for(int i=1;i<=100000;i++)
        GG[cmp[i]].push_back(i);
    for(int i=1;i<=100000;i++)
        G[i].clear(),rG[i].clear();
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) add_edge(a[i],b[i]);
    scc();
    for(int i=0;i<num;i++)
    {
        if(GG[i].size()==1) continue;
        bool f=true;
        for(int j=0;j<(int)GG[i].size();j++)
        {
            int v=cmp[GG[i][j]];
            if(usd[v])
            {
                f=false; 
                break;
            }
            usd[v]=true;
        }
        if(f) ans+=GG[i].size()-1; else ans+=GG[i].size();
    }
    printf("%d\n",ans);
    return 0;
}
