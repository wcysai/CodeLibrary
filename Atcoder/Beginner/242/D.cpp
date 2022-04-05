#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n,q;
ll t,k;
char solve(ll t,ll k)
{
	if(t==0) return str[k];
	else if(k==1) return (char)('A'+((str[1]-'A'+t)%3));
	else
	{
		char ch=solve(t-1,(k+1)/2);
		if(k&1) return (char)('A'+(ch-'A'+1)%3);
		else return (char)('A'+(ch-'A'+2)%3);
	}
}
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld",&t,&k);
		printf("%c\n",solve(t,k));
	}
	return 0;
}