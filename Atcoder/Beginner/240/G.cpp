#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,z,fact[MAXN];
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	fact[0]=1;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(int i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	x=max(-x,x); y=max(-y,y); z=max(-z,z);
	if(x+y+z>n) {puts("0"); return 0;}
	if((n-x-y-z)&1) {puts("0"); return 0;}
	int k=(n-x-y-z)/2;
	int ans=fact[n];
	ans=1LL*ans*pow_mod(fact[k],MOD-2)%MOD;
	ans=1LL*ans*pow_mod(fact[n-k],MOD-2)%MOD;
	ans=1LL*ans*fact[n]%MOD;
	ans=1LL*ans*pow_mod(fact[x+k],MOD-2)%MOD;
	ans=1LL*ans*pow_mod(fact[y+k],MOD-2)%MOD;
	ans=1LL*ans*pow_mod(fact[z+k],MOD-2)%MOD;
	printf("%d\n",ans);
	return 0;
}