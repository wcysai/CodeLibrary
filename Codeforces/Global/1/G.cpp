#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
vector<int> G[MAXN];
int deg[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) deg[i]=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++;deg[v]++;
        }
        bool f=false;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]>=4)
            {
                f=true;
                break;
            }
            else if(deg[i]>=3)
            {
                int cnt=0;
                for(auto to:G[i])
                {
                    if(deg[to]>=2) cnt++;
                }
                if(cnt>=2)
                {
                    f=true;
                    break;
                }
            }
            else if(deg[i]==2)
            {
                int cnt=0;
                for(auto to:G[i])
                {
                    if(deg[to]>=3) cnt++;
                }
                if(cnt==2)
                {
                    f=true;
                    break;
                }
            }
        }   
        if(f) puts("White"); else puts("Draw");
    }
    return 0;
}

