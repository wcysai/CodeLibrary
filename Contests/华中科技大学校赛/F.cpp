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
vector<int> G[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(k==0)
	{
		for(int i=0;i<n;i++) G[0].push_back(a[i]);
		sort(G[0].begin(),G[0].end());
		for(int i=0;i<n;i++) if(a[i]!=G[0][i]) {printf("%d\n",i+1); return 0;}
		puts("-1");
		return 0;
	}
	for(int i=0;i<k;i++)
		for(int j=i;j<n;j+=k)
			G[i].push_back(a[j]);
	sort(a,a+n);
	for(int i=0;i<k;i++) sort(G[i].begin(),G[i].end());
	for(int i=0;i<n;i++)
		if(a[i]!=G[i%k][i/k]) {printf("%d\n",i+1); return 0;}
	puts("-1");
	return 0;
}