#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
vector<int> G[MAXN];
int d[MAXN];
ll solve(int x,int k)
{
    vector<int> vv;
    queue<int> que;
    que.push(x); d[x]=0; vv.push_back(x);
    while(que.size())
    {
        int v=que.front(); que.pop();
        if(d[v]==k) continue;
        for(auto to:G[v])
        {
            if(d[to]==INF)
            {
                vv.push_back(to); que.push(to);
                d[to]=d[v]+1;
            }
        }
    }
    ll res=0;
    for(auto x:vv) {res+=x; d[x]=INF;}
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    scanf("%d",&q);
    for(int i=1;i<=n;i++) d[i]=INF;
    for(int i=0;i<q;i++)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        printf("%lld\n",solve(x,k));
    }
    return 0;
}

