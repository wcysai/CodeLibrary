#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,k,a[MAXN];
vector<P> G[MAXN];
vector<int> times[MAXN];
int d[MAXN];
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=t;i++){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(P(v,i)); G[v].push_back(P(u,i));
        }
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) {scanf("%d",&a[i]); times[a[i]].push_back(i);}
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+n+1,INF);
    d[1]=0;
    que.push(P(0,1));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        //printf("v=%d\n",v);
        if(d[v]<p.F) continue;
        for(auto p:G[v])
        {
            int to=p.F,id=p.S;
            //printf("to=%d id=%d\n",to,id);
            if(!times[id].size()||d[v]>=times[id].back()) continue;
            int nxt_time=*lower_bound(times[id].begin(),times[id].end(),d[v]+1);
            if(d[to]>nxt_time)
            {
                d[to]=nxt_time;
                que.push(P(d[to],to));
            }
        }
    }
    if(d[n]==INF) printf("-1\n"); else printf("%d\n",d[n]);
    return 0;
}

