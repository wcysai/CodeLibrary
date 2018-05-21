#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 100005
#define PI 3.1415926535897932384626
using namespace std;
typedef long long ll;
ll a[MAXN];
ll digit[64];
ll n,m,l,r;
ll dis(ll x,ll r)
{
    return (ll)(x/(2*PI*r));
}
int main()
{
    while(scanf("%lld%lld%lld%lld",&n,&m,&l,&r)==4)
    {
        l=dis(l,r);
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]=dis(a[i],r)+1;
            a[i]%=l+1;
        }
        memset(digit,0,sizeof(digit));
        for(ll i=0;i<n;i++)
        {
            ll k=0;
            while(a[i]>0)
            {
                if(a[i]&1) digit[k]++;
                a[i]>>=1;
                k++;
            }
        }
        bool f=true;
        for(ll i=0;i<64;i++)
            if(digit[i]%(m+1)!=0)
            {
                f=false;break;
            }
        if(!f) puts("Alice"); else puts("Bob");
    }
    return 0;
}
