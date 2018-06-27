#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],num[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int now=1;
	memset(num,0,sizeof(num));
	for(int i=2;i<=n;i++)
	{
		if(a[now]>a[i]) num[now]++;
		else
		{
			num[i]++;
			now=i;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	return 0;
}