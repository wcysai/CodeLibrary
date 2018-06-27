#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,k;
string str;
map<string,ll> mp;
bool is_suffix(string x,string y)
{
	ll p=x.size(),q=y.size();
	if(p>q) return false;
	for(ll i=p-1;i>=0;i--)
		if(x[i]!=y[q-p+i]) return false;
	return true;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		mp.clear();
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			cin>>str;
			if(str[0]=='i')
			{
				cin>>str;
				scanf("%lld",&k);
				if(mp.find(str)==mp.end()) mp[str]=k; else mp[str]+=k;
			}
			else if(str[0]=='d')
			{
				cin>>str;
				if(mp.find(str)==mp.end()||mp[str]==0) {puts("Empty"); continue;}
				mp[str]=0;
			}
			else
			{
				cin>>str;
				ll cnt=0;
				for(auto it=mp.begin();it!=mp.end();it++)
					if(is_suffix(str,it->F)) cnt+=it->S;
				printf("%lld\n",cnt);
			}
		}
	}
	return 0;
}