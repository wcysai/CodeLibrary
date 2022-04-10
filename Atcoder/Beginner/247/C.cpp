#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void solve(int n)
{
	if(n==0) return;
	solve(n-1);
	printf("%d ",n);
	solve(n-1);
}
int n;
int main()
{
	scanf("%d",&n);
	solve(n);
	return 0;
}