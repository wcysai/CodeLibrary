#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef pair<int,int> P;
int n,k;
set<P> s;
int main()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		s.insert(P(x,y));
	}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(s.count(P(x,y))>0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}