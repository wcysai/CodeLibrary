#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int a,b,c,x,y;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	int ans=0;
	int k=min(x,y);
	ans+=min(c*2*k,a*k+b*k);
	x-=k,y-=k;
	if(x>0) ans+=min(c*2*x,a*x);
	else ans+=min(c*2*y,b*y);
	printf("%d\n",ans);
	return 0;
}