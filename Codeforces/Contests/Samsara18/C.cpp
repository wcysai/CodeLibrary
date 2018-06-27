#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN];
vector<int> ans;
bool cmp(P x,P y)
{
	if(x.S==y.S) return x.F>y.F;
	return x.S<y.S;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].F,&a[i].S);
	sort(a,a+n,cmp);
	int last=a[0].S;
	ans.push_back(a[0].S);
	for(int i=1;i<n;i++)
	{
		if(a[i].F<=last) continue;
		else
		{
			ans.push_back(a[i].S);
			last=a[i].S;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}