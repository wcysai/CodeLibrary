#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,q,a[31][MAXN],sum[31][MAXN];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=0;j<=30;j++)
		{
			a[j][i]=x&1;
			x>>=1;
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=0;i<=30;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+a[i][j];
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0,k=1;
		for(int j=0;j<=30;j++)
		{
			int len=r-l+1;
			if(2*(sum[j][r]-sum[j][l-1])-len<0) ans+=k;
			k<<=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}