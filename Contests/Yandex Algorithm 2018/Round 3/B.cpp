#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
ll a[MAXN],d[MAXN];
string str[MAXN];
bool cmp(string x,string y)
{
	while(x.size()<y.size()) x=x+'0';
	while(y.size()<x.size()) y=y+'0';
	return x>=y;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		str[i]="";
		ll t=a[i];
		while(t>0)
		{
			str[i]=(char)('0'+(t&1))+str[i];
			t=t/2;
		}
		//cout<<str[i]<<endl;
		d[i]=str[i].size();
	}
	ll ans=0;
	for(ll i=1;i<n;i++)
	{
		if(a[i]==0&&a[i-1]>0) {puts("-1"); return 0;}
		if(d[i]>d[i-1]) continue;
		if(cmp(str[i],str[i-1])) {ans+=d[i-1]-d[i]; d[i]=d[i-1];}
		else {ans+=d[i-1]+1-d[i]; d[i]=d[i-1]+1;}
	}
	printf("%lld\n",ans);
	return 0;
}