#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,k;
int a[MAXN],b[MAXN];
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	int res=-INF;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		res=max(res,b[i]);
		a[i]-=b[i];
		if(a[i]<0)	f=false;
		ans=gcd(ans,a[i]);
	}
	if(!f||(ans<=res&&ans!=0))
	{
		printf("-1\n");
		return 0;
	}
	if(ans==0)
	{
		printf("%d\n",res+1);
		return 0;
	}
	vector<int> divisor;
	for(int i=1;i*i<=ans;i++)
	{
		if(ans%i==0) 
		{
			divisor.push_back(i);
			if(i*i!=ans) divisor.push_back(ans/i);
		}
	}
	sort(divisor.begin(),divisor.end());
	for(int i=0;i<divisor.size();i++)
	{
		if(divisor[i]>res)
		{
			printf("%d\n",divisor[i]);
			return 0;
		}
	}
	return 0;
}