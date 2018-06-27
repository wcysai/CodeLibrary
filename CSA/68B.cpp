#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m,k;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int count(int x1,int y1,int x2,int y2)
{
	int dif1=max(x1-x2,x2-x1),dif2=max(y1-y2,y2-y1);
	if(dif1==0) return dif2+1;
	if(dif2==0) return dif1+1;
	return 1+gcd(dif1,dif2);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int i2=0;i2<=n;i2++)
				for(int j2=0;j2<=m;j2++)
					if(count(i,j,i2,j2)==k) cnt++;
	printf("%d\n",cnt/2);
	return 0;
}