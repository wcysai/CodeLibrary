#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]) x++;
		else 
		{
			for(int j=1;j<=n;j++) if(b[j]==a[i]) y++;
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}