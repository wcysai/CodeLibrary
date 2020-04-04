#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int l[MAXN],r[MAXN];
vector<int> G[MAXN];
int color[MAXN];
bool dfs(int v,int c)
{
    color[v]=c;
    for(auto to:G[v])
    {
        if(color[to]==c) return false;
        if(!color[to]&&!dfs(to,-c)) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) color[i]=0;
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        printf("Case #%d: ",_);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(l[j]>=r[i]||r[j]<=l[i]);
                else 
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        bool f=true;
        for(int i=1;i<=n;i++) if(!color[i]&&!dfs(i,1)) f=false;
        if(!f) puts("IMPOSSIBLE");
        else
        {
            for(int i=1;i<=n;i++) if(color[i]==1) printf("J"); else printf("C");
            printf("\n");
        }
    }
    return 0;
}