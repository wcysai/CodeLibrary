#include<bits/stdc++.h>
#define MAXT 1000005
using namespace std;
int n,t;
int cnt[MAXT],times[MAXT];
int main()
{
	scanf("%d%d",&n,&t);
	int maxi=0;
	memset(cnt,0,sizeof(cnt));
	memset(times,0,sizeof(times));
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		maxi=max(maxi,x);
		cnt[x]++;
	}
	for(int i=1;i<=maxi;i++)
	{
		if(cnt[i])
		{
			for(int j=i;j<=t;j+=i)
				times[j]+=cnt[i];
		}
	}
	int res=0,id=0,cnt=0;
	for(int i=1;i<=t;i++)
	{
		if(times[i]>res)
		{
			res=times[i];
			id=i;
			cnt=1;
		}
		else if(times[i]==res) cnt++;
	}
	printf("%d %d\n",res,id==0?t:cnt);
	return 0;
}