#include<bits/stdc++.h>
#define MAXV 1005
#define MAXE 1005
#define INF 100000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
struct edge
{
    int to;
    int cost;
};
int V,E,Q;
vector<edge> G[MAXV];
bool used[MAXV];
P dis(int x,int y)
{
    int dist[MAXV];
    int dist2[MAXV];
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dist,dist+V,INF);
    fill(dist2,dist2+V,INF);
    memset(used,false,sizeof(used));
    dist[x]=0;
    que.push(P(x,0));
    used[x]=true;
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int v=p.S,d=p.F;
        if(dist2[v]<d) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(used[e.to]) continue;
            int d2=d+e.cost;
            if(dist[e.to]>d2)
            {
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
                used[e.to]=true;
            }
            if(dist2[e.to]>d2&&dist[e.to]<d2)
            {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
                used[e.to]
            }
        }
    }
    return make_pair(dist[y],dist2[y]);
}
int main()
{

    scanf("%d%d%d",&V,&E,&Q);
    for(int i=0;i<V;i++)
        G[i].clear();
    for(int i=0;i<E;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        G[x].push_back((edge){y,1});
        G[y].push_back((edge){x,1});
    }
    for(int i=0;i<Q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        P ans=dis(x,y);
        printf("%d %d\n",ans.F,ans.S);
        if(ans.F!=INF&&ans.S==INF) printf("1\n"); else printf("0\n");
    }
    return 0;
}
