#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a,b;
bool vis[MAXN*MAXN];
int state[MAXN*MAXN];
//0: lose 1:win 2:
vector<int> G[MAXN*MAXN];
deque<int> deq;
int deg[MAXN*MAXN];
void add_edge(int a1,int b1,int a2,int b2)
{
    int x=(a1)*n+b1+1,y=a2*n+b2+1;
    G[y].push_back(x);
    deg[x]++;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n*n;i++) G[i].clear(),deg[i]=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;j<=n-1;j++)
            {
                add_edge(i,j,j,(i+j)%n);
                add_edge(i,j,j,i*j%n);
            }
        }
        deq.clear();
        for(int i=1;i<=n-1;i++)
        {
            int x=i*n+1;
            vis[x]=true;
            state[x]=0;
            deq.push_back(x);
        }
        while(deq.size())
        {
            int x=deq.front();
            deq.pop_front();
            if(!state[x])
            {
                for(auto to:G[x])
                {
                    if(vis[to]) continue;
                    vis[to]=true;
                    state[to]=1;
                    deq.push_back(to);
                }
            }
            else
            {
                for(auto to:G[x])
                {
                    if(vis[to]) continue;
                    deg[to]--;
                    if(deg[to]==0)
                    {
                        vis[to]=true;
                        state[to]=0;
                        deq.push_front(to);
                    }
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&a,&b);
            int x=a*n+b+1;
            if(vis[x])
            {
                if(state[x]) puts("cocktail");
                else puts("sys");
            }
            else puts("draw");
        }
    }
}
