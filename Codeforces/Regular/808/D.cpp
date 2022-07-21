#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p;
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
int dp[MAXN][MAXN];//subtree at i, maximum label j
void dfs(int v,int p)
{

}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    return 0;
}

