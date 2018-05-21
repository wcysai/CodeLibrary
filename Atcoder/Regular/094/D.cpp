#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll q,a,b;
int main()
{
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d",&a,&b);
		if(a==b) {printf("%I64d\n",2*a-2); continue;}
		ll c=(ll)sqrt(a*b);
		if(c*c==a*b) c--;
		if(c*(c+1)<a*b) printf("%I64d\n",2*c-1); else printf("%I64d\n",2*c-2);
	}
	return 0;
}