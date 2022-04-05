#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,ans;
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int p[MAXN];
void solve(string s)
{
	int sz=(int)s.size();
	for(int i=1;i<=sz;i++)
		add(ans,1LL*p[sz-i]*(s[i-1]-'A')%MOD);
}
int main()
{
	p[0]=1;
	for(int i=1;i<=1000000;i++) p[i]=26LL*p[i-1]%MOD;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cin>>str;
		ans=0;
		string t=str.substr(0,(n+1)/2);
		if(n&1)
		{
			string tt=t;
			tt.pop_back();
			reverse(tt.begin(),tt.end());
			if(t+tt<=str) add(ans,1);
		}
		else 
		{
			string tt=t;
			reverse(tt.begin(),tt.end());
			if(t+tt<=str) add(ans,1);
		}
		solve(t);
		printf("%d\n",ans);
	}
	return 0;
}