#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p;
int f[MAXN][MAXN],g[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=p) a-=p;}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    memset(f,0,sizeof(f));memset(g,0,sizeof(g));
    f[1][0]=1;
    for(int j=0;j<=m;j++) g[1][j]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=min(i-1,m);j++)
        {
            add(f[i][j],f[i-1][j-1]);
            for(int k=1;k<=i-2;k++) add(f[i][j],1LL*f[k][j-1]*g[i-k][min(j,m-j)]%p);
            if(j>1&&j!=m)
            {
                for(int k=1;k<=i-2;k++) add(f[i][j],1LL*g[k][min(j-2,m-j-1)]*f[i-k][j]%p);
            }
        }
        g[i][0]=f[i][0];
        for(int j=1;j<=m;j++) g[i][j]=g[i][j-1],add(g[i][j],f[i][j]);
    }
    printf("%d\n",g[n][m]);
    return 0;
}
