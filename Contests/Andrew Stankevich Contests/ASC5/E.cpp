#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll k,n;
int sz;
vector<int> v;
ll dp[20][200];
ll getsum1(int l,int sum)
{
    if(sum>9*l||l<0||sum<0) return 0;
    if(dp[l][sum]!=-1) return dp[l][sum];
    if(l==0&&sum==0) return 1;
    dp[l][sum]=0;
    for(int i=0;i<=9;i++)
    {
        if(sum<i) break;
        dp[l][sum]+=getsum1(l-1,sum-i);
    }
    return dp[l][sum];
}
ll getsum2(ll n,int sum)
{
    vector<int> dig;
    while(n)
    {
        dig.push_back(n%10);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
    ll ret=0;
    int sz=(int)dig.size();
    for(int i=0;i<(int)dig.size();i++)
    {
        for(int j=0;j<dig[i];j++) ret+=getsum1(sz-1-i,sum--);
    }
    ret+=getsum1(0,sum);
    return ret;
}
ll getsum3(ll n,ll pre,int sum)
{
    char sn[21]={0},sp[21]={0};
    int ln,lp;
    sprintf(sn,"%lld",n);
    sprintf(sp,"%lld",pre);
    ln=strlen(sn); lp=strlen(sp);
    for(int i=0;i<lp;i++) sum-=sp[i]-'0';
    int i;
    for(i=0;i<lp;i++) if(sn[i]!=sp[i]) break;
    if(i<lp)
    {
        ll res=0;
        if(sn[i]<sp[i]) ln--;
        for(i=ln-lp;i>=0;i--) res+=getsum1(i,sum);
        return res;
    }
    ll t=0,ret=0;
    for(i=lp;i<ln;i++) t=10*t+sn[i]-'0';
    ret=getsum2(t,sum);
    for(i=ln-lp-1;i>=0;i--) ret+=getsum1(i,sum);
    return ret;
}
ll getsum4(ll n,ll k,int sum)
{
    vector<int> dig;
    while(k)
    {
        dig.push_back(k%10);
        k/=10;
    }
    ll pre=1,res=0;
    int t=1,sz=(int)dig.size();
    for(int i=sz-1;i>=0;i--)
    {
        for(int j=t;j<dig[i];j++) res+=getsum3(n,pre++,sum);
        pre=10*pre;
        t=0;
    }
    for(int i=0;i<sz;i++)
    {
        if(dig[i]==0) res++;
        else break;
    }
    return res;
}
ll getsum5(ll n,ll k)
{
    int sum=0;
    ll _k=k;
    while(_k)
    {
        sum+=_k%10;
        _k/=10;
    }
    ll res=0;
    for(int i=1;i<sum;i++) res+=getsum2(n,i);
    res+=getsum4(n,k,sum);
    return res+1;
}
int main()
{
    freopen("grlex.in","r",stdin);
    freopen("grlex.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    scanf("%lld%lld",&n,&k);
    printf("%lld\n",getsum5(n,k));
    int sum=1,presum;
    ll t,pre;
    while((t=getsum2(n,sum))<k)
    {
        sum++;
        k-=t;
    }
    pre=1;presum=1;
    while(true)
    {
        while((t=getsum3(n,pre,sum))<k)
        {
            pre++;
            presum++;
            k-=t;
        }
        if(presum==sum) break;
        else pre*=10;
    }
    while(--k) pre*=10;
    printf("%lld\n",pre);
    return 0;
}
