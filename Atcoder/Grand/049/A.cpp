#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d[MAXN][MAXN];
string str;
void floyd_warshall()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int j=0;j<n;j++) d[i][j]=(str[j]=='1'?1:INF);
	}
	floyd_warshall();
	double ans=0.0;
	for(int i=0;i<n;i++)
	{
		int reach=1;
		for(int j=0;j<n;j++) if(i!=j&&d[j][i]!=INF) reach++;
		ans+=1.0/reach;
	}
	printf("%.10f\n",ans);
	return 0;
}