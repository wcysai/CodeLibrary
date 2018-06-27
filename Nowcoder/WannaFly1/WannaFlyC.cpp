#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 2005
using namespace std;
typedef pair<int,int> P;
int n,m,ans;
int save[MAXN];
int connected[MAXN][MAXN];
struct edge
{
    int to,id;
};
struct vert
{
    int deg,id,color;
}a[MAXN];
vector<vert> black,white;
vector<edge> G[MAXN];
bool cmp(vert x,vert y)
{
    if(x.deg!=y.deg) return x.deg>y.deg;
    return x.id>y.id;
}
int cnt;
int match[MAXN];
bool used[MAXN];

bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)white.size();i++)
    {
        int u=white[i].id,w=match[u];
        if((connected[u][v]>=0)&&(w<0||(!used[w]&&dfs(w))))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
bool bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<(int)black.size();i++)
    {
        int v=black[i].id;
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    for(int i=0;i<(int)black.size();i++)
    {
        if(match[black[i].id]>=0)
        {
            black[i].deg--;
            save[connected[black[i].id][match[black[i].id]]]=cnt+1;
            connected[black[i].id][match[black[i].id]]=-1;
            connected[match[black[i].id]][black[i].id]=-1;
        }
    }
    for(int i=0;i<(int)white.size();i++)
        if(match[white[i].id]>=0) white[i].deg--;
    if(res==0) return false; else return true;
}
bool colored[MAXN];
void find_color(int x,int color)
{
    colored[x]=true;
    a[x].color=color;
        if(color==0) black.push_back(a[x]); else white.push_back(a[x]);
    for(int i=0;i<(int)G[x].size();i++)
        if(!colored[G[x][i].to]) find_color(G[x][i].to,1-color);
}
int main()
{
    scanf("%d %d",&n,&m);
    memset(connected,-1,sizeof(connected));
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back((edge){y,i});
        G[y].push_back((edge){x,i});
        connected[x][y]=i;
        connected[y][x]=i;
        a[x].deg++;
        a[y].deg++;
    }
    for(int i=1;i<=n;i++)
        a[i].id=i;
    find_color(1,0);
    sort(black.begin(),black.end(),cmp);
    sort(white.begin(),white.end(),cmp);
    int k=max(black[0].deg,white[0].deg);
    printf("%d\n",k);
    cnt=0;
    memset(save,-1,sizeof(save));
    for(int i=0;i<k;i++)
    {
        if(!bipartite_matching()) break;
        sort(black.begin(),black.end(),cmp);
        sort(white.begin(),white.end(),cmp);
        cnt++;
    }

    for(int i=0;i<m;i++)
        printf("%d\n",save[i]);
    return 0;
}
