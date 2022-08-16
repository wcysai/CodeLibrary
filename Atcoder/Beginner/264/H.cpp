#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN][20],sum[MAXN][20];
int fa[MAXN];
int cur;
void change(int v,int pos,int newval)
{
    if(v!=1)
    {
        int lastdp=dp[fa[v]][pos+1];
        dec(sum[fa[v]][pos],dp[v][pos]);
        dec(lastdp,1LL*sum[fa[v]][pos]*dp[v][pos]%MOD);
        add(lastdp,1LL*sum[fa[v]][pos]*newval%MOD);
        add(sum[fa[v]][pos],newval);
        if(lastdp!=dp[fa[v]][pos+1]) change(fa[v],pos+1,lastdp);
    }
    dp[v][pos]=newval;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) scanf("%d",&fa[i]);
    dp[1][0]=1;
    printf("%d\n",1);
    for(int i=2;i<=n;i++) 
    {
        cur=i;
        change(i,0,1);
        int s=0;
        for(int i=0;i<20;i++) add(s,dp[1][i]);
        printf("%d\n",s);
    }
    return 0;
}

