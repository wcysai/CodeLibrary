#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int r[2],p[2];
int go[2][MAXN][MAXN];
bool valid[MAXN][MAXN];
bool f;
int color[MAXN][MAXN];
vector<int> ans;
bool dfs(int v1,int v2)
{
    color[v1][v2]=1;
    valid[v1][v2]=false;
    if(v1==r[0]&&v2==r[1])
    {
        valid[v1][v2]=true;
        return true;
    }
    for(int c=1;c<=n;c++)
    {
        if(go[0][v1][c]==-1||go[1][v2][c]==-1) continue;
        int u1=go[0][v1][c],u2=go[1][v2][c];
        if(color[u1][u2]==1) continue;
        if(color[u1][u2]==0) dfs(u1,u2);
        valid[v1][v2]|=valid[u1][u2];
    }
    color[v1][v2]=2;
    return valid[v1][v2];
}
void dfs2(int v1,int v2)
{
    if(!f) return;
    if(v1==r[0]&&v2==r[1]) return;
    color[v1][v2]=1;
    for(int c=1;c<=n;c++)
    {
        if(go[0][v1][c]==-1||go[1][v2][c]==-1) continue;
        int u1=go[0][v1][c],u2=go[1][v2][c];
        if(!valid[u1][u2]) continue;
        if(color[u1][u2]==1) 
        {
            f=false;
            return;
        }
        if(color[u1][u2]==0) 
        {
            ans.push_back(c);
            dfs2(u1,u2);
            return;
        }
    }
    color[v1][v2]=2;
}
int main()
{
    freopen("mazes.in","r",stdin);
    freopen("mazes.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<2;i++)
    {
        memset(go[i],-1,sizeof(go[i]));
        scanf("%d%d",&r[i],&p[i]);
        for(int j=0;j<p[i];j++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            go[i][u][w]=v;
        }
    }
    memset(color,0,sizeof(color));
    dfs(1,1);
    if(!valid[1][1])
    {
        puts("no common solution");
        return 0;
    }
    f=true;
    memset(color,0,sizeof(color));
    dfs2(1,1);
    if(!f)
    {
        puts("no smallest solution");
        return 0;
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}
