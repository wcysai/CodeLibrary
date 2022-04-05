#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int k,n;
vector<int> v;
int dp[MAXN][MAXN],ndp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	cin>>str;
	n=(int)str.size();
	scanf("%d",&k);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			v.push_back(cnt);
			cnt=0;
		}
		else cnt++;
	}
	v.push_back(cnt);
	if(v.size()==1||v.size()==n+1) {puts("1"); return 0;}
	reverse(v.begin(),v.end());
	dp[0][0]=1;
	for(int i=0;i<(int)v.size();i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<=300;j++)
		{
			for(int used=0;used<=300;used++)
			{
				if(!dp[j][used]) continue;
				//add to
				for(int num=0;num<=j;num++) add(ndp[j-num][used],dp[j][used]);
				for(int num=1;num<=v[i]&&j+num<=300&&used+num<=300;num++) add(ndp[j+num][used+num],dp[j][used]);
			}
		}
		swap(dp,ndp);
	}
	int ans=0;
	for(int i=0;i<=min(300,k);i++) add(ans,dp[0][i]);
	printf("%d\n",ans);
	return 0;
}