#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,a[4];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
		sort(a,a+4);
		printf((a[0]==a[1]&&a[2]==a[3])?"YES\n":"NO\n");
	}
	return 0;
}
