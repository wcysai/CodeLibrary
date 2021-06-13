#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int color[MAXN];
bool G[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v]=G[v][u]=true;
    }
    for(int i=1;i<=n;i++)
    {
        int cw=0,cb=0;
        for(int j=1;j<i;j++)
        {
            if(G[j][i])
            {
                if(!color[j]) cw++;
                else cb++;
            }
        }
        if(cw>=cb) color[i]=1; else color[i]=0;
    }
    for(int i=1;i<=n;i++) printf("%d%c",color[i],i==n?'\n':' ');
    return 0;
}