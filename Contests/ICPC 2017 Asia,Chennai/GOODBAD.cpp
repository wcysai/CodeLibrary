#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
char str[MAXN];
int t,n,k,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",str);
		a=b=0;
		for(int i=0;i<n;i++)
			if(str[i]>='A'&&str[i]<='Z') a++; else b++;
		if(b<=k&&a>k) puts("brother");
		else if(b>k&&a<=k) puts("chef");
		else if(a<=k&&b<=k) puts("both");
		else puts("none");
	}
	return 0;
}