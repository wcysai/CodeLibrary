#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define left rice
#define MAXN 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,a[MAXN][MAXN];
int p[MAXN],lab[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void init(int n)
{
    for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x!=y) p[x]=y;
}
int left[MAXN];
int dp[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                for(int k=i+1;k<=j;k++) unite(k-1,k);
        }
    for(int i=1;i<=n;i++)
        if(find(i)==i) lab[i]=++tot;
    bool f=true;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(a[i][j]==2)
            {
                int l=INF,r=-INF;
                for(int k=i;k<=j;k++) {l=min(l,lab[find(k)]); r=max(r,lab[find(k)]);}
                if(l==r) f=false;
                left[r]=max(left[r],l);
            }
    if(!f) {puts("0"); return 0;}
    dp[1][0]=2;
    for(int i=1;i<tot;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            if(left[i+1]<=j) add(dp[i+1][j],dp[i][j]);
            add(dp[i+1][i],dp[i][j]);
        }
    }
    int ans=0;
    for(int j=0;j<=tot;j++) add(ans,dp[tot][j]);
    printf("%d\n",ans);
    return 0;
}

