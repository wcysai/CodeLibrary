#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,n1,n2;
vector<int> G[MAXN];
int a[MAXN],b[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool vis[MAXN];
bool find(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1)
        {
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]]))
            {
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
int matching()
{
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    int ans=0;
    while(true)
    {
        bool flag=false;
        while(!que.empty()) que.pop();
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(int i=1;i<=n1;i++)
            if(!mx[i]) que.push(i);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
                if(!dy[G[u][i]])
                {
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]])
                    {
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
        }
        if(!flag) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n1;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
vector<int> dis;
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&n);
        dis.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d",&a[i],&b[i]);
            dis.push_back(a[i]); dis.push_back(b[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n+(int)dis.size();i++) G[i].clear();
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
            b[i]=lower_bound(dis.begin(),dis.end(),b[i])-dis.begin()+1;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].push_back(n+a[i]); G[n+a[i]].push_back(i);
            G[i].push_back(n+b[i]); G[n+b[i]].push_back(i);
        }
        n1=n; n2=(int)dis.size();
        printf("Case #%d: %d\n",_,matching());
    }
    return 0;
}
