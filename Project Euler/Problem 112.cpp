#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool is_bouncy(int x)
{
	if(x<10) return true;
	int now=x%10;
	x=x/10;
	bool f1=true,f2=true;
	while(x)
	{
		int nxt=x%10;
		if(nxt>now) f1=false;
		if(nxt<now) f2=false;
		now=nxt;
		x=x/10;
	}
	return f1||f2;
}
int main()
{
	int bn=0,nbn=0;
	for(int i=1;;i++)
	{
		if(is_bouncy(i)) bn++; else nbn++;
		if(nbn==99*bn) {printf("%d %d %d\n",i,bn,nbn); return 0;}
	}
	return 0;
}