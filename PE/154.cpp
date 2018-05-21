#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll two[MAXN],five[MAXN];
int main()
{
	two[0]=five[0]=0;
	two[1]=five[1]=0;
	for(ll i=2;i<=200000;i++)
	{
		ll cnt2=0,cnt5=0,t=i;
		while(t%2==0) t=t/2,cnt2++;
		while(t%5==0) t=t/5,cnt5++;
		two[i]=two[i-1]+cnt2;five[i]=five[i-1]+cnt5;
	}
	ll ans=0;
	for(ll i=0;i<=200000/3;i++)
	{
		for(ll j=i;j<=200000-i-j;j++)
		{
			ll k=200000-i-j;
			if(min(two[200000]-two[i]-two[j]-two[k],five[200000]-five[i]-five[j]-five[k])>=12)
			{
				if(i!=j&&j!=k) ans+=6;
				else if(i==j&&j==k) ans++;
				else ans+=3;
			}
		}
		if(i%10000==0) printf("%I64d\n",ans);
	}
	printf("%I64d\n",ans);
	return 0;
}