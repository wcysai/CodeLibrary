#include<bits/stdc++.h>
#define MAXN 64
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
ll pow2[MAXN],pow4[MAXN];
ll n;
int app(int x,ll a)
{
    if(a<pow2[x]) return 0;
    ll p=a-pow2[x];
    return ((p/pow2[x-1]+1)/2+1)%MOD;
}
int main()
{
    pow2[0]=pow4[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        pow2[i]=(pow2[i-1]*2);
        pow4[i]=(pow4[i-1]*4)%MOD;
    }
    while(scanf("%llu",&n)==1)
    {
        n--;
        ll ans=1,pow=1;
        while(n>=pow2[pow])
        {
            ans=(ans+(((pow4[pow-1]+1)%MOD)*app(pow,n))%MOD)%MOD;
            pow++;
        }
        printf("%llu\n",ans);
    }
    return 0;
}
