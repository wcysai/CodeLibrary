#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll fact[100][15],save[15];
bool used[100];
ll comb(ll n,ll k)
{
	if(k>n-k) return comb(n,n-k);
	ll s=1;
	memset(used,false,sizeof(used));
	for(ll i=(n-k+1);i<=n;i++)
	{
		s=s*i;
		for(ll j=1;j<=k;j++)
		{
			if(!used[j]&&s%j==0)
			{
				s=s/j;
				used[j]=true;
			}
		}
	}
	return s;
}
set<ll> s;
int main()
{
	s.clear();
	ll ans=0;
	for(ll i=1;i<=50;i++)
	{
		ll t=i;
		for(ll j=0;j<15;j++)
			while(t%prime[j]==0) {t=t/prime[j]; fact[i][j]++;}
	}
	for(ll i=1;i<=50;i++)
	{
		for(ll j=0;j<=i;j++)
		{
			memset(save,0,sizeof(save));
			for(ll k=j+1;k<=i;k++)
				for(ll l=0;l<15;l++)
					save[l]+=fact[k][l];
			for(ll k=1;k<=i-j;k++)
				for(ll l=0;l<15;l++)
					save[l]-=fact[k][l];
			bool f=true;
			for(ll k=0;k<15;k++)
				if(save[k]>1) {f=false; break;}
			if(f) 
			{
				ll res=comb(i,j);
				if(s.count(res)==0)
				{
					ans+=res;
					s.insert(res);
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}