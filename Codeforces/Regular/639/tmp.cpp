#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
int n;
const int N=22;
int a[N][N],f[1<<N];
int dp[N][1<<N];
int cnt;
int calc(int row,int x) {
	int sum=0,i=0;
    x=f[x];
	while(x>0) {
		i++;
		if(x&1) {
			sum+=a[row][i];
		}
		x>>=1;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<(1<<n);i++) {
		if(i&(i>>1)==0) {
			f[++cnt]=i;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=cnt;j++) {
			int val=calc(i,j);
			dp[i][j]=val;
			for(int k=1;k<=cnt;k++) {
				if(f[j]&f[k]==0) {
					dp[i][j]=max(dp[i][j],dp[i-1][k]+val);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=cnt;i++) {
		ans=max(ans,dp[n][i]);
	}
	printf("%d",ans);
	return 0;
}