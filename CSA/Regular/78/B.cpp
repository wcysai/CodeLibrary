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
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans1=-INF,ans2=-INF;
	for(int i=2;i<=n-2;i++)
	{
		int len=a[i]-a[i-1];
		if(len>ans1) {ans2=ans1; ans1=len;}
		else if(len>ans2) {ans2=len;}
	}
	int res1=a[1]-a[0],res2=a[n-1]-a[n-2];
	if(res1<res2) swap(res1,res2);
	if(n==3) printf("%d\n",(res2+1)/2);
	else printf("%d\n",max(ans2,max((ans1+1)/2,res2)));
	return 0;
}