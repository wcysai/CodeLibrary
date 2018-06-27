#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int query,n;
vector<int> G[MAXN];
int depth[MAXN],p[MAXN];
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        queue<int> que;
        memset(p,0,sizeof(p));
        memset(depth,0,sizeof(depth));
        que.push(1);
        int ans=0,t=1;
        while(!que.empty())
        {
            int x=que.front();
            que.pop();
            for(int i=0;i<G[x].size();i++)
                if(G[x][i]!=p[x])
                {
                    que.push(G[x][i]);
                    depth[G[x][i]]=depth[x]+1;
                    if(depth[G[x][i]]>ans) ans=depth[G[x][i]],t=G[x][i];
                    p[G[x][i]]=x;
                }
        }
        memset(depth,0,sizeof(depth));
        memset(p,0,sizeof(p));
        int rec=t;
        ans=0;
        que.push(t);
        while(!que.empty())
        {
            int x=que.front();
            que.pop();
            for(int i=0;i<G[x].size();i++)
                if(G[x][i]!=p[x])
                {
                    que.push(G[x][i]);
                    depth[G[x][i]]=depth[x]+1;
                    if(depth[G[x][i]]>ans) ans=depth[G[x][i]],rec=G[x][i];
                    p[G[x][i]]=x;
                }
        }
        depth[rec]=1;
        while(p[rec]!=0)
        {
            depth[p[rec]]=min(depth[rec]+1,depth[p[rec]]);
            rec=p[rec];
        }
        ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,depth[i]);
        printf("%d\n",ans);
    }
    return 0;
}
