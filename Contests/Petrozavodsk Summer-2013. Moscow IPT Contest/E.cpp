#include <bits/stdc++.h>
#define ll long long
#define int128 long long
using namespace std;

inline ll read()
{
    int ch=getchar(),f=0;
    ll x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f?-x:x;
}
const int kcz=1000000007;
ll n,m,l,r,k;
inline ll power(ll a,ll p)
{
    ll ret=1;
    while(p>0)
    {
        if(p&1)
            ret=ret*a%kcz;
        a=a*a%kcz;
        p>>=1;
    }
    return ret;
}
int main()
{
    int T=read();
    while(T--)
    {
        n=read(),l=read(),r=read(),k=read();
        if(n-l-r+2<0)
        {
            printf("%lld\n",power(2,min(k,min(n-r+1,n-l+1))));
            continue;
        }
        else
        {
            if(k<n-l-r+2)
            {
                printf("%lld\n",(k+1)%kcz);
                continue;
            }
            else
            if(k==n-r-l+2)
            {
                printf("%lld\n",1ll);
                continue;
            }
            else
            if(k>n-r-l+2)
            {
                printf("%lld\n",power(2,min(k-n+r+l-2,min(l-1,r-1))));
                continue;
            }
        }
    }
    return 0;
}
