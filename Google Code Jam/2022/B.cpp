#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a[5][5];
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<4;j++)
				scanf("%d",&a[i][j]);
		int s=0;
		for(int i=0;i<4;i++)
		{
			a[3][i]=INF;
			for(int j=0;j<3;j++) a[3][i]=min(a[3][i],a[j][i]);
			s+=a[3][i];
		}
		printf("Case #%d: ",t);
		if(s<1000000) {puts("IMPOSSIBLE"); continue;}
		s=1000000;
		for(int i=0;i<4;i++) 
		{
			printf("%d ",min(s,a[3][i]));
			s-=min(s,a[3][i]);
		}
		puts("");
	}
	return 0;
}