#include<bits/stdc++.h>
#define MAXN 450000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int cnt[MAXN];
bool is_palindrome(int x)
{
	int a[10],t=0;
	memset(a,0,sizeof(a));
	while(x)
	{
		a[t++]=x%10;
		x=x/10;
	}
	for(int i=0;i<t;i++)
		if(a[i]!=a[t-1-i]) return false;
	return true;
}
//207427364
int main()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i*i*i<=900000000;i++)
	{
		for(int j=1;i*i*i+j*j<=900000000;j++)
		{
			if(i*i*i+j*j<450000000) continue;
			cnt[i*i*i+j*j-450000000]++;
		}
	}
	int sum=207427364;
	for(int i=1;i<=450000000;i++)
		if(cnt[i]==4&&is_palindrome(i+450000000)) {printf("%d\n",i+450000000); sum+=i+450000000;}
	printf("%d\n",sum);
	return 0;
}