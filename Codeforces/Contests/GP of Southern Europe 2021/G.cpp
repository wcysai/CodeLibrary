#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
	cerr << " " << H;
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
	#define debug(...) 42
#endif
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN],rk[MAXN],dp[MAXN];
//dp[i]= max dp[j]+1 | j<i and a[j]<a[i] (rk[i]-rk[j]>=i-j-1) -> rk[i]-i+1>=rk[j]-j
int bit[2*MAXN];
int sum(int i)
{
    int s=-1;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n+m+5)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    sort(b+1,b+m+1);
    b[m+1]=INF+1;
    for(int i=1;i<=n;i++) rk[i]=lower_bound(b+1,b+m+2,a[i])-b;
    a[n+1]=INF+1;
    rk[n+1]=m+1;
    memset(bit,-1,sizeof(bit));
    add(n+2,0);
    for(int i=1;i<=n+1;i++)
    {
        dp[i]=sum(rk[i]-i+1+(n+1))+1;
        if(a[i-1]<a[i]&&dp[i-1]) dp[i]=max(dp[i],dp[i-1]+1);
        //debug(i,rk[i],dp[i]);
        if(i!=1&&dp[i-1]) add(rk[i-1]-(i-1)+n+1,dp[i-1]);
    }
    if(!dp[n+1]) puts("-1"); else printf("%d\n",n+1-dp[n+1]);
    return 0;
}