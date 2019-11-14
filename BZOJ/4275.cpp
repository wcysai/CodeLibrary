#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    scanf("%d",&k);
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1; else f[i][j]=max(f[i-1][j],f[i][j-1]);
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            if(a[i]==b[j]) g[i][j]=g[i+1][j+1]+1; else g[i][j]=max(g[i+1][j],g[i][j+1]);
    if(!k)
    {
        printf("%d\n",f[n][m]);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int pos=i;
        for(int j=1;j<=k;j++)
        {
            while(pos<=n&&a[pos]!=c[j]) pos++;
            if(pos>n) break; else if(j!=k) pos++;
        }
        d[i]=pos;
    }
    for(int i=1;i<=m;i++)
    {
        int pos=i;
        for(int j=1;j<=k;j++)
        {
            while(pos<=m&&b[pos]!=c[j]) pos++;
            if(pos>m) break; else if(j!=k) pos++;
        }
        e[i]=pos;
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(d[i]>n||e[j]>m) continue;
            ans=max(ans,f[i-1][j-1]+k+g[d[i]+1][e[j]+1]);
        }
    printf("%d\n",ans);
    return 0;
}
