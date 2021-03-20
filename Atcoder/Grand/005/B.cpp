#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h[MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
void solve()
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    solve();
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=1LL*(i-L[i])*(R[i]-i)*h[i];
    printf("%lld\n",ans);
}