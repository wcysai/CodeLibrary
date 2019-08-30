#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
struct edge2{int to,cost;};
struct edge3{int from,to,cap;};
int T,n,m,sz,ans;
int treesz[MAXN];
string str;
vector<int> spe;
vector<edge> G[MAXN];
bool used[MAXN];
set<P> wall;
vector<edge2> gh[MAXN];
vector<edge3>  edges;
int dx[8]={0,0,-1,1,-1,-1,1,1},dy[8]={-1,1,0,0,-1,1,-1,1};
void add_wall(int u,int v)
{
   // printf("add wall %d %d\n",u,v);
    if(u>v) swap(u,v);
    wall.insert(P(u,v));
}
void add_all()
{
    for(auto e:edges)
    {
        G[e.from].push_back((edge){e.to,e.cap,(int)G[e.to].size()});
        G[e.to].push_back((edge){e.from,0,(int)G[e.from].size()-1});
    }
}
void clear_all()
{
    for(auto v:spe) G[v].clear();
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        for(auto v:spe) used[v]=0;
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
void build_gomory_hu_tree()
{
    vector<int> p(n*m,spe[0]),cap(n*m,0);
    for(int i=1;i<(int)spe.size();i++)
    {
        int s=spe[i];
        add_all();
        int t=p[s];
        cap[s]=max_flow(s,t);
        vector<bool> in_cut(n*m,0);
        queue<int> que({s});
        in_cut[s]=true;
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            for(auto e:G[v])
            {
                if(e.cap>0&&!in_cut[e.to])
                {
                    in_cut[e.to]=true;
                    que.push(e.to);
                }
            }
        }
        for(auto v:spe)
            if(v!=s&&in_cut[v]&&p[v]==t)
                p[v]=s;
        if(in_cut[p[t]])
        {
            p[s]=p[t];
            p[t]=s;
            swap(cap[s],cap[t]);
        }
        clear_all();
    }
    for(int i=1;i<(int)spe.size();i++)
    {
        int v=spe[i];
       // printf("gh tree edge %d %d %d\n",v,p[v],cap[v]);
        gh[p[v]].push_back((edge2){v,cap[v]});
        gh[v].push_back((edge2){p[v],cap[v]});
    }
}
void dfs2(int v,int p,int mincost)
{
    if(mincost!=INF) ans+=mincost;
    for(auto e:gh[v])
    {
        if(e.to==p) continue;
        dfs2(e.to,v,min(mincost,e.cost));
    }
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        spe.clear(); edges.clear(); wall.clear();
        scanf("%d%d ",&n,&m);
        ans=0;
        int cols=3+n*4;
        for(int i=0;i<cols;i++)
        {
            getline(cin,str);
            sz=(int)str.size();
            int round=i/4;
            switch(i%4)
            {
                case 0:
                {
                    for(int j=0;j<sz;j++)
                    {
                        if(str[j]=='*')
                        {
                            int x=2*(j/12)+1;
                            spe.push_back((round-1)*m+x);
                        }
                        else if(str[j]=='-'&&j%12==3)
                        {
                            if(round==0||round==n) continue;
                            int x=2*(j/12);
                            add_wall((round-1)*m+x,round*m+x);
                        }
                    }
                    break;
                }
                case 1:
                {
                    for(int j=0;j<sz;j++)
                    {
                        if(str[j]=='/')
                        {
                            if(round==0||round==n||j/12==0) continue;
                            int x=2*(j/12)-1;
                            if(x<0||x+1==m) continue;
                            add_wall((round-1)*m+x,round*m+x+1);
                        }
                        else if(str[j]=='\\')
                        {
                            if(round==0||round==n) continue;
                            int x=2*(j/12);
                            if(x+1==m) continue;
                            add_wall((round-1)*m+x+1,round*m+x);
                        }
                    }
                    break;
                }
                case 2:
                {
                    for(int j=0;j<sz;j++)
                    {
                        if(str[j]=='*')
                        {
                            int x=2*(j/12);
                            spe.push_back(round*m+x);
                        }
                        else if(str[j]=='-'&&j%12==9)
                        {
                            if(round==0||round==n) continue;
                            int x=2*(j/12)+1;
                            add_wall((round-1)*m+x,round*m+x);
                        }
                    }
                    break;
                }
                case 3:
                {
                    for(int j=0;j<sz;j++)
                    {
                        if(str[j]=='/')
                        {
                            if(round==n) continue;
                            int x=2*(j/12);
                            if(x+1==m) continue;
                            add_wall(round*m+x,round*m+x+1);
                        }
                        else if(str[j]=='\\')
                        {
                            if(round==n) continue;
                            int x=2*(j/12)-1;
                            if(x<0) continue;
                            if(x+1==m) continue;
                            add_wall(round*m+x,round*m+x+1);
                        }
                    }
                    break;
                }
            }
        }
       // printf("special nodes: ");
       // for(auto v:spe) printf("%d ",v);
       // puts("");
        sz=(int)spe.size();
        if(sz<=1)
        {
            printf("Case #%d: %d\n",t,0);
            continue;
        }
        for(auto v:spe)
        {
            int x=v/m,y=v%m;
            for(int i=0;i<8;i++)
            {
                if(y%2==0&&i>=6) continue;
                if(y%2==1&&(i==4||i==5)) continue;
                int nx=x+dx[i],ny=y+dy[i];
                int u=nx*m+ny;
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!wall.count(P(min(v,u),max(v,u))))
                {
                    //printf("added edge %d %d\n",u,v);
                    edges.push_back((edge3){v,u,1});
                }
            }
        }
        build_gomory_hu_tree();
        for(auto v:spe) dfs2(v,-1,INF);
        for(auto v:spe) gh[v].clear();
        printf("Case #%d: %d\n",t,ans/2);
    }
    return 0;
}
