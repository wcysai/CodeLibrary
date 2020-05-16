#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
unordered_map<ull,double> dp;
int n,k,cyc=0;
double p[MAXN];
vector<P> G[MAXN];
vector<int> rG[MAXN];
ull val[MAXN];
bool vis[MAXN];
string str;
int c[MAXN];
bool flag=true;
void add_edge(int u,int v,int x)
{
    G[u].push_back(P(v,x));
    rG[v].push_back(u);
}
void solve(int v)
{
    int cnt=0;
    int cur=-1;
    queue<int> que;
    do
    {
        if(vis[v]) {cur=v; break;}
        vis[v]=true;
        que.push(v);
        cnt++;
        if(!G[v].size()) break;
        v=G[v][0].F;
    } 
    while(true);
    while(que.size())
    {
        int v=que.front();
        que.pop();
        for(auto to:rG[v])
        {
            if(vis[to]) continue;
            vis[to]=true; cnt++;
            que.push(to);
        }
    }
    if(cur==-1) 
    {
        c[cnt]++; return;
    }
    cyc++;
    int tmp=cur,s=0;
    do
    {
        s^=G[cur][0].S;
        cur=G[cur][0].F;
    } while (cur!=tmp);
    if(s) flag=false;
}
double dfs(int x,ull S)
{
    if(x==0) return 1.0;
    if(dp.find(S)!=dp.end()) return dp[S];
    int id=-1;
    int s=n;
    for(int i=1;i<=n;i++) s-=c[i]*i;
    for(int i=1;i<=n;i++) if(c[i]) {id=i; break;}
    c[id]--;
    double res=0.0;
    double tmp=dfs(x-1,S-val[id]);
    res+=tmp/(double)n*(double)id/2.0;
    if(s) res+=tmp/(double)n*(double)s;
    for(int i=id;i<=n;i++)
    {
        if(c[i])
        {
            int k=c[i]--;
            c[i+id]++;
            double tmp=dfs(x-1,S-val[i]-val[id]+val[i+id]);
            res+=tmp*(double)k/(double)n*(double)i;
            c[i+id]--;
            c[i]++;
        }
    }
    c[id]++;
    return dp[S]=res;
}
int main()
{
    val[0]=1;
    for(int i=1;i<=50;i++) val[i]=val[i-1]*19260817;
    p[0]=1.0;
    for(int i=1;i<=50;i++) p[i]=2.0*p[i-1];
    //freopen("K.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        cin>>str;
        if(str[0]=='k') add_edge(u,v,0); else add_edge(u,v,1);
    }
    memset(vis,false,sizeof(vis));
    bool f=true;
    for(int i=1;i<=n;i++) if(!vis[i]) solve(i);
    if(!flag) {printf("%.10f %.10f\n",0.0,0.0); return 0;}
    double tmp=dfs(n-k,0);
    printf("%.10f %.10f\n",p[cyc],tmp);
    return 0;
}