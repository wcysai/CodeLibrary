#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
map<ll,bool> mymap;
int main()
{
	ll ans=1;
	for(ll base=2;base<=1000000;base++)
	{
		ll now=base*base+base+1,t=base*base;
		while(now<1000000000000)
		{
			if(mymap.find(now)==mymap.end())
			{
				//printf("%I64d\n",now);
				mymap[now]=true;
				ans+=now;
			}
			t=t*base;
			now=now+t;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}