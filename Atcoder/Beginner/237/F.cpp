#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 12
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,dp[MAXM][MAXM][MAXM],ndp[MAXM][MAXM][MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
pair<P,int> get_state(int a,int b,int c,int v)
{
	int na=min(a,v);
	int nb=b; if(v>a&&v<b) nb=v;
	int nc=c; if(v>b&&v<c) nc=v;
	return make_pair(P(na,nb),nc);  
}
int main()
{
	scanf("%d%d",&n,&m);
	dp[m+1][m+1][m+1]=1;
	for(int i=0;i<n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int a=1;a<=m+1;a++)
			for(int b=a;b<=m+1;b++)
				for(int c=b;c<=m+1;c++)
				{
					if(!dp[a][b][c]) continue;
					for(int v=1;v<=min(m,c);v++)
					{
						auto p=get_state(a,b,c,v);
						add(ndp[p.F.F][p.F.S][p.S],dp[a][b][c]);
					}
				}
		swap(dp,ndp);
	}
	int ans=0;
	for(int a=1;a<=m;a++)
		for(int b=a;b<=m;b++)
			for(int c=b;c<=m;c++)
				add(ans,dp[a][b][c]);
	printf("%d\n",ans);
}