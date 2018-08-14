#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool winning[33];
int main()
{
	memset(winning,false,sizeof(winning));
	for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d",&x);
		winning[x]=true;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<6;j++)
		{
			int x;
			scanf("%d",&x);
			if(winning[x]) cnt++;
		}
		if(cnt>=3) puts("Lucky"); else puts("Unlucky");
	}
	return 0;
}