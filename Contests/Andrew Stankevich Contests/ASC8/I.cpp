#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 21
#define MAXM 105
#define MAXK 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
vector<int> G[MAXN];
vector<P> edges;
vector<int> keys[MAXN];
vector<P> schedule[MAXN];
vector<int> events;
bool unlock[MAXM];
vector<int> open[MAXM];
int dp[10005][MAXN][2];
void update(int &x,int y) {x=min(x,y);}
int pre[10005][MAXN][2];
int adj(int v,P p)
{
    if(v==p.F) return p.S;
    else if(v==p.S) return p.F;
    else return -1;
}
vector<P> operations;
int main()
{
    freopen("secret.in","r",stdin);
    freopen("secret.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(edges.size()); G[v].push_back(edges.size());
        edges.push_back(P(u,v));
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
        int x; scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y;scanf("%d",&y);
            keys[i].push_back(--y);
        }
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y,z;
            scanf("%d%d",&y,&z);
            schedule[i].push_back(P(z,--y));
        }
    }
    int ans=INF,bestmask=-1;
    for(int mask=0;mask<(1<<k);mask++)
    {
        int res=0;
        memset(unlock,false,sizeof(unlock));
        for(int i=0;i<k;i++)
        {
            if(mask&(1<<i))
            {
                res+=a[i];
                for(int j=0;j<(int)keys[i].size();j++) unlock[keys[i][j]]=true;
            }
        }
        if(res+2*n-1>ans) continue;
        events.clear();
        for(int i=0;i<=2*n+2;i++) events.push_back(i);
        for(int i=0;i<k;i++)
            if(!(mask&(1<<i)))
                for(int j=0;j<(int)schedule[i].size();j++)
                    for(int l=-(n+1);l<=(n+1);l++)
                        if(schedule[i][j].F+l>=0&&schedule[i][j].F+l<28800) events.push_back(schedule[i][j].F+l);
        sort(events.begin(),events.end());
        events.erase(unique(events.begin(),events.end()),events.end());
        for(int i=0;i<m;i++) open[i].assign(events.size(),0);
        for(int i=0;i<k;i++)
        {
            if(!(mask&(1<<i)))
            {
                for(int j=0;j<(int)schedule[i].size();j++)
                {
                    int id=lower_bound(events.begin(),events.end(),schedule[i][j].F)-events.begin();
                    if(id<(int)events.size()) open[schedule[i][j].S][id]=1;
                }
            }
        }
        int sz=(int)events.size();
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i+1<sz;i++)
        {
            dp[i][1][0]=0;
            for(int j=1;j<=n;j++)
            {
                for(int k=0;k<=1;k++)
                {
                    if(dp[i][j][k]>INF) continue;
                    if(dp[i+1][j][k]>dp[i][j][k]+events[i+1]-events[i])
                    {
                        dp[i+1][j][k]=dp[i][j][k]+events[i+1]-events[i];
                        pre[i+1][j][k]=-1;
                    }
                    for(int l=0;l<(int)G[j].size();l++)
                    {
                        int id=G[j][l];
                        int to=adj(j,edges[id]);
                        if(k==1&&to==n) continue;
                        if(unlock[id]||open[id][i+1]) 
                        {
                            if(dp[i+1][to][k|(to==n)]>dp[i][j][k]+events[i+1]-events[i])
                            {
                                dp[i+1][to][k|(to==n)]=dp[i][j][k]+events[i+1]-events[i];
                                pre[i+1][to][k|(to==n)]=id;
                            }
                        }
                    }
                }
            }
        }
        int ret=INF,x=-1;
        for(int i=0;i<sz;i++) 
        {
            if(dp[i][1][1]<ret)
            {
                ret=dp[i][1][1];
                x=i;
            }
        }
        if(res+ret+1<ans)
        {
            ans=res+ret+1;
            bestmask=mask;
            operations.clear();
            int v=1,state=1;
            operations.push_back(P(events[x]+1,-1));
            while(v!=1||state!=0)
            {
                if(pre[x][v][state]==-1)
                {
                    x--;
                    continue;
                }
                operations.push_back(P(events[x],pre[x][v][state]+1));
                int id=pre[x][v][state];
                int to=adj(v,edges[id]);
                if(v==n&&to!=n) state=0;
                v=to;
                x--;
            }
            operations.push_back(P(events[x+1]-1,-1));
        }
    }
    if(ans==INF)
    {
        puts("mission impossible");
        return 0;
    }
    printf("%d\n",ans);
    printf("%d\n",__builtin_popcount(bestmask));
    for(int i=0;i<n;i++) if(bestmask&(1<<i)) printf("%d ",i+1);
    puts("");
    reverse(operations.begin(),operations.end());
    for(int i=0;i<(int)operations.size();i++) 
    {
        if(operations[i].S==-1) printf("%d\n",operations[i].F);
        else printf("%d %d\n",operations[i].S,operations[i].F);
    }
    return 0;
}
