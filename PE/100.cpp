#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main()
{
	ll b=15,n=21;
	while(n<1000000000000)
	{
		ll tb=3*b+2*n-2;
		ll tn=4*b+3*n-3;
		b=tb;
		n=tn;
	}
	printf("%I64d\n",b);
	return 0;
}