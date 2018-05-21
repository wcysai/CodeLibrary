#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MAXV 105
#define MAXE 3005
#define INF 1000000000
using namespace std;
struct edge
{
    int to,id;
    bool active;
};
struct pos
{
    int a,b,c,d;
}save[MAXE];
int V,E;
vector<edge>G[MAXV];
int d[MAXV],dis[MAXV];
int ans[MAXV][MAXE];
vector<int> wait;
int bfs(int s)
{
    fill(dis,dis+V,INF);
    dis[s]=0;
    queue<int> q;
    while(!q.empty())
        q.pop();
    q.push(s);
    int res=0,cnt=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();i++)
        {
            if(G[x][i].active&&dis[G[x][i].to]==INF)
            {
                dis[G[x][i].to]=dis[x]+1;
                res+=dis[x]+1;
                q.push(G[x][i].to);
                cnt++;
            }
        }
    }
    if(cnt==V) return res; else return -1;
}
void fbfs(int s)
{
    fill(d,d+V,INF);
    wait.clear();
    d[s]=0;
    queue<int> que;
    que.push(s);
    int res=0,cnt=1;
    while(!que.empty())
    {
        int x=que.front();
        que.pop();
        for(int i=0;i<G[x].size();i++)
        {
            if(d[G[x][i].to]==INF)
            {
                d[G[x][i].to]=d[x]+1;
                res+=d[x]+1;
                que.push(G[x][i].to);
                wait.push_back(G[x][i].id);
                cnt++;
            }
        }
    }
    if(cnt!=V)
    {
        for(int i=0;i<E;i++)
            printf("INF\n");
        return;
    }
    else
    {
        fill(ans[s],ans[s]+E,res);
        for(int i=0;i<wait.size();i++)
        {
            G[save[wait[i]].a][save[wait[i]].b].active=false;
            G[save[wait[i]].c][save[wait[i]].d].active=false;
            ans[s][wait[i]]=bfs(s);
            G[save[wait[i]].a][save[wait[i]].b].active=true;
            G[save[wait[i]].c][save[wait[i]].d].active=true;
        }
    }
    return;
}
int main()
{
    while(scanf("%d %d",&V,&E)==2)
    {
        for(int i=0;i<V;i++)
            G[i].clear();
        for(int i=0;i<E;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
            G[x].push_back((edge){y,i,true});
            G[y].push_back((edge){x,i,true});
            save[i].a=x;
            save[i].b=G[x].size()-1;
            save[i].c=y;
            save[i].d=G[y].size()-1;
        }
        for(int i=0;i<V;i++)
            fbfs(i);
        for(int i=0;i<E;i++)
        {
            int result=0,f=1;
            for(int j=0;j<V;j++)
            {
                if(ans[j][i]==-1)
                {
                    f=0;
                    break;
                }
                else result+=ans[j][i];
            }
            if(!f) printf("INF\n"); else printf("%d\n",result);
        }
    }
    return 0;
}

