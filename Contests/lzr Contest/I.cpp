#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 8005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],maxi[MAXN][MAXN];
int sum[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        maxi[i][i]=a[i];
        for(int j=i+1;j<=n;j++) maxi[i][j]=max(a[j],maxi[i][j-1]);
    }
    for(int i=1;i<=n;i++)
    {
        int len=n-i+1,ans=INF;
        for(int j=1;j+len-1<=n;j++)
        {
            int l=j,r=j+len-1;
            if(maxi[l][r]==maxi[1][n]) ans=min(ans,sum[n]-(sum[r]-sum[l-1])+maxi[l][r]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

