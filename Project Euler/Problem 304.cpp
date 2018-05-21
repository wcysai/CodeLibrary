#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1234567891011
#define F first
#define S second
using namespace std;
typedef long long ll;
int main()
{
	for(ll i=1000000;i<=1000000000;i++)
		if(i*i%MOD==5) {printf("%I64d\n",i); return 0;}
	return 0;
}