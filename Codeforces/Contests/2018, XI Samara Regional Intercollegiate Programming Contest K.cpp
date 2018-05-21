#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],num[MAXN];
bool C(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=cnt) cnt++;
		else
		{
			if(x>0)
			{
				x--;
				cnt++;
			}
		}
	}
	return cnt>=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=-1,r=n;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) r=mid; else l=mid;
	}
	printf("%d\n",r);
	return 0;
}