#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int v,a,b,c;
int main()
{
	scanf("%d%d%d%d",&v,&a,&b,&c);
	v%=(a+b+c);
	if(v<a) puts("F");
	else if(v<a+b) puts("M");
	else puts("T");
	return 0;
}