#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll save[12];
ll find_ans(ll x)
{
	if(x<=7) return x*(1+x)/2;
	ll res=1,cnt=0,ans=0;
	while(res*7<=x)
	{
		res*=7;
		cnt++;
	}
	ll num=x/res;
	ans+=(1+num)*num/2*save[cnt]+(num+1)*find_ans(x%res);
}
int main()
{
	save[1]=28;
	for(int i=2;i<12;i++)
		save[i]=save[i-1]*28;
	printf("%lld\n",find_ans(1000000000));
}