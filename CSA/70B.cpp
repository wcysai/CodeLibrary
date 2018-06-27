#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
int cnt1[MAXN][MAXN],cnt2[MAXN][MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				cnt++;
				cnt1[i][j]=cnt;
			}
			else cnt=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i][j]==1)
			{
				cnt++;
				cnt2[i][j]=cnt;
			}
			else cnt=0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(cnt1[i][j]>=2&&cnt2[i][j]>=2)ans=max(ans,cnt1[i][j]+cnt2[i][j]-1);
	printf("%d\n",ans);
	return 0;
}