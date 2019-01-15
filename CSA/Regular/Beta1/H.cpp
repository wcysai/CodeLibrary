#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],cnt[MAXN],fact[MAXN],ffact[MAXN],invf[MAXN],invff[MAXN],dp[MAXN];
vector<int> v;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int combb(int n,int k)
{
    if(n<=k) return 1;
    return 1LL*ffact[n]*invff[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    ffact[1]=invff[1]=1;
    for(int i=2;i<=100000;i++) ffact[i]=(1LL*i*(i-1)/2)%MOD*ffact[i-1]%MOD;
    invff[100000]=pow_mod(ffact[100000],MOD-2);
    for(int i=99999;i>=2;i--) invff[i]=(1LL*i*(i+1)/2)%MOD*invff[i+1]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1]) {v.push_back(cnt); cnt=1;}
        else cnt++;
    }
    if(cnt) v.push_back(cnt);
    memset(dp,0,sizeof(dp));
    dp[0]=combb(v[0],v[0]-1);
    int sz=(int)v.size(),s=v[0];
    for(int i=1;i<sz;i++)
    {
        for(int j=0;j<v[i];j++)
        {
            add(dp[i],1LL*dp[i-1]*combb(v[i],j)%MOD*comb(s-1+j,j)%MOD*(v[i]-j)%MOD*combb(v[i]-j,v[i]-j-1)%MOD);
        }
        s+=v[i]; 
    }
    printf("%d\n",dp[sz-1]);
    return 0;
}
