#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int p2[MAXN],sum[MAXN],fact[MAXN],invf[MAXN];
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
int main()
{
    p2[0]=fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1];
        add(sum[i],a[i]);
    }
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        add(ans,1LL*sum[i]%MOD*comb(n,n-i-1)%MOD*fact[n-i-1]%MOD*fact[i]%MOD);
        int now=sum[n];
        dec(now,sum[n-i]);
        add(ans,1LL*now%MOD*comb(n,n-i-1)%MOD*fact[n-i-1]%MOD*fact[i]%MOD);
    }
    add(ans,1LL*sum[n]*fact[n]%MOD);
    int cur=0,len=n-2;;
    for(int i=1;i<=(len+1)/2;i++)
    {
        int now=sum[n-i];
        dec(now,sum[i]);
        add(cur,now);
        add(ans,2LL*cur%MOD*comb(n,n-i-2)%MOD*fact[n-i-2]%MOD*fact[i]%MOD);
        if(i*2-1!=len) 
        {
            int rest=len+1-i;
            add(ans,2LL*cur%MOD*comb(n,n-rest-2)%MOD*fact[n-rest-2]%MOD*fact[rest]%MOD);
        }
    }
    printf("%d\n",ans);
    return 0;
}

