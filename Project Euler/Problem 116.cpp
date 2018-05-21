#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
typedef long long ll;
ll red[MAXN],green[MAXN],blue[MAXN];
int main()
{
	memset(red,0,sizeof(red));//red[i]=2*red[i-2]+red[i-3]
	memset(green,0,sizeof(green));//green[i]=2*green[i-3]+green[i-4]+green[i-5]
	memset(blue,0,sizeof(blue));//blue[i]=2*blue[i-4]+blue[i-5]+blue[i-6]+blue[i-7]
	red[1]=1;
	red[2]=2;
	green[1]=1;
	green[2]=1;
	green[3]=2;
	blue[1]=1;
	blue[2]=1;
	blue[3]=1;
	blue[4]=2;
	for(ll i=3;i<=50;i++)
		red[i]=red[i-2]+red[i-1];
	for(ll i=4;i<=50;i++)
		green[i]=green[i-3]+green[i-1];
	for(ll i=5;i<=50;i++)
		blue[i]=blue[i-4]+blue[i-1];
	printf("%I64d\n",red[50]+green[50]+blue[50]-3);
	return 0;
}