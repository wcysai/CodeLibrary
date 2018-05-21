#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
	scanf("%d",&n);
	int cnt=0;
	while(n>0)
	{
		if(n&1) cnt++;
		n=n/2;
	}
	printf("%d\n",cnt/2);
	return 0;
}