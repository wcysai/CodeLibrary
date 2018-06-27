#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt[MAXN];
int main()
{
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	int ans=0;
	for(int i=1;i<=200000;i++)
		ans+=cnt[i]/2;
	printf("%d\n",ans/2);
	return 0;
}