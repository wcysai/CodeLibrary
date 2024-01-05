#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int n1,n2;
int u[MAXN],v[MAXN];
vector<int> H[MAXN];
vector<int> G[MAXN];
vector<int> GG[MAXN];
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
int color[MAXN];
vector<int> order;
int nxt[MAXN],pre[MAXN];
int tot,id[MAXN];
int head[MAXN],tail[MAXN];
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<GG[v].size();i++)
	{
		int to=GG[v][i];
		if(color[to]==0)
		{
			dfs_visit(to);
		}
	}
	color[v]=2;
	order.push_back(v);
}
void toposort()
{
	memset(color,0,sizeof(color));
	for(int i=1;i<=tot;i++)
		if(color[i]==0)
			dfs_visit(i);
    reverse(order.begin(),order.end());
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(n+v[i]);
        G[n+v[i]].push_back(u[i]);
    }
    n1=n2=n;
    int x=matching();
    int num=n-x;
    printf("%d\n",num-1);
    for(int i=1;i<=n;i++){
        if(mx[i]) {nxt[i]=mx[i]-n; pre[nxt[i]]=i;}
        else nxt[i]=i;
    }
    vector<int> st;
    for(int i=1;i<=n;i++) if(!pre[i]) st.push_back(i);
    for(auto x:st){
        ++tot;
        int now=x; id[now]=tot; head[tot]=now;
        while(nxt[now]!=now){
            now=nxt[now];
            id[now]=tot;
        }
        tail[tot]=now;
    }
    for(int i=0;i<n-1;i++){
        if(id[u[i]]==id[v[i]]) continue;
        GG[id[u[i]]].push_back(id[v[i]]);
    }
    toposort();
    for(int i=0;i<(int)order.size()-1;i++){
        printf("%d %d\n",tail[order[i]],head[order[i+1]]);
    }
    return 0;
}

