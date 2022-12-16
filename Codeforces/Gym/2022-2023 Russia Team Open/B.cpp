#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 200005
#define INF 1000000000000000LL
#define MOD 1000000007
using namespace std;
typedef long long ll;
struct edge{int to,cost;};
typedef pair<ll,int> P;
int n,m,s,t;
ll L;
vector<edge> G[MAXN];
namespace IO { 
int len = 0;
char ibuf[(1 << 20) + 1], *iS, *iT, out[(1 << 25) + 1];
#define gh()                                                                   \
    (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),       \
     (iS == iT ? EOF : *iS++) : *iS++)
#define reg register
inline int read() {
    reg char ch = gh();
    reg int x = 0;
    reg char t = 0;
    while (ch < '0' || ch > '9')
        t |= ch == '-', ch = gh();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch ^ 48), ch = gh();
    return t ? -x : x;
}
inline void putc(char ch) {
    out[len++] = ch;
}
template <class T> inline void write(T x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) write(x / 10);
    out[len++] = x % 10 + 48;
}
inline void flush() {
    fwrite(out, 1, len, stdout);
    len = 0;
}
}
void add_edge(int u,int v,int w)
{
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
vector<int> v;
ll d[2][MAXN];
int dp[2][MAXN];
void dijkstra(int s,int id)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d[id]+1,d[id]+n+1,INF);
    d[id][s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[id][v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[id][e.to]>d[id][v]+e.cost)
            {
                d[id][e.to]=d[id][v]+e.cost;
                que.push(P(d[id][e.to],e.to));
            }
        }
    }
}
bool cmp1(int x,int y) {return d[0][x]<d[0][y];}
bool cmp2(int x,int y) {return d[1][x]<d[1][y];}
int main()
{
    scanf("%d%d%d%d%lld",&n,&m,&s,&t,&L);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        u=IO::read(); v=IO::read(); w=IO::read();
        add_edge(u,v,w);
    }
    dijkstra(s,0); dijkstra(t,1);
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    dp[0][s]=1; dp[1][t]=1;
    sort(v.begin(),v.end(),cmp1);
    for(int i=1;i<n;i++)
    {
        int x=v[i];
        for(auto e:G[x])
            if(d[0][e.to]+e.cost==d[0][x]) add(dp[0][x],dp[0][e.to]);
    }
    sort(v.begin(),v.end(),cmp2);
    for(int i=1;i<n;i++)
    {
        int x=v[i];
        for(auto e:G[x])
            if(d[1][e.to]+e.cost==d[1][x]) add(dp[1][x],dp[1][e.to]);
    }
    /*for(int i=1;i<=n;i++) printf("%lld ",d[0][i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%lld ",d[1][i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%d ",dp[0][i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%d ",dp[1][i]);
    puts("");*/
    if(L==d[0][t]) printf("%d\n",dp[0][t]);
    else
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i==t) continue;
            if(d[0][i]+d[1][i]!=d[0][t]) continue;
            for(auto e:G[i])
            {
                if(e.cost+d[0][i]+d[1][e.to]==L) 
                {
                    //printf("i=%d to=%d\n",i,e.to);
                    add(ans,1LL*dp[0][i]*dp[1][e.to]%MOD);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
