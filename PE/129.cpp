#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN];
int main()
{
	for(int i=1000001;;i+=2)
	{
		if(i%5==0) continue;
		int cnt=0,t=1;
		while(t!=0)
		{
			t=t*10+1;
			cnt++;
			t=t%i;
		}
		if(cnt>=1000000)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}