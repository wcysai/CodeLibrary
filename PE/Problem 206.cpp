#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod[10]={10000000000000000,100000000000000,1000000000000,10000000000,100000000,1000000,10000,100,1};
int main()
{
	for(ll i=1e8;;i+=1)
	{
		ll res=i*i;
		if(res<0) break;
		if(res/mod[0]==1&&(res/mod[1])%10==2&&(res/mod[2])%10==3&&(res/mod[3])%10==4&&(res/mod[4])%10==5&&(res/mod[5])%10==6&&(res/mod[6])%10==7&&(res/mod[7])%10==8&&(res%10==9))
		{
			printf("%lld %lld\n",i,res);
			return 0;
		}
	}
	return 0;
}