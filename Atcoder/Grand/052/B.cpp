#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<P> G[2][MAXN];
int w[2][MAXN];
void dfs(int v,int p,int id)
{
    for(auto e:G[id][v])
    {
        int to=e.F,cost=e.S;
        if(to==p) continue;
        w[id][to]=w[id][v]^cost;
        dfs(to,v,id);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w1,w2;
        scanf("%d%d%d%d",&u,&v,&w1,&w2);
        G[0][u].push_back(P(v,w1));
        G[0][v].push_back(P(u,w1));
        G[1][u].push_back(P(v,w2));
        G[1][v].push_back(P(u,w2));
    }
    dfs(1,0,0); dfs(1,0,1);
    int sw0=0,sw1=0;
    for(int i=1;i<=n;i++) sw0^=w[0][i];
    for(int i=1;i<=n;i++) sw1^=w[1][i];
    for(int i=1;i<=n;i++) w[0][i]^=(sw0^sw1);
    vector<int> v1,v2;
    for(int i=1;i<=n;i++) v1.push_back(w[0][i]);
    for(int i=1;i<=n;i++) v2.push_back(w[1][i]);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    bool f=true;
    for(int i=0;i<n;i++) if(v1[i]!=v2[i]) f=false;
    if(f) puts("YES"); else puts("NO");
    return 0;
}