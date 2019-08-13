#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 8
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char ch[60][60],trans[60][60];
void transpose()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			trans[j][i]=ch[i][j];
	swap(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ch[i][j]=trans[i][j];
}
P p[30];
int a[30],b[30],tmp[30];
int res[30][30];
int pre[30][30];//pre[i][j]: [0,i] items, choose j pairs
int suf[30][30];//suf[i][j]: [i,27] items, choose j pairs
bool dp[57][8][(1<<7)][30];
int main()
{
	int tot=0;
	for(int i=6;i>=0;i--)
		for(int j=i;j>=0;j--)
		{
			p[tot]=P(i,j);
			tmp[tot]=a[tot]=i+j; b[tot]=i;
			tot++;
		}
	for(int i=27;i>=0;i--)
	{
		sort(tmp+i,tmp+28,greater<int>());
		for(int j=1;i+j-1<28;j++)
			suf[i][j]=suf[i][j-1]+tmp[i+j-1];
	}
	for(int i=0;i<28;i++)
	{
		vector<int> v; v.clear();
		int res=0;
		for(int j=0;j<=i;j++) 
		{
			res+=b[j];
			v.push_back(a[j]-b[j]);
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int j=0;j<=i+1;j++) //j pairs, i-j singles
		{
			pre[i][j]=res;
			if(j<=i) res+=v[j];
		}
	}
	for(int i=0;i<=28;i++)
		for(int j=0;i+j<=28;j++) //i pairs,j singles
		{
			res[i][j]=-INF;
			if(!j) {res[i][j]=suf[0][i]; continue;}
			for(int k=j-1;k+1<=i+j;k++) res[i][j]=max(res[i][j],pre[k][k+1-j]+suf[k+1][i+j-(k+1)]);
		}
	int kase=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n&&!m) break;
		kase++;
		int cnt=0;
		for(int i=0;i<n;i++) 
		{
			scanf("%s",ch[i]);
			for(int j=0;j<m;j++) if(ch[i][j]=='G') cnt++;
		}
		if(n<m) transpose();
		memset(dp,false,sizeof(dp));
		dp[0][0][0][0]=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int mask=0;mask<(1<<m);mask++)
				{
					int cur=(i*m+j)/2+4;
					for(int pair=0;pair<=cur;pair++)
					{
						if(!dp[i][j][mask][pair]) continue;
						if(mask&(1<<j))
						{
							dp[i][j+1][mask^(1<<j)][pair]=true;
							continue;
						}
						if(ch[i][j]=='B') 
						{
							dp[i][j+1][mask][pair]=true;
							continue;
						}
						else
						{
							if(j+1<m&&ch[i][j+1]!='B'&&(!(mask&(1<<(j+1)))))
							{
								if(ch[i][j]=='G'&&ch[i][j+1]=='G') dp[i][j+2][mask][pair+1]=true;
								else dp[i][j+2][mask][pair]=true;
							}
						}
						if(i+1<n&&ch[i+1][j]!='B')
						{
							if(ch[i][j]=='G'&&ch[i+1][j]=='G') dp[i][j+1][mask^(1<<j)][pair+1]=true;
							else dp[i][j+1][mask^(1<<j)][pair]=true;
						}
					}
				}
			}
			for(int mask=0;mask<(1<<m);mask++)
				for(int pair=0;pair<=28;pair++)
					dp[i+1][0][mask][pair]=dp[i][m][mask][pair];
		}
		int ans=-1;
		for(int pair=0;pair<=28;pair++)
			if(dp[n][0][0][pair]) ans=max(ans,res[pair][cnt-2*pair]);
		printf("Case %d: ",kase);
		if(ans==-1) puts("No solution");
		else printf("%d\n",ans);
	}
	return 0;
}
