#include<bits/stdc++.h>
#define MAXN 405
#define MAXM 2000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int s[MAXM],t[MAXM];
vector<P> G[MAXN];
int d[MAXN],ans[MAXM];
vector<int> save;
void bfs(int id=-1)
{
    queue<int> que;
    for(int i=1;i<=n;i++) d[i]=INF;
    d[1]=0;
    que.push(1);
    while(que.size())
    {
        int v=que.front(); que.pop();
        for(auto e:G[v])
        {
            if(e.S==id) continue;
            if(d[e.F]==INF)
            {
                d[e.F]=d[v]+1;
                if(id==-1) save.push_back(e.S);
                que.push(e.F);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&s[i],&t[i]);
        G[s[i]].push_back(P(t[i],i));
    }
    bfs();
    for(int i=0;i<m;i++) if(d[n]==INF) ans[i]=-1; else ans[i]=d[n];
    for(auto id:save)
    {
        bfs(id);
        if(d[n]==INF) ans[id]=-1; else ans[id]=d[n];
    }
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}