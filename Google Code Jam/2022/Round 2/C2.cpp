#include<bits/stdc++.h>
#define MAXN 2005
#define INF 8000000000000000000LL
using namespace std;
typedef long long ll;
int T,n;
vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int x[MAXN],y[MAXN];
int dx[MAXN],dy[MAXN];
bool vis[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
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
        for(int i=1;i<=n;i++)
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
        for(int i=1;i<=n;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
ll get_dist2(int i,int j)
{
    return 1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]);
}
int cnt;
bool used[MAXN];
bool check(int pos)
{
    int to=mx[pos];
    ll d=get_dist2(pos,to+1);
    for(int i=1;i<=n;i++)
        if(!used[n+i]&&get_dist2(pos,n+i+1)<d) return false;
    return true;
}
bool checkall()
{
    for(int i=1;i<=n;i++)
    {
        if(!used[i]&&check(i))
        {
            used[i]=true; used[mx[i]]=true;
            printf("%d %d\n",i,mx[i]-n+1);
            cnt--; return true;
        }
    }
    return false;
}
int find_nearest(int pos)
{
    ll d=INF,id=-1;
    for(int i=1;i<=n;i++)
    {
        if(!used[n+i]&&get_dist2(pos,n+1+i)<d) {d=get_dist2(pos,n+1+i); id=n+i;}
    }
    return id;
}
void change_matching()
{
    int id=-1;
    for(int i=1;i<=n;i++) if(!used[i]) {id=i; break;}
    assert(id!=-1); 
    vector<int> v;
    set<int> s;
    int now=id;
    do
    {
        int to=find_nearest(now);
        v.push_back(now); v.push_back(to); s.insert(now);
        //printf("now=%d to=%d\n",now,to);
        now=my[to]; 
    }while(!s.count(now));
    bool f=false;
    for(int i=0;i<(int)v.size();i+=2) 
    {
        if(v[i]==now) f=true;
        if(!f) continue;
        mx[v[i]]=v[i+1],my[v[i+1]]=v[i];
    }
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n+1;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=2*n;i++) used[i]=false;
        for(int i=1;i<=n;i++)
        {
            ll d=get_dist2(i,n+1);
            for(int j=1;j<=n;j++)
                if(get_dist2(i,n+1+j)<=d) add_edge(i,n+j);
        }
        printf("Case #%d: ",t);
        if(matching()!=n) {puts("IMPOSSIBLE"); continue;}
        puts("POSSIBLE");
        cnt=n;
        int num=0;
        while(cnt)
        {
            if(!checkall()) change_matching(); 
        }
    }
    return 0;
}

