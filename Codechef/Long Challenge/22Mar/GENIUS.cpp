#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,x;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		x+=n;
		int need=x/4;
		int mod=x%4;
		if(need+mod>n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %d %d\n",need,n-need-mod,mod);
	}
	return 0;
}