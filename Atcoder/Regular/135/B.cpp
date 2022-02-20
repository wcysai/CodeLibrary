#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll s[MAXN],a[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(int i=3;i<=n+2;i++) a[i]=s[i-2]-a[i-1]-a[i-2];
	ll mini[3]={INF,INF,INF};
	for(int i=1;i<=n+2;i++)
	{
		mini[i%3]=min(mini[i%3],a[i]);
	}
	if(mini[0]+mini[1]+mini[2]<0) {puts("No"); return 0;}
	puts("Yes");
	while(mini[0]<0||mini[1]<0||mini[2]<0)
	{
		int id=-1; 
		for(int i=0;i<3;i++) if(mini[i]<0) {id=i; break;}
		int id2=-1;
		for(int i=0;i<3;i++) if(mini[i]>=-mini[id]) {id2=i; break;}
		ll val=-mini[id];
		for(int i=1;i<=n+2;i++) if(i%3==id) a[i]+=val; else if(i%3==id2) a[i]-=val;
		mini[id]+=val; mini[id2]-=val;
	} 
	for(int i=1;i<=n+2;i++) printf("%lld ",a[i]);
	puts("");
	return 0;
}