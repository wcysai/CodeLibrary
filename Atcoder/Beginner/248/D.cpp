#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
vector<int> pos[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		printf("%d\n",upper_bound(pos[x].begin(),pos[x].end(),r)-lower_bound(pos[x].begin(),pos[x].end(),l));
	}
	return 0;
}