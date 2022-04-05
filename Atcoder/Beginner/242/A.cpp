#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b,c;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
	if(n<=a) puts("1");
	else if(n<=b) printf("%.10f\n",1.0*c/(b-a));
	else puts("0");
	return 0;
}