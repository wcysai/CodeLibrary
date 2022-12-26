#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c,a[2*MAXN],b[2*MAXN];
vector<int> v;
ll dp[MAXN][3];
ll ans=0;
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=2*n-1;i+=2) {
        b[i]=min(c,a[i]);
        ans+=b[i];
    }
    if(n==1){
        printf("%lld\n",ans); return 0;
    }
    printf("ans=%lld\n",ans);
    for(int i=2;i<=2*n-1;i+=2){
        v.push_back(max(0,min(c,a[i]+a[i+1]+a[i-1])-b[i-1]-b[i+1]));
        printf("%d ",v.back());
    }
    puts("");
    dp[0][1]=v[0]; dp[0][2]=2*v[0];
    for(int i=1;i<n-1;i++){
        for(int j=0;j<=2;j++){
            for(int k=0;j+k<=2;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][k]+j*v[i]);
        }
    }
    ll res=0;
    for(int i=0;i<=2;i++) res=max(res,dp[n-2][i]/2);
    printf("%lld\n",res+ans);
    return 0;
}

