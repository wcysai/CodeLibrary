#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int x,y;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d%d",&x,&y);
	if(gcd(x,y)==y)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",x);
	return 0;
}