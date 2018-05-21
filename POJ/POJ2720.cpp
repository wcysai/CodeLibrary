#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll i,ll mod)
{
    if(i==0) return 1;
     ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%mod;
         a=(a*a)%mod;
         i>>=1;
     }
     return s;
}
int main()
{
    ll b,i,n;
    while(scanf("%lld",&b)==1)
    {
        if(b==0) break;
        scanf("%lld%lld",&i,&n);
        ll s=1,MOD=1;
        for(int j=0;j<n;j++)
            MOD*=10;
        for(int j=0;j<i;j++)
            s=pow_mod(b,s,(MOD));
        int cnt=0;
        ll t=s;
        while(t>0)
        {
            cnt++;
            t/=10;
        }
        for(int j=0;j<n-cnt;j++)
            printf("0");
        printf("%lld\n",s);
    }
    return 0;
}
