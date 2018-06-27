#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y;
int main()
{
	scanf("%d%d",&x,&y);
	if(x%y!=0||x==y) puts("-1");
	else printf("%d %d\n",x-y,y);
	return 0;
}