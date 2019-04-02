#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define MAXM 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int u[MAXM],v[MAXM];
int n,s,t,m,d[MAXN];
vector<int> edges[MAXN];
int main()
{
    freopen("defence.in","r",stdin);
    freopen("defence.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    fill(d+1,d+n+1,INF);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);G[v[i]].push_back(u[i]);
    }
    queue<int> que;
    que.push(s); d[s]=0;
    while(!que.empty())
    {
        int v=que.front();que.pop();
        for(auto to:G[v])
        {
            if(d[to]==INF) 
            {
                d[to]=d[v]+1;
                que.push(to);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x=d[u[i]],y=d[v[i]];
        if(x>d[t]||y>d[t]||x==y) edges[0].push_back(i);
        else edges[min(x,y)].push_back(i);
    }
    printf("%d\n",d[t]);
    for(int i=0;i<d[t];i++)
    {
        printf("%d ",(int)edges[i].size());
        for(auto v:edges[i]) printf("%d ",v);
        puts("");
    }
    return 0;
}
