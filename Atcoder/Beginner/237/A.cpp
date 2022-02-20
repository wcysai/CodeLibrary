#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int main()
{
	scanf("%lld",&n);
	ll x=(1LL<<31);
	if(n>=-x&&n<=x-1) puts("Yes"); else puts("No");
	return 0;
}