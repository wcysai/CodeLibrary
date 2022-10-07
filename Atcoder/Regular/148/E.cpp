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
int n,k,a[MAXN];
int fact[MAXN],invf[MAXN];
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
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int num=n+3-(lower_bound(a+1,a+n+1,k-a[i])-a)-i;
        if(2*a[i]>=k) num--;
        ans=1LL*ans*num%MOD;
    }
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            ans=1LL*ans*invf[cnt]%MOD;
            cnt=1;
        }
    }
    ans=1LL*ans*invf[cnt]%MOD;
    printf("%d\n",ans);
    return 0;
}

