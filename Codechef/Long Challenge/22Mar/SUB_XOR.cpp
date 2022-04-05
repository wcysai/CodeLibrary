#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
string str;
int sum[MAXN];
int p[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	p[0]=1;
	for(int i=1;i<=100000;i++) p[i]=2LL*p[i-1]%MOD;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		cin>>str;
		for(int i=0;i<=N;i++) sum[i]=0;
		for(int i=0;i<N;i+=2)
		{
			if(str[i]=='1')
			{
				sum[0]^=1;
				sum[N-i]^=1;
			}
		}
		int ans=0;
		for(int i=1;i<=N;i++) sum[i]^=sum[i-1];
		for(int i=0;i<=N;i++) if(sum[i]) add(ans,p[i]);
		printf("%d\n",ans);
	}
	return 0;
}