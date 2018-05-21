#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a+c>b+d) {puts("1"); continue;}
		if(a+c<b+d) {puts("2"); continue;}
		if(c>b) puts("1");
		else if(c<b) puts("2");
		else puts("-1"); 
	}
	return 0;
}