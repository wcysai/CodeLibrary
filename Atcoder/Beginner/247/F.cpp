#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],q[MAXN],f[MAXN],r[MAXN];
bool vis[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	f[0]=2; f[1]=1;
	for(int i=2;i<=200000;i++) {f[i]=f[i-1]; add(f[i],f[i-2]);}
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=1;i<=n;i++) r[p[i]]=q[i];
	int ans=1;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int cnt=0,now=i;
			while(!vis[now])
			{
				cnt++;
				vis[now]=true;
				now=r[now];
			}
			ans=1LL*ans*f[cnt]%MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}