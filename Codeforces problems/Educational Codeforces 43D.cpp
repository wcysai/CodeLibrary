#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],deg[MAXN];
bool connected[MAXN][MAXN];
int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(connected,true,sizeof(connected));
	for(int i=1;i<=a[n]+1;i++)
		deg[i]=a[n];
	int t=1,now=1;
	while(now<=a[n]+1&&t<=n)
	{
		if(deg[now]>a[t])
		{
			for(int j=now+1;j<=now+deg[now]-a[t];j++)
			{
				connected[now][j]=false;
				deg[j]--;
			}
			deg[now]=a[t];
			now++;
		}
		if(t==n) break;
		while(deg[now]<a[t+1])
		{
			for(int j=now+1;j<=now+deg[now]-a[t];j++)
			{
				connected[now][j]=false;
				deg[j]--;
			}
			deg[now]=a[t];
			now++;
		}
		t++;
	}
	int cnt=0;
	for(int i=1;i<=a[n]+1;i++)
		for(int j=i+1;j<=a[n]+1;j++)
			if(connected[i][j]) cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=a[n]+1;i++)
		for(int j=i+1;j<=a[n]+1;j++)
			if(connected[i][j]) printf("%d %d\n",i,j);
	puts("Valid");
	return 0;
}