#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 500005
#define MAXK 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
inline int read(){
    char c = getchar();
    int ret =0;
    while (c>'9'||c<'0')c = getchar();
    while (c>='0'&&c<='9')ret = ret*10+c-'0',c = getchar();
    return ret;
}
int dp[3][MAXK];
int k,n,t[MAXN];
int main()
{
	k=read();n=read();
	for(int i=1;i<=n;i++) t[i]=read();
	sort(t+1,t+n+1);
	for(int i=1;i<n;i++) t[i]=t[i+1]-t[i];
	n--;
	for(int i=0;i<3;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=INF;
	dp[0][0]=dp[1][0]=dp[2][0]=0;
	dp[1][1]=t[1];
	int tt=1;
	for(int i=2;i<=n;i++)
	{
		tt++;
		if(tt==3) tt-=3;
		int tt1=tt-1,tt2=tt-2;
		if(tt1<0) tt1+=3;
		if(tt2<0) tt2+=3;
		for(int j=1;j<=k;j++)
			dp[tt][j]=min(dp[tt1][j],dp[tt2][j-1]+t[i]);
	}
	printf("%d\n",dp[tt][k]);
	return 0;
}