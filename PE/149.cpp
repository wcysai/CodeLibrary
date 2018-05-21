#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll num[2000][2000];
int main()
{
	memset(num,0,sizeof(num));
	for(ll i=0;i<2000;i++)
		for(ll j=0;j<2000;j++)
		{
			ll k=i*2000+j+1;
			if(k<=55) num[i][j]=(100003-200003*k+300007*k*k*k)%1000000-500000;
			else 
			{
				ll ni=i,nj=j-24;
				if(nj<0) {nj+=2000; ni--;}
				num[i][j]+=num[ni][nj];
				ni=i,nj=j-55;
				if(nj<0) {nj+=2000; ni--;}
				num[i][j]+=num[ni][nj];
				num[i][j]=(num[i][j]+1000000)%1000000-500000;
			}
			//if(k==10||k==100) printf("%lld\n",num[i][j]);
		}
	ll ans=0;
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<2000;j++)
		{
			now+=num[i][j];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<2000;j++)
		{
			now+=num[j][i];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<2000-i;j++)
		{
			now+=num[i+j][j];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<2000-i;j++)
		{
			now+=num[j][i+j];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<i;j++)
		{
			now+=num[j][i-j];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	for(int i=0;i<2000;i++)
	{
		ll res=0,now=0;
		for(int j=0;j<i;j++)
		{
			now+=num[i-j][j];
			res=max(res,now);
			if(now<0) now=0;
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}