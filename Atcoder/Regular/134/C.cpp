#include<bits/stdc++.h>
#define MAXN 200005
#define MAXQ 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int inv[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
int comb(int n,int k)
{
	if(n<k) return 0;
	int ans=1;
	for(int i=n;i>=n-k+1;i--) ans=1LL*ans*i%MOD;
	ans=1LL*ans*invf[k]%MOD;
	return ans;
}
int main()
{
	inv[1]=1;
	for (int i=2;i<=200;i++) inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	invf[0]=1;
	for(int i=1;i<=200;i++) invf[i]=1LL*invf[i-1]*inv[i]%MOD;
	scanf("%d%d",&n,&k);
	ll s=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s-a[1]+k>a[1]) {puts("0"); return 0;}
	int rem=(a[1]-(s-a[1]));
	int ans=1;
	ans=1LL*ans*comb(rem-1,k-1)%MOD;
	for(int i=2;i<=n;i++) ans=1LL*ans*comb(a[i]+k-1,k-1)%MOD;
	printf("%d\n",ans);
	return 0;
}