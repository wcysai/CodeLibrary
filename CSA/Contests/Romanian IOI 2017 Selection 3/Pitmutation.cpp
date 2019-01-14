#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s,a[MAXN],b[MAXN];
int fact[MAXN],invf[MAXN],ans1[MAXN],ans2[MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void solve(vector<int> &v)
{
    int sz=(int)v.size();
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            add(dp[i+1][j+1],1LL*dp[i][j]*(v[i]-j)%MOD);
            add(dp[i+1][j],dp[i][j]);
        }
    }
    for(int i=sz;i>=0;i--)
    {
        dp[sz][i]=1LL*dp[sz][i]*fact[sz-i]%MOD;
        for(int j=i+1;j<=sz;j++) dec(dp[sz][i],1LL*dp[sz][j]*comb(j,i)%MOD);
    }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=300;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300]=pow_mod(fact[300],MOD-2);
    for(int i=299;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    set<int> ss;
    for(int i=1;i<=n;i++) ss.insert(i);
    for(int i=1;i<=n;i++) if(a[i]!=0) ss.erase(a[i]);
    vector<int> v;v.clear();
    for(int i=1;i<=n;i++) if(b[i]!=0) v.push_back(b[i]);
    sort(v.begin(),v.end());
    vector<int> vv;vv.clear();
    for(auto x:ss) vv.push_back(upper_bound(v.begin(),v.end(),x-1)-v.begin());
    solve(vv);int sz=(int)vv.size();
    for(int i=0;i<=sz;i++) ans1[i]=dp[sz][i];
    ss.clear();
    for(int i=1;i<=n;i++) ss.insert(i);
    for(int i=1;i<=n;i++) if(b[i]!=0) ss.erase(b[i]);
    v.clear();
    for(int i=1;i<=n;i++) if(a[i]!=0) v.push_back(a[i]);
    sort(v.begin(),v.end());
    vv.clear();
    for(auto x:ss) vv.push_back(upper_bound(v.begin(),v.end(),x)-v.begin());
    solve(vv);sz=(int)vv.size();
    for(int i=0;i<=sz;i++) ans2[i]=dp[sz][sz-i];
    int ans=0;
    for(int i=0;i<=s;i++) add(ans,1LL*ans1[i]*ans2[s-i]%MOD);
    printf("%d\n",ans);
    return 0;
}
