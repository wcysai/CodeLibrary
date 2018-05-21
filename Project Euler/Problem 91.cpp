#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int ans=7500;
	for(int x1=1;x1<=50;x1++)
		for(int y1=1;y1<=50;y1++)
		{
			int dx=x1/gcd(x1,y1),dy=y1/gcd(x1,y1);
			swap(dx,dy);
			ans+=min(y1/dy,(50-x1)/dx);
			ans+=min(x1/dx,(50-y1)/dy);
		}
	printf("%d\n",ans);
	return 0;
}