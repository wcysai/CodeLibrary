#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll t[10][5];
int main()
{
	for(ll i=0;i<10;i++)
		scanf("%I64d%I64d",&t[i][0],&t[i][1]);
	for(ll i=0;i<10;i++)
		scanf("%I64d%I64d%I64d",&t[i][2],&t[i][3],&t[i][4]);
	ll ti=0;
	for(ll k=0;k<3;k++)
	{
		for(ll i=0;i<10;i++)
		{
			if(ti<t[i][4]||(ti-t[i][4])%(t[i][2]+t[i][3])>=t[i][2])
			{
				ll rest=ti<t[i][4]?t[i][4]-ti:t[i][2]+t[i][3]-((ti-t[i][4])%(t[i][2]+t[i][3]));
				ti+=t[i][0]+t[i][1];
				if(rest<t[i][0]) t[i][4]+=t[i][0]-rest;
			}
			else
			{
				ll work=t[i][2]-((ti-t[i][4])%(t[i][2]+t[i][3]));
				ti+=work+t[i][0]+t[i][1];
				if(t[i][0]>t[i][3]) t[i][4]+=t[i][0]-t[i][3];
			}
		}
	}
	ti-=t[9][3];
	printf("%I64d\n",ti);
	return 0;
}