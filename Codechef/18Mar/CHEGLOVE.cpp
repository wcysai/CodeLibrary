#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int t,n,l[MAXN],g[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&l[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&g[i]);
		bool f1=true,f2=true;
		for(int i=0;i<n;i++)
			if(l[i]>g[i]) {f1=false; break;}
		for(int i=0;i<n;i++)
			if(l[i]>g[n-1-i]) {f2=false; break;}
		if(f1&&f2) puts("both");
		else if(f1) puts("front");
		else if(f2) puts("back");
		else puts("none");
	}
	return 0;
}