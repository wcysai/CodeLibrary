#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,L[MAXN],R[MAXN];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&L[i]);
		for(int i=1;i<=N;i++) scanf("%d",&R[i]);
		ll ans=0;
		for(int i=1;i<=N-1;i++) ans+=min(R[i],L[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}