#include<bits/stdc++.h>
#define MP make_pair
#define MAXN 30005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
struct edge{int to,damage,length;};
int T,N,K,cnt,b,e;
vector<edge> G[MAXN];
bool centroid[MAXN];
int subtree_size[MAXN];
P path[MAXN];
int ans;
int compute_subtree_size(int v,int p)
{
    int c=1;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        c+=compute_subtree_size(G[v][i].to,v);
    }
    subtree_size[v]=c;
    return c;
}
pair<int,int> search_centroid(int v,int p,int t)
{
    P res=MP(INT_MAX,-1);
    int s=1,m=0;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,MP(m,v));
    return res;
}
void traverse_paths(int v,int p,int d,int l)
{
    if(d>K) return;
    path[e++]=MP(d,l);
    ans=max(ans,l);
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        traverse_paths(w,v,d+G[v][i].damage,l+G[v][i].length);
    }
}
void remove_useless(int b, int &e)
{
    if (b==e)
        return;
    int size;
    for (int i=size=b+1;i<e;i++)
    {
        if (path[i].F==path[size-1].F)
        {
            path[size-1]=path[i];
            continue;
        }
        if (path[i].S<=path[size-1].S)
            continue;
        path[size++]=path[i];
    }
    e=size;
}
void solve_subproblem(int v)
{
    compute_subtree_size(v,-1);
    int s=search_centroid(v,-1,subtree_size[v]).S;
    centroid[s]=true;
    for(int i=0;i<G[s].size();i++)
    {
        if(centroid[G[s][i].to]) continue;
        solve_subproblem(G[s][i].to);
    }
    b=e=0;
    for(int i=0;i<G[s].size();i++)
    {
        if(centroid[G[s][i].to]) continue;
        traverse_paths(G[s][i].to,s,G[s][i].damage,G[s][i].length);
        if(b>0)
        {
            sort(path+b,path+e);
            remove_useless(b,e);
            for(int b_=0,e_=e-1;b_<b;b_++)
            {
                while(e_>= b&&path[b_].F+path[e_].F>K)
                    e_--;
                if(e_>=b) ans=max(ans,path[b_].S+path[e_].S);
            }
        }
        sort(path,path+e);
        remove_useless(0,e);
        b=e;
    }
    
    centroid[s]=false;
}
void solve()
{
    ans=0;
    solve_subproblem(0);
    printf("Case %d: %d\n",cnt,ans);
}
int main()
{
    scanf("%d",&T);
    cnt=0;
    while(T--)
    {
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;i++)
            G[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int x,y,d,l;
            scanf("%d%d%d%d",&x,&y,&d,&l);
            x--;
            y--;
            G[x].push_back((edge){y,d,l});
            G[y].push_back((edge){x,d,l});
        }
        memset(centroid,false,sizeof(centroid));
        cnt++;
        solve();
    }
    return 0;
}
