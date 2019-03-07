#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int u[MAXN],v[MAXN],deg[MAXN];
int val[MAXN];
bool valid[MAXN];
char str[MAXN];
vector<int> G[MAXN];
int dp[MAXN];
int ans,tot;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
    deg[u]++;deg[v]++;
}
void dfs(int v,int p)
{
    dp[v]=0;
    int m1=-1,m2=-1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        tot++;
        dfs(to,v);
        dp[v]=max(dp[v],val[v]+dp[to]);
        if(dp[to]>m1)
        {
            m2=m1;
            m1=dp[to];
        }
        else if(dp[to]>m2) m2=dp[to];
    }
    if(m2!=-1) ans=max(ans,m1+m2+val[v]);
    if(m1!=-1) ans=max(ans,m1+val[v]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) 
    {
        scanf("%d%d",&u[i],&v[i]);
        add_edge(u[i],v[i]);
    }
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1;i<=n;i++) if(str[i]=='W') cnt++;
    if(cnt==0) {puts("0"); return 0;}
    else if(cnt==1) {puts("1"); return 0;}
    memset(valid,true,sizeof(valid));
    queue<int> que;
    for(int i=1;i<=n;i++) if(deg[i]==1&&str[i]=='B') que.push(i);
    while(que.size())
    {
        int p=que.front();que.pop();
        valid[p]=false;
        for(auto to:G[p])
        {
            deg[to]--;
            if(deg[to]==1&&str[to]=='B') que.push(to);
        }
    }
    for(int i=1;i<=n;i++) G[i].clear();
    memset(deg,0,sizeof(deg));
    for(int i=0;i<n-1;i++)
    {
        if(valid[u[i]]&&valid[v[i]]) add_edge(u[i],v[i]);
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(valid[i])
        {
            if(str[i]=='B') val[i]=(deg[i]&1?2:0);
            else val[i]=(deg[i]&1?0:2);
            if(val[i]==2) cnt++; 
        }
    }
    ans=0;tot=0;
    for(int i=1;i<=n;i++) 
    {
        if(valid[i])
        {
            dfs(i,0);
            break;
        }
    }
    //printf("%d %d %d\n",tot,ans,cnt);
    if(cnt==0) ans=2*tot; else ans=2*tot+cnt-ans;
    printf("%d\n",ans);
    return 0;
}

