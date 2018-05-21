#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef long long ll;
char str[20][50];
char S[1000];
int main()
{
	for(int i=0;i<20;i++)
		scanf("%s",str[i]);
	for(int i=0;i<20;i++)
		for(int j=0;j<50;j++)
			S[i*50+j]=str[i][j];
	ll ans=0;
	for(int i=0;i<=987;i++)
	{
		ll product=1;
		for(int j=0;j<13;j++)
			product=product*(ll)(S[i+j]-'0');
		ans=max(ans,product);
	}
	printf("%lld\n",ans);
	return 0;
}