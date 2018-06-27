#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	ll s=0;
	int res=INF;
	bool f=true;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]!=b[i]) f=false;
		s+=a[i];
		if(a[i]>b[i]) res=min(res,b[i]);
	}
	if(f) puts("0"); else printf("%lld\n",s-res);
	return 0;
}