#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double x,y,z;
		double ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&z);
			ans+=y*(x-x*(1+z/100)*(1-z/100));
		}
		printf("%.10f\n",ans);
	}
	return 0;
}