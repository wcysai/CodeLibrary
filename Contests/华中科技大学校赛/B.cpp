#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,ans;
string str;
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&k);
	cin>>str;
	n=str.size();
	int ans=0,mult=1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='5'||str[i]=='0') ans=(ans+mult)%MOD;
		mult=2LL*mult%MOD;
	}
	ans=1LL*ans*(pow_mod(2,1LL*n*k%(MOD-1))-1+MOD)%MOD*pow_mod((pow_mod(2,n)-1+MOD),MOD-2)%MOD;
	printf("%d\n",ans);
}