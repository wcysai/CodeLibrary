#include<bits/stdc++.h>
#define MAXN 12
#define MAXM 3005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,one3,zero3,one4,zero4,one5,zero5;
string str;
int layer[MAXM];
double weight[MAXM];
vector<int> neurons[MAXM];
vector<pair<int,int> > G[MAXM];
int val[MAXM];
struct edge
{
    int from,to,weight;
};
vector<edge> edges;
void add_edge(int from,int to,int weight)
{
    edges.push_back((edge){from,to,weight});
    G[from].push_back(P(to,weight));
}
void pre()
{
    for(int i=1;i<=tot;i++) neurons[layer[i]].push_back(i);
}
void solve()
{
    for(int i=1;i<=tot;i++) weight[i]=0.0;
    for(int i=1;i<=n;i++) scanf("%lf",&weight[i]);
    for(int i=1;i<=6;i++)
    {
        for(auto v:neurons[i])
        {
            if(v>n) weight[v]=1.0/(1+exp(-weight[v]));
            for(auto e:G[v]) weight[e.F]+=weight[v]*e.S;
        }
    }
    for(int i=1;i<=tot;i++) printf("%f ",weight[i]);
    puts("");
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int nmask=0;
        for(int j=0;j<n;j++) if(mask&(1<<j)) nmask|=(1<<(n-1-j));
        val[mask]=(int)str[nmask]-'0';
    }
    for(int i=1;i<=n;i++) layer[i]=1;
    tot=n;
    layer[++tot]=2;
    layer[++tot]=3;
    one3=tot;
    add_edge(tot-1,tot,1000);
    layer[++tot]=3;
    zero3=tot;
    add_edge(tot-2,tot,-1000);
    add_edge(one3,++tot,-1000); layer[tot]=4; zero4=tot;
    add_edge(one3,++tot,1000); layer[tot]=4; one4=tot;
    int st=tot+1;
    for(int i=1;i<=n;i++)
    {
        add_edge(i,++tot,1000);
        add_edge(one3,tot,-500);
        layer[tot]=4;
    }
    int notst=tot+1;
    for(int i=1;i<=n;i++)
    {
        add_edge(i,++tot,-1000);
        add_edge(one3,tot,500);
        layer[tot]=4;
    }
    add_edge(one4,++tot,-1000); layer[tot]=5; zero5=tot;
    add_edge(one4,++tot,1000); layer[tot]=5; one5=tot;
    for(int i=tot+1;i<=tot+(1<<n);i++) layer[i]=5;
    int stm=tot+1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) add_edge(st+i,tot+mask+1,100);
            else add_edge(notst+i,tot+mask+1,100);
        }
        add_edge(one4,tot+mask+1,-n*100+50);
    }
    tot+=(1<<n);
    layer[++tot]=6;
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(!val[mask]) continue;
        add_edge(stm+mask,tot,1000);
    }
    add_edge(one5,tot,-500);
    printf("%d %d\n",6,tot);
    for(int i=1;i<=tot;i++) printf("%d%c",layer[i],i==tot?'\n':' ');
    printf("%d\n",(int)edges.size());
    for(auto p:edges) printf("%d %d %d\n",p.from,p.to,p.weight);
    //pre();
    //while(true) solve();
    return 0;
}
