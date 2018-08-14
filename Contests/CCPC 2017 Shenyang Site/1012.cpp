#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int t,n,k;
vector<int> G[MAXN];
int cnt[MAXN];
bool used[MAXN];
void dfs(int x)
{
    int s=1;
    used[x]=true;
    for(int i=0;i<G[x].size();i++)
    {
        if(!used[G[x][i]]) dfs(G[x][i]);
        s+=cnt[G[x][i]];
    }
    cnt[x]=s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        memset(cnt,0,sizeof(cnt));
        dfs(1);
        int ans=0;
        for(int i=2;i<=n;i++)
            if(cnt[i]>=k&&n-cnt[i]>=k) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
