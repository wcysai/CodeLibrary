#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
int dp[MAXN][10][10][10][10],ans;
bool passed1(int from,int to,int leave)
{
	return (leave>=from&&leave<=to)||(leave<=from&&leave>=to);
}
bool passed2(int from,int to,int leave,int enter)
{
	if(from<=to)
	{
		return (leave>=from&&leave<=to&&leave<=enter);
	}
	else
	{
		return (leave<=from&&leave>=to&&leave>=enter);
	}
}
int find_ans(int now,int i,int j,int k,int l,int cost)
{
	if(i==0&&j==0&&k==0&&l==0) return cost;
	int res=INF;
	if(i!=0) res=min(res,find_ans(i,0,j,k,l,cost+max(now-i,i-now)));
	if(j!=0) res=min(res,find_ans(j,i,0,k,l,cost+max(now-j,j-now)));
	if(k!=0) res=min(res,find_ans(k,i,j,0,l,cost+max(now-k,k-now)));
	if(l!=0) res=min(res,find_ans(l,i,j,k,0,cost+max(now-l,l-now)));
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++)
						dp[i][j][k][l][m]=INF;
	dp[1][b[1]][0][0][0]=a[1]-1;
	for(int i=1;i<n;i++)
	{
		int last=a[i];
		for(int j=0;j<10;j++)
			for(int k=0;k<=j;k++)
				for(int l=0;l<=k;l++)
					for(int m=0;m<=l;m++)
					{
						int cnt=(j>0?1:0)+(k>0?1:0)+(l>0?1:0)+(m>0?1:0);
						if(dp[i][j][k][l][m]==INF) continue;
						int a1,a2,a3,a4;
						for(int p=1;p<=9;p++)
						{
							if(cnt==4)
							{
								if(!passed2(last,p,j,a[i+1])&&!passed2(last,p,k,a[i+1])&&!passed2(last,p,l,a[i+1])&&!passed2(last,p,m,a[i+1])&&!passed2(p,a[i+1],j,a[i+1])&&!passed2(p,a[i+1],k,a[i+1])&&!passed2(last,a[i+1],l,a[i+1])&&!passed2(last,a[i+1],m,a[i+1]))
									continue;
							}
							a1=(passed1(last,p,j)||passed1(p,a[i+1],j))?0:j;
							a2=(passed1(last,p,k)||passed1(p,a[i+1],k))?0:k;
							a3=(passed1(last,p,l)||passed1(p,a[i+1],l))?0:l;
							a4=(passed1(last,p,m)||passed1(p,a[i+1],m))?0:m;
							int cost=max(p-last,last-p)+max(a[i+1]-p,p-a[i+1]);
							if(a1==0) a1=b[i+1]; else if(a2==0) a2=b[i+1]; else if(a3==0) a3=b[i+1]; else if(a4==0) a4=b[i+1]; else assert(0);
							if(a1==0)
							{
								a1=a2;a2=a3;a3=a4;
							}
							if(a2==0)
							{
								a2=a3;a3=a4;
							}
							if(a3==0) a3=a4;
							dp[i+1][a1][a2][a3][a4]=min(dp[i+1][a1][a2][a3][a4],dp[i][j][k][l][m]+cost);
							//printf("%d %d %d %d %d %d\n",i+1,a1,a2,a3,a4,dp[i+1][a1][a2][a3][a4]);
						}
					}
	}
	ans=INF;
	for(int j=0;j<10;j++)
			for(int k=0;k<=j;k++)
				for(int l=0;l<=k;l++)
					for(int m=0;m<=l;m++)
						ans=min(ans,dp[n][j][k][l][m]+find_ans(a[n],j,k,l,m,0));
	printf("%d\n",ans+2*n);
	return 0;
}