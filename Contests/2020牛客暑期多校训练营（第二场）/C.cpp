#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
vector<int> G[MAXN];
int st[MAXN];
void dfs(int v,int p)
{
    st[v]=++tot;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
bool cmp(int x,int y)
{
    return st[x]<st[y];
}
vector<int> leaves;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) if((int)G[i].size()==1) leaves.push_back(i);
    sort(leaves.begin(),leaves.end(),cmp);
    printf("%d\n",((int)leaves.size()+1)/2);
    int shift=(leaves.size()+1)/2;
    for(int i=0;i<shift;i++) printf("%d %d\n",leaves[i],leaves[(i+shift)%(int)leaves.size()]);
}