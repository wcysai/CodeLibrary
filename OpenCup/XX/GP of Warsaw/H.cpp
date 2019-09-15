#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,int> P;
int n,m;
double dis[MAXN];
vector<int> G[MAXN];
vector<double> to[MAXN];
bool valid[MAXN];
double p4[MAXN],psum4[MAXN];
void update_weight(int v,double e)
{
    to[v].push_back(e);
    double tmp=dis[v];
    if(dis[v]==INF) dis[v]=e+1.5;
    else
    {
        int x=(int)to[v].size()-1;
        dis[v]-=(psum4[x-1]+0.5*p4[x-1]);
        dis[v]+=psum4[x]+0.5*p4[x];
        dis[v]-=p4[x]*to[v][0];
        dis[v]+=p4[x+1]*to[v][0];
        dis[v]+=p4[x+1]*3.0*e;
    }
    if(dis[v]>tmp)
    {
        dis[v]=tmp;
        to[v].pop_back();
    }
}
void dijkstra(int s)
{
    set<P> st;
    fill(dis+1,dis+n+1,INF);
    dis[s]=0.0;
    for(int i=1;i<=n;i++) st.insert(P(dis[i],i));
    while(st.size())
    {
        P p=*(st.begin());
        st.erase(st.begin());
        int v=p.S;
        valid[v]=true;
        for(auto to:G[v])
        {
            if(valid[to]) continue;
            st.erase(st.find(P(dis[to],to)));
            update_weight(to,dis[v]);
            st.insert(P(dis[to],to));
        }
    }
}
int main()
{
    p4[0]=psum4[0]=1.0;
    for(int i=1;i<=200000;i++)
    {
        p4[i]=0.25*p4[i-1];
        psum4[i]=psum4[i-1]+p4[i];
    }
    memset(valid,false,sizeof(valid));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dijkstra(n);
    printf("%.10f\n",dis[1]);
    return 0;
}

