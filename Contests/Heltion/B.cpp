#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 400035
#define MAXM 400005
#define MAXK 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int T,n,m,all;
string str[MAXK];
mat vid;
struct graph
{
    mat G,tree,bcc;
    vec compid,sta,dfn,low,bccno,id;
    vector<bool> art,vis;
    int bcc_cnt,V,N,t,tot,compcnt;
    vector<int> st[MAXLOGN],vs,depth,rid;
    void init(int n)
    {
        N=compcnt=bcc_cnt=0; V=n;
        G.clear(); tree.clear(); bcc.clear(); vis.clear(); 
        compid.clear(); sta.clear(); dfn.clear(); low.clear(); bccno.clear(); id.clear(); art.clear();
        for(int i=0;i<MAXLOGN;i++) st[i].clear();
        vs.clear(); depth.clear(); rid.clear();
        G.resize(V+1); tree.resize(2*V+1); bcc.resize(V+1);
        compid.resize(V+1);  dfn.resize(V+1); low.resize(V+1); bccno.resize(V+1); id.resize(V+1); art.resize(V+1); vis.resize(2*V+1);
    }
    void add_edge(int u,int v)
    {
        G[u].push_back(v); G[v].push_back(u);
    }
    void dfs(int v,int p,int &tot)
    {
        dfn[v]=low[v]=++tot; compid[v]=compcnt;
        sta.push_back(v);
        for(auto to:G[v])
        {   
            if(to==p) continue;
            if(!dfn[to])
            {
                dfs(to,v,tot);
                low[v]=min(low[v],low[to]);
                if(low[to]>=dfn[v])
                {
                    art[v]=(dfn[v]>1||dfn[to]>2);
                    bcc_cnt++;
                    bcc[bcc_cnt].push_back(v); bccno[v]=bcc_cnt;
                    while(bcc[bcc_cnt].back()!=to)
                    {
                        bccno[sta.back()]=bcc_cnt;
                        bcc[bcc_cnt].push_back(sta.back()),sta.pop_back();
                    }
                }
            }
            else low[v]=min(low[v],dfn[to]);
        }
    }
    int tarjan()
    {
        bcc_cnt=t=compcnt=0;
        for(int i=1;i<=V;i++) if(!dfn[i]) {compcnt++; dfs(i,-1,tot=0);}
        return bcc_cnt;
    }
    void small_dfs(int v)
    {
        vis[v]=true; 
        for(auto to:tree[v])
            if(!vis[to]) small_dfs(to);
    }
    void build_block_cut_tree()
    {
        tarjan();
        for(int i=1;i<=V;i++) if(art[i]) id[i]=++N;
        for(int i=1;i<=bcc_cnt;i++)
        {
            N++;
            //printf("i=%d\n",i);
            for(auto v:bcc[i])
            {
                //printf("v=%d id=%d\n",v,id[v]);
                if(!art[v]) id[v]=N;
                else
                {   
                    tree[id[v]].push_back(N);
                    tree[N].push_back(id[v]);
                }
            }
        }
        vector<int> roots;
        for(int i=1;i<=N;i++) vis[i]=false;
        for(int i=1;i<=N;i++) if(!vis[i]) {small_dfs(i); roots.push_back(i);}
        ++N;
        for(auto x:roots) {tree[N].push_back(x); tree[x].push_back(N);}
    }
    void dfs2(int v,int p,int d,int &k)
    {
        //printf("v=%d p=%d\n",v,p);
        rid[v]=k;
        vs[k]=v;
        depth[k++]=d;
        for(int i=0;i<(int)tree[v].size();i++)
        {
            if(tree[v][i]!=p)
            {
                dfs2(tree[v][i],v,d+1,k);
                vs[k]=v;
                depth[k++]=d;
            }
        }
    }
    int getMin(int x, int y)
    {
        return depth[x]<depth[y]?x:y;
    }
    void rmq_init(int n)
    {
        for(int i=1;i<=n;++i) st[0][i]=i;
        for(int i=1;1<<i<n;++i)
            for(int j=1;j+(1<<i)-1<=n;++j)
                st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    void init_lca()
    {
        int k=0;
        for(int i=0;(1<<i)<2*N-1;i++) st[i].resize(2*N+1);
        depth.resize(2*N+1); vs.resize(2*N+1); rid.resize(N+1);
        dfs2(N,0,0,k);
        rmq_init(N*2-1);
    }
    int query(int l, int r)
    {
        int k=31-__builtin_clz(r-l+1);
        return getMin(st[k][l],st[k][r-(1<<k)+1]);
    }
    int lca(int u,int v)
    {
        if(u==v) return u;
        return vs[query(min(rid[u],rid[v]),max(rid[u],rid[v]))];
    }
    int dis(int u,int v)
    {
        return depth[rid[u]]+depth[rid[v]]-2*depth[rid[lca(u,v)]];
    }
    void init_all()
    {
        build_block_cut_tree();
        init_lca();
    }
    bool onpath(int u,int v,int w)
    {
        return dis(u,w)+dis(v,w)==dis(u,v);
    }
    bool reach(int u,int v,int w)
    {
        if(compid[u]!=compid[v]) return false;
        if((compid[w]!=compid[v])||(!art[w])) return true;
        return !onpath(id[u],id[v],id[w]);
    }
}g[5];
int d[4*MAXN];
vector<P> pos;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int bordx[4],bordy[4];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        bordx[0]=0; bordy[0]=(m+1)/2-1;
        bordx[1]=n-1; bordy[1]=(m+1)/2-1;
        bordy[2]=0; bordx[2]=(n+1)/2-1;
        bordy[3]=m-1; bordx[3]=(n+1)/2-1;
        for(int i=0;i<n;i++) cin>>str[i];
        vid.clear(); pos.clear();
        vid.resize(n);
        for(int i=0;i<n;i++) vid[i].resize(m);
        all=0;
        int patrick=-1,box=-1,pdes=-1,bdes=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]!='#') {vid[i][j]=++all; pos.push_back(P(i,j));} else vid[i][j]=0;
                if(str[i][j]=='p') patrick=all;
                else if(str[i][j]=='b') box=all;
                else if(str[i][j]=='-') bdes=all;
                else if(str[i][j]=='=') pdes=all;
            }
        for(int i=0;i<4;i++) g[i].init(all+2);
        g[4].init(all+1);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]!='#')
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k],ny=j+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]) 
                            for(int tmp=0;tmp<5;tmp++) g[tmp].add_edge(vid[i][j],vid[nx][ny]);
                    }
                }
        for(int i=0;i<m;i++) if(vid[0][i]) g[0].add_edge(all+1,vid[0][i]);
        for(int i=0;i<m;i++) if(vid[n-1][i]) g[1].add_edge(all+1,vid[n-1][i]);
        for(int i=0;i<n;i++) if(vid[i][0]) g[2].add_edge(all+1,vid[i][0]);
        for(int i=0;i<n;i++) if(vid[i][m-1]) g[3].add_edge(all+1,vid[i][m-1]);
        for(int i=0;i<5;i++) g[i].init_all(); 
        for(int i=0;i<4*all;i++) d[i]=INF;
        deque<int> deq;
        int bx=pos[box-1].F,by=pos[box-1].S;
        for(int k=0;k<4;k++)
        {
            int nx=bx+dx[k],ny=by+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]&&(g[4].reach(patrick,vid[nx][ny],box)||g[k].reach(patrick,all+1,box))) {deq.push_back((box-1)*4+k); d[(box-1)*4+k]=0;}
        }
        int ans=INF;
        while(deq.size())
        {
            int state=deq.front(); deq.pop_front();
            int bid=state/4+1,dir=state%4;
            int bx=pos[bid-1].F,by=pos[bid-1].S;
            int px=bx+dx[dir],py=by+dy[dir];
            int pid=vid[px][py];
            //printf("bx=%d by=%d px=%d py=%d dir=%d dis=%d\n",bx,by,px,py,dir,d[state]);
            if(bid==bdes&&g[4].reach(pid,pdes,bid)) {ans=d[state]; break;}
            //0-3: up/down/left/right to box
            //push
            int tx=bx-dx[dir],ty=by-dy[dir];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&vid[tx][ty]&&d[(vid[tx][ty]-1)*4+dir]>d[state]+1) 
            {
                //printf("direct push\n");
                //same dir
                deq.push_back((vid[tx][ty]-1)*4+dir); 
                d[(vid[tx][ty]-1)*4+dir]=d[state]+1;
            }
            //directly move to distinct side
            //puts("111");
            for(int i=0;i<4;i++)
            {
                if(dir==i) continue;
                int nx=bx+dx[i],ny=by+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]&&d[(bid-1)*4+i]>d[state]&&g[4].reach(pid,vid[nx][ny],bid)) 
                { 
                    //printf("direct to %d\n",i);
                    deq.push_front((bid-1)*4+i); 
                    d[(bid-1)*4+i]=d[state];
                }
            }
            //puts("222");
            //enter box and move to distinct side
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&(!vid[tx][ty])&&vid[bordx[dir]][bordy[dir]]) 
            {
                if(bid==bdes&&g[4].reach(vid[bordx[dir]][bordy[dir]],pdes,bid)) {ans=d[state]; break;}
                for(int i=0;i<4;i++)
                {
                    if(dir==i) continue;
                    int nx=bx+dx[i],ny=by+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]&&d[(bid-1)*4+i]>d[state]&&g[4].reach(vid[bordx[dir]][bordy[dir]],vid[nx][ny],bid))
                    {
                        //printf("enter box then to %d\n",i);
                        deq.push_front((bid-1)*4+i); 
                        d[(bid-1)*4+i]=d[state];
                    }
                }
            }
            //go out of border
            //puts("333");
            for(int i=0;i<4;i++)
            {
                if(dir==i) continue;
                int nx=bx+dx[i],ny=by+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]&&d[(bid-1)*4+i]>d[state]&&g[i].reach(pid,all+1,bid)) 
                {
                    //printf("out of border then to %d\n",i);
                    deq.push_front((bid-1)*4+i); 
                    d[(bid-1)*4+i]=d[state];
                }
            }
            //enter box and go out of border
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&(!vid[tx][ty])&&vid[bordx[dir]][bordy[dir]]) 
            {
                for(int i=0;i<4;i++)
                {
                    if(dir==i) continue;
                    int nx=bx+dx[i],ny=by+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&vid[nx][ny]&&d[(bid-1)*4+i]>d[state]&&g[i].reach(vid[bordx[dir]][bordy[dir]],all+1,bid))
                    {
                        //printf("enter box then to %d\n",i);
                        deq.push_front((bid-1)*4+i); 
                        d[(bid-1)*4+i]=d[state];
                    }
                }
            }
        }
        if(ans==INF) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}
