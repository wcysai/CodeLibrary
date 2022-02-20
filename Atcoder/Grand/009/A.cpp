#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
int main()
{
	ll s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=n;i>=1;i--)
	{
		int mod=(s+a[i])%b[i];
		s+=(mod?b[i]-mod:0);
	}
	printf("%lld\n",s);
	return 0;
}