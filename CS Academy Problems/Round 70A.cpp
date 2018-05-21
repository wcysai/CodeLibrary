#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	int res=0,ans=a;
	for(int i=a;i<=b;i++)
	{
		int t=i,cnt=0;
		if(t==0) cnt=1;
		while(t>0)
		{
			int num=t%10;
			t=t/10;
			if(num==0||num==6||num==9) cnt++;
			if(num==8) cnt+=2;
		}
		if(cnt>res)
		{
			res=cnt;
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}