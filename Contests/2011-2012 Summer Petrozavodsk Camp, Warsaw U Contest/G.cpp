#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,cur;
vector<int> G[MAXN];
bool del[MAXN];
int deg[MAXN];
bool has[MAXN];
void delete_vertex(int v)
{
    for(auto to:G[v])
    {
        if(del[to]) continue;
        deg[to]--;
    }
    del[v]=true;
}
int main()
{
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    memset(del,false,sizeof(del));
    cur=n;
    for(int i=1;i<=n/3;i++)
    {
        bool flag=false;
        for(int j=1;j<=n;j++)
        {
            if(flag) break;
            if(del[j]) continue;
            if(deg[j]!=cur-1)
            {
                memset(has,false,sizeof(has));
                for(auto to:G[j]) has[to]=true;
                for(int k=1;k<=n;k++)
                {
                    if(j==k) continue;
                    if(!has[k]&&!del[k])
                    {
                        delete_vertex(k);
                        delete_vertex(j);
                        flag=true;
                        cur-=2;
                        break;
                    }
                }
            }
        }
        if(!flag) break;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!del[i])
        {
            printf("%d ",i);
            cnt++;
        }
        if(cnt==n/3) break;
    }
    return 0;
}
