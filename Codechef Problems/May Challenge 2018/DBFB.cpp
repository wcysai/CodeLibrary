#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int cnt1[MAXN],cnt2[MAXN],x,t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		cnt1[1]=1;cnt2[1]=0;cnt1[2]=0;cnt2[2]=1;
		for(int i=3;i<=n;i++)
		{
			cnt1[i]=(cnt1[i-1]+cnt1[i-2])%MOD;
			cnt2[i]=(cnt2[i-1]+cnt2[i-2])%MOD;
		}
		int s1=0,s2=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			s1=(s1+x)%MOD;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			s2=(s2+x)%MOD;
		}
		printf("%d\n",(int)((1LL*s1*cnt1[n]+1LL*s2*cnt2[n])%MOD*m%MOD));
	}
	return 0;
}