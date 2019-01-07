#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,k,a[MAXN];
db dp[MAXN][MAXN][MAXN];
int cnt1,cnt2,cnt3;
db solve(int cnt1,int cnt2,int cnt3)
{
    if(cnt1<0||cnt2<0||cnt3<0) return 0;
    if(cnt1==0&&cnt2==0&&cnt3==0) return 0;
    if(dp[cnt1][cnt2][cnt3]!=-1.0) return dp[cnt1][cnt2][cnt3];
    db res=cnt1*solve(cnt1-1,cnt2,cnt3)+cnt2*solve(cnt1+1,cnt2-1,cnt3)+cnt3*solve(cnt1,cnt2+1,cnt3-1);
    return dp[cnt1][cnt2][cnt3]=(res+n)/(cnt1+cnt2+cnt3);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(x==1) cnt1++; else if(x==2) cnt2++; else cnt3++;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=-1;
    printf("%.15Lf\n",solve(cnt1,cnt2,cnt3));
    return 0;
}

