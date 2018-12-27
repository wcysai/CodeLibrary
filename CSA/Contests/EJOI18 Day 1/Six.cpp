/*************************************************************************
    > File Name: Six.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-27 17:54:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
ll mul_mod(ll a,ll i,ll n)
{
    ll s=0;
    while(i)
    {
        if(i&1) s=(s+a)%n;
        a=(a+a)%n;
        i>>=1;
    }
    return s;
}
ll pow_mod(ll a,ll i,ll n)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=mul_mod(s,a,n);
        a=mul_mod(a,a,n);
        i>>=1;
    }
    return s;
}
bool test(ll n,ll a,ll d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    ll t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=mul_mod(t,t,n);
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(ll n)
{
    if(n<2) return false;
    ll a[]={2,3,5,7,11,13,17,19,23,29};
    for(ll i=0;i<=9;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
int prime[MAXN],sz;
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(i*prime[j]>n) break;
            is_prime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll n;
int tot=0;
vector<int> fact;
unordered_map<int,int> dp;
int bit[10][10],cc;
int cnt[1000];
int find_next(int mask,int fmask)
{
    for(int i=0;i<sz;i++)
    {
        if(!(fmask&(1<<i))) continue;
        for(int j=i;j<sz;j++)
        {
            if(!(fmask&(1<<j))) continue;
            if(mask&(1<<bit[i][j])) return -1;
        }
    }
    int nmask=mask;
    for(int i=0;i<sz;i++)
    {
        if(!(fmask&(1<<i))) continue;
        for(int j=i;j<sz;j++)
            if(mask&(1<<j))
                nmask|=(1<<bit[i][j]);
        for(int j=0;j<i;j++)
            if(mask&(1<<j))
                nmask|=(1<<bit[j][i]);
    }
    nmask|=fmask;
    return nmask;
}
//mask: number in base 3
//0: unchosen 1: chosen once 2:chosen twice
int dfs(int mask)
{
    if(dp[mask]) return dp[mask];
    int ans=1;
    for(int fmask=1;fmask<(1<<sz);fmask++)
    {
        int to=find_next(mask,fmask);
        if(to==-1) continue;
        add(ans,1LL*cnt[fmask]*dfs(to)%MOD);
    }
    return dp[mask]=ans;
}
int main()
{
    int p=sieve(100000);
    scanf("%lld",&n);
    for(int i=0;i<p;i++)
    {
        int cnt=0;
        while(n%prime[i]==0) {n=n/prime[i]; cnt++;}
        if(cnt) fact.push_back(cnt);
    }
    if(n>1)
    {
        if(isPrime(n)) fact.push_back(1);
        else 
        {
            int r=(int)sqrt(n);
            bool f=false;
            for(int i=r-10;i<=r+10;i++) 
                if(1LL*r*r==n)
                {
                    f=true;
                    fact.push_back(2);
                    break;
                }
            if(!f) {fact.push_back(1);fact.push_back(1);}
        }
    }
    sz=(int)fact.size();
    for(int i=0;i<(1<<sz);i++)
    {
        cnt[i]=1;
        for(int j=0;j<sz;j++)
            if(i&(1<<j)) cnt[i]*=fact[j];
    }
    int cc=sz;
    for(int i=0;i<sz;i++)
        for(int j=i;j<sz;j++)
            bit[i][j]=cc++;
    printf("%d\n",(dfs(0)-1+MOD)%MOD);
    return 0;
}

