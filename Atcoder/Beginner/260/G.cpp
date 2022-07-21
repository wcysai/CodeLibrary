#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
char str[MAXN][MAXN];
int ans[MAXN][MAXN];
int d1[MAXN],d2[MAXN];
vector<P> v1[MAXN],v2[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(str[i][j]=='O')
            {
                int last=i+m;
                v1[last].push_back(P(j,1));
                v1[i-1].push_back(P(j,-1));
                v2[last].push_back(P(j,-1));
                v2[i-1].push_back(P(j+2*(last-(i-1)),1));
            }
        }
    for(int i=n+m;i>=1;i--)
    {
        for(auto p:v1[i]) if(p.F<=n) d1[p.F]+=p.S;
        for(int j=n;j>=2;j--) d2[j]=d2[j-2];
        d2[0]=d2[1]=0;
        for(auto p:v2[i]) if(p.F<=n) d2[p.F]+=p.S;
        for(int j=1;j<=n;j++) ans[i][j]=ans[i][j-1]+d1[j]+d2[j];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[x][y]);
    }
    return 0;
}

