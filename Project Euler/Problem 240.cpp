#include<bits/stdc++.h>
#define MAXN 32
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll fact[MAXN],cnt[MAXN];
ll count(vector <int> &dices)
{
	memset(cnt,0,sizeof(cnt));
	for(ll i=0;i<20;i++)
		cnt[dices[i]]++;
	ll res=fact[20];
	for(ll i=1;i<=12;i++) res=res/fact[cnt[i]];
	return res;
}
ll dfs(vector<int> &dices)
{
	if(dices.size()==20) return count(dices);
	if(dices.size()==10)
	{
		ll sum=0;
		for(auto x:dices) sum+=x;
		if(sum!=70) return 0;
	}
	ll maxi=dices.size()==0?12:dices.back();
	ll res=0;
	for(ll i=1;i<=maxi;i++)
	{
		dices.push_back(i);
		res+=dfs(dices);
		dices.pop_back();
	}
	return res;
}
int main()
{
	fact[0]=1;
	for(ll i=1;i<=30;i++)
		fact[i]=fact[i-1]*i;
	vector<int> dices;
	dices.clear();
	printf("%I64d\n",dfs(dices));
	return 0;
}