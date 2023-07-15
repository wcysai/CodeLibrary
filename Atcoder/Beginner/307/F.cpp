#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000001
#define INF2 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,m,K,D;
P p[MAXN];
struct edge{
    int to,cost;
};
vector<edge> G[MAXN];
ll d[MAXN];
int x[MAXN];
void add_edge(int u,int v,int w){
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
}
struct segtree{
    int maxi[4*MAXN];
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r) {maxi[k]=x[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    int get_mini(int k,int l,int r,int pos,int val){
        if(r<pos) return -1;
        if(maxi[k]<val) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int a=get_mini(k*2,l,mid,pos,val);
        if(a!=-1) return a; else return get_mini(k*2+1,mid+1,r,pos,val);
    }
}seg;
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=1;i<=n+1;i++) d[i]=INF2;
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.S;
        ll z=p.F;
        ll day=z/INF,rem=x[day+1]-(z%INF);
        if(d[v]<z) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            ll target;
            if(e.cost<=rem){
                target=z+e.cost;
            }
            else{
                int nxt=seg.get_mini(1,1,D,day+2,e.cost);
               // printf("day=%d cost=%lld nxt=%d\n",day+2,e.cost,nxt);
                if(nxt==-1) continue;
                else target=1LL*(nxt-1)*INF+e.cost;
            }
            if(d[e.to]>target)
            {
                d[e.to]=target;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    scanf("%d",&K);
    for(int i=1;i<=K;i++){
        int x;
        scanf("%d",&x);
        add_edge(n+1,x,0);
    }
    scanf("%d",&D);
    for(int i=1;i<=D;i++) scanf("%d",&x[i]);
    seg.build(1,1,D);
    dijkstra(n+1);
    for(int i=1;i<=n;i++){
        //printf("i=%d d=%lld\n",i,d[i]);
        if(d[i]==INF2) puts("-1");
        else if(d[i]==0) printf("0\n");
        else printf("%lld\n",d[i]/INF+1);
    }
    return 0;
}

