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
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int id=lower_bound(a,a+n,a[n-1]/2)-a;
	if(id==0) printf("%d %d\n",a[n-1],a[id]);
	else if(id==n-1) printf("%d %d\n",a[n-1],a[n-2]);
	else 
	{
		int x=a[id],y=a[id-1];
		int res1=max(x*2-a[n-1],a[n-1]-x*2),res2=max(y*2-a[n-1],a[n-1]-y*2);
		if(res1<res2) printf("%d %d\n",a[n-1],x); else printf("%d %d\n",a[n-1],y);
	}
	return 0;
}