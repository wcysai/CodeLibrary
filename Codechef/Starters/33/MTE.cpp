#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,even,odd;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		even=odd=0;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d",&x);
			if(x&1) odd++; else even++;
		}
		int ans;
		if(odd&1) ans=even;
		else ans=min(odd/2,even);
		printf("%d\n",ans);
	}
	return 0;
}