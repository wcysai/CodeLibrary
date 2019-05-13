#include<bits/stdc++.h>
#define MAXV 2005
#define MAXE 5005
#define INF 2000000000000000001LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll from,to,cost;};
edge es[MAXE];
ll d[MAXV];
ll V,E,s;
bool updated[MAXV];
void bellman_ford(ll s)
{
    for(ll i=1;i<=V;i++) d[i]=INF;
    d[s]=0;
    ll cnt=0;
    bool check=false;
    memset(updated,false,sizeof(updated));
    while(true)
    {
        bool update=false;
        for(ll i=0;i<E;i++)
        {
            edge e=es[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                update=true;
                if(check) updated[e.to]=true;
            }
        }
        if(!update) break;
        cnt++;
        if(cnt==V) check=true; 
        if(cnt==2*V) break;
    }
}
void update_relation()
{
    for(int i=0;i<V;i++)
        for(int j=0;j<E;j++)
        {
            edge e=es[j];
            if(updated[e.from]) updated[e.to]=true;
        }
}
int main()
{
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    scanf("%lld%lld%lld",&V,&E,&s);
    for(ll i=0;i<E;i++) scanf("%lld%lld%lld",&es[i].from,&es[i].to,&es[i].cost);
    bellman_ford(s);
    update_relation();
    for(ll i=1;i<=V;i++) if(d[i]==INF) puts("*"); else if(updated[i]) puts("-"); else printf("%lld\n",d[i]);
    return 0;
}
