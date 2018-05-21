#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
bool used[21];
int main()
{
	ll s=1;
	memset(used,false,sizeof(used));
	for(ll i=21;i<=40;i++)
	{
		s=s*i;
		for(ll j=1;j<=20;j++)
			if(!used[j]&&s%j==0)
			{
				s=s/j;
				used[j]=true;
			}
	}
	printf("%lld\n",s);
	return 0;
}