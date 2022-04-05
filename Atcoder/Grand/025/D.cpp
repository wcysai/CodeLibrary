#include<bits/stdc++.h>
#define MAXN 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d1,d2;
bool good[MAXN][MAXN];
void reduce(int x,int xmod,int ymod,int d)
{
	if(d%4==0)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				reduce(x*2,xmod+i*x,ymod+j*x,d/4);
		return;
	}
	if(d%4==1)
	{
		for(int i=0;i*x+xmod<2*n;i++)
			for(int j=0;j*x+ymod<2*n;j++)
				if((i+j)&1) good[i*x+xmod][j*x+ymod]=false;
		return;
	}
	if(d%4==2)
	{
		for(int i=0;i*x+xmod<2*n;i++)
			for(int j=0;j*x+ymod<2*n;j++)
				if(i&1) good[i*x+xmod][j*x+ymod]=false;
		return;
	}
	if(d%4==3) return;
}
int main()
{
	scanf("%d%d%d",&n,&d1,&d2);
	for(int i=0;i<2*n;i++)
		for(int j=0;j<=2*n;j++)
			good[i][j]=true;
	reduce(1,0,0,d1); reduce(1,0,0,d2);
	int cnt=0;
	for(int i=0;i<2*n;i++)
		for(int j=0;j<2*n;j++)
			if(cnt<n*n&&good[i][j]) {cnt++;  printf("%d %d\n",i,j);}
	return 0;
}