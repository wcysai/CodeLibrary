#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y;
int main()
{
	scanf("%d%d",&x,&y);
	printf("%d %d\n",(12-x)%12,(60-y)%60);
	return 0;
}