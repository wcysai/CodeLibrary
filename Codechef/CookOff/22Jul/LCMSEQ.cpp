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
int t,n,k,a[MAXN];
int fact[MAXN],invf[MAXN],cnt[MAXN];
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
map<int,int> mp;
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            mp[a[i]]++; 
        }
        int ans=0;
        for(auto p:mp)
            for(int j=2;j<=p.S;j++) if(p.F%j) add(ans,comb(p.S,j));
        for(auto p:mp)
            for(int j=1;j*j<=p.F;j++)
            {
                if(p.F%j==0)
                {
                    cnt[j]+=p.S;
                    if(j*j!=p.F&&p.F/j<=n) cnt[p.F/j]+=p.S;
                }
            }
        for(int i=2;i<=n;i++) add(ans,comb(cnt[i],i));
        printf("%d\n",ans);
    }
    return 0;
}

