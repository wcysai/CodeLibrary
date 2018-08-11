/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-11 22:37:14
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN],rG[MAXN];
int mark[MAXN],deg[MAXN];//mark: 0 unvisited 1 chosen 2 dead 3 can be reached
set<P> vis;
bool used[MAXN];
vector<int> ans;
queue<int> dead;
void solve(int p)
{
        vis.erase(P(deg[p],p));
        if(mark[p]==2) return;
        ans.push_back(p);mark[p]=1;
        for(int j=0;j<(int)G[p].size();j++)
        {
            int to=G[p][j];
            if(mark[to]==2) continue;
            mark[to]=2;
            dead.push(to);
            vis.erase(P(deg[to],to));
        }
        for(int j=0;j<(int)rG[p].size();j++)
        {
            int to=rG[p][j];
            if(mark[to]==2) continue;
            mark[to]=2;
            vis.erase(P(deg[to],to));
        }
        while(dead.size())
        {
            int pp=dead.front();dead.pop();
            if(used[pp]) continue;
            used[pp]=true;
            for(int j=0;j<(int)G[pp].size();j++)
            {
                int to=G[pp][j];
                if(mark[to]!=0) continue;
                vis.erase(P(deg[to],to));
                deg[to]--;
                vis.insert(P(deg[to],to));
            }
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);rG[v].push_back(u);
        deg[v]++;
    }
    for(int i=1;i<=n;i++) vis.insert(P(deg[i],i));
    memset(mark,0,sizeof(mark));
    memset(used,false,sizeof(used));
    while(dead.size()) dead.pop();
    while(vis.size())
    {
        P p=*vis.begin();
        solve(p.F);
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}

