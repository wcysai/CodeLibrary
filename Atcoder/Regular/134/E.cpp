#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][(1<<16)];
bool lose[(1<<16)];
int solve(vector<int> v)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	int sz=(int)v.size();
	for(int i=0;i<n;i++)
	{
		for(int mask=0;mask<(1<<sz);mask++)
		{
			if(!dp[i][mask]) continue;
			for(int j=0;j<sz;j++)
			{
				if(a[i+1]>=v[j]) add(dp[i+1][mask|(1<<j)],dp[i][mask]);
			}
		}
	}
	return dp[n][(1<<sz)-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=1;
	for(int i=1;i<=n;i++) ans=1LL*ans*a[i]%MOD;
	memset(lose,false,sizeof(lose));
	for(int mask=1;mask<(1<<16);mask++)
	{
		int maxi=12*(32-__builtin_clz(mask));
		lose[mask]=true;
		for(int j=2;j<=maxi;j++)
		{
			vector<int> v;
			for(int k=0;k<16;k++)
			{
				if(mask&(1<<k)) 
				{
					int val=((k+1)*12)%j;
					if(val==0) continue;
					v.push_back(val);
					if(val!=1&&val!=2&&val!=4&&val!=8&&val%12) break;
				}
			}
			sort(v.begin(),v.end());
			v.erase(unique(v.begin(),v.end()),v.end());
			bool f=false;
			if(v.size()==0) continue;
			if(v.size()==1&&(v[0]==1||v[0]==2)) f=true;
			if(v.size()==2&&v[0]==4&&v[1]==8) f=true;
			bool flag=true;
			int nmask=0;
			for(auto x:v) if(x%12) {flag=false; break;} else nmask|=(1<<(x/12-1));
			if(flag&&lose[nmask]) f=true;
			if(f) {lose[mask]=false; break;}
		}
	}
	//all 1
	dec(ans,solve(vector<int>{1}));
	dec(ans,solve(vector<int>{2}));
	dec(ans,solve(vector<int>{4,8}));
	for(int mask=1;mask<(1<<16);mask++)
	{
		if(lose[mask])
		{
			vector<int> v;
			for(int i=0;i<16;i++) if(mask&(1<<i)) v.push_back(12*(i+1));
			dec(ans,solve(v));
		}
	}
	printf("%d\n",ans);
	return 0;
}