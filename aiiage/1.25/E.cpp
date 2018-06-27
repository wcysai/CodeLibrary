#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
int ans1[8]={0,1,3,4,2,3,1,0};
int ans2[8]={0,1,1,0,0,1,1,0};
int query,n;
int main()
{
	scanf("%d",&query);
	while(query--)
	{
		scanf("%d",&n);
		if(n<=8) printf("%d\n",ans1[n%8]); else printf("%d\n",ans2[n%8]);
	}
	return 0;
}