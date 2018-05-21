#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main()
{
	int ans=0;
	for(int i=10;i<=100;i++)
	{
		int s=1;
		for(int j=1;j<=i/2;j++)
		{
			s=s*(i-j+1)/j;
			if(s>1000000)
			{
				ans+=i-1-2*(j-1);
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}