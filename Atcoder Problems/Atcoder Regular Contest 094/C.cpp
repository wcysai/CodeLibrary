#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c;
int find_ans(int x,int y)
{
	if(x>=y) return x-y;
	if((y-x)&1) return 2+(y-x)/2;
	return (y-x)/2;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	int lb=min(min(a,b),c);
	int rb=max(max(a,b),c);
	int ans=INF;
	for(int i=lb;i<=rb;i++)
		ans=min(ans,find_ans(a,i)+find_ans(b,i)+find_ans(c,i));
	printf("%d\n",ans);
}