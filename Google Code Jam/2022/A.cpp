#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,r,c;
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d%d",&r,&c);
		printf("Case #%d:\n",t);
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=2*c+1;j++) 
				if(i==1&&j<=2) printf("."); else if(j&1) printf("+"); else printf("-");
			puts("");
			for(int j=1;j<=2*c+1;j++) 
				if(i==1&&j==1) printf("."); else if(j&1) printf("|"); else printf(".");
			puts("");
		}
		for(int j=1;j<=2*c+1;j++) if(j&1) printf("+"); else printf("-");
		puts("");
	}
	return 0;
}