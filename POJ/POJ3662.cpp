#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_V 1000
#define MAX_E 10000
#define INF 1000000000
using namespace std;
struct edge
{
    int to;
    int cost;
};
vector<edge> G[MAX_V];
vector<edge> G2[MAX_V];
int d[MAX_V];
int V,E,k,f;
bool C(int x)
{
    for(int i=0;i<V;i++)
        G2[i].clear();
    for(int i=0;i<V;i++)
        for(int j=0;j<G[i].size();j++)
        {
            edge e;
            e.to=G[i][j].to;
            if(G[i][j].cost>x)
            {
                e.cost=1;
                G2[i].push_back(e);
            }
            else
            {
                e.cost=0;
                G2[i].push_back(e);
            }
        }
    typedef pair<int,int> P;
    priority_queue<P,vector<P>,greater<P> >que;
    while(que.size()) que.pop();
    fill(d,d+V,INF);
    d[0]=0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        long long m=p.second;
        if(d[m]<p.first) continue;
        for(int i=0;i<G2[m].size();i++)
        {
            edge e=G2[m][i];
            if(d[e.to]>d[m]+e.cost)
            {
                d[e.to]=d[m]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    if(d[V-1]==INF)
    {
        printf("-1\n");
       f=0;
    }
    return d[V-1]<=k;
}
int main()
{
    scanf("%d %d %d",&V,&E,&k);
    f=1;
    for(int i=0;i<E;i++)
    {
        int s;
        edge x;
        scanf("%d %d %d",&s,&x.to,&x.cost);
        s--;
        x.to--;
        G[s].push_back(x);
        swap(s,x.to);
        G[s].push_back(x);
    }
    int left=-1,right=1000000;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)) right=mid;
        else left=mid;
        if(f==0) return 0;
    }
    printf("%d\n",right);
    ending:return 0;
}
