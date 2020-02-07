#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,int> P;
const double eps=1e-6;
int T,n,s,t,tot;
string str;
map<string,int> mp;
string save[MAXN];
int get_id(string str)
{
    if(mp.find(str)==mp.end()) 
    {
        mp[str]=++tot;
        save[tot]=str;
    }
    return mp[str];
}
struct edge
{
    int from,deptime,cost,delay;
    double prob;
};
vector<edge> G[MAXN];
void add_edge(int from,int to,int dt,int c,int p,int dl)
{
    G[to].push_back((edge){from,dt,c,dl,(double)p/100.0});
}
double dist[MAXN][60];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        //tot=0;
        cin>>str;
        s=get_id(str);
        cin>>str;
        t=get_id(str);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int from,to,dt,c,p,dl;
            cin>>str;
            from=get_id(str);
            cin>>str;
            to=get_id(str);
            scanf("%d%d%d%d",&dt,&c,&p,&dl);
            add_edge(from,to,dt,c,p,dl);
        }
        for(int i=1;i<=tot;i++)
            for(int j=0;j<60;j++)
                dist[i][j]=(i==t?0:INF);
        priority_queue<P,vector<P>,greater<P> > pque;
        pque.push(P(0,t*60));
        while(pque.size())
        {
            P p=pque.top(); pque.pop();
            int to=p.S/60,curt=p.S%60;
            double res=p.F;
            if(dist[to][curt]+eps<res) continue;
            for(auto e:G[to])
            {
                double ans=(1.0-e.prob)*(e.cost+dist[to][(e.deptime+e.cost)%60]);
                for(int i=1;i<=e.delay;i++) ans+=e.prob*(1.0/e.delay)*(e.cost+i+dist[to][(e.deptime+e.cost+i)%60]);
                if(ans<dist[e.from][e.deptime])
                {
                    dist[e.from][e.deptime]=ans;
                    pque.push(P(ans,e.from*60+e.deptime));
                    for(int i=1;i<60;i++) dist[e.from][(e.deptime-i+60)%60]=min(dist[e.from][(e.deptime-i+60)%60],ans+i);
                }
            }
        }
        double ans=INF;
        for(int i=0;i<60;i++) ans=min(ans,dist[s][i]);
        if(ans==INF) puts("IMPOSSIBLE"); else printf("%.10f\n",ans);
    }
    return 0;
}