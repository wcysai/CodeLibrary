#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
vector<int> G[MAXN],bG[MAXN];
int x[MAXN],t[MAXN];
P upd[MAXN];
const int threshold=400;
int get_val(int v)
{
    P p=P(t[v],x[v]);
    for(auto to:bG[v]) p=max(p,upd[to]);
    return p.S;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    vector<int> big;
    for(int i=1;i<=n;i++) if((int)G[i].size()>=threshold) big.push_back(i);
    for(int i=1;i<=n;i++)
        for(auto to:G[i]) if((int)G[to].size()>=threshold) bG[i].push_back(to);
    for(int i=1;i<=n;i++) x[i]=i,upd[i]=P(-1,-1);
    for(int i=1;i<=q;i++)
    {
        int X;
        scanf("%d",&X);
        if((int)G[X].size()<threshold)
        {
            int val=get_val(X);
            x[X]=val; t[X]=i;
            for(auto to:G[X])
            {
                x[to]=val;
                t[to]=i;
            }
        }
        else
        {
            int val=get_val(X);
            x[X]=val; t[X]=i;
            upd[X]=P(i,val);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",get_val(i));
    return 0;
}