#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int val[MAXN],cnt[MAXN],sum[MAXN];
int last,pre[MAXN][MAXN];
P pos[MAXN];
map<P,int> st;
map<int,int> mp;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int state[MAXN];
map<pair<P,int>,int > dp;
int solve(int now,int filled,int cur)
{
    if(cur>=last||(last-cur+1)*now+filled<=0)
        return pre[n-filled][min(n-filled,now)];
    if(dp.find(make_pair(P(now,filled),cur))!=dp.end()) return dp[make_pair(P(now,filled),cur)];
    int res=0;
    if(now==0)
    {
        if(filled==n) return 1;
        else return 0;
    }
    add(res,solve(now-1,filled,cur));
    if(sum[cur+1]>=filled+now) add(res,solve(now,filled+now,cur+1));
    return dp[make_pair(P(now,filled),cur)]=res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    pre[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        pre[i][1]=1;
        for(int j=2;j<=n;j++)
        {
            pre[i][j]=pre[i][j-1];
            if(j<=i) add(pre[i][j],pre[i-j][j]);
        }
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    last=0;
    for(auto p:mp)
    {
        last=max(last,p.S);
        for(int j=1;j<=p.S;j++) 
            val[j]++;
    }
    for(int i=1;i<=n+1;i++) sum[i]=sum[i-1]+val[i];
    assert(sum[last]==n);
    printf("%d\n",solve(n,0,0));
    return 0;
}

