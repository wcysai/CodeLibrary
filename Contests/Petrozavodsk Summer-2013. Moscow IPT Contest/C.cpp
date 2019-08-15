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
int n;
int128 gcd(int128 x,int128 y)
{
    return y?gcd(y,x%y):x;
}
inline void print(int128 x)
{
    if(x>=1000000000000000000ll)
    {
        printf("%lld",x/1000000000000000000ll);x%=1000000000000000000ll;
        for(ll i=100000000000000000ll;i>=1;i/=10)
            printf("%lld",x/i),x%=i;
    }
    else
        printf("%lld",x);
}
int main()
{
    int128 P=read(),Q=read(),U=read(),V=read();
    if(Q==0||V==0)
    {
        printf("-1\n");
        return 0;
    }
    int neg=(P*Q<=0)+(V*U<=0);
    if(Q<0)
    Q=-Q,P=-P;
    if(V<0)
        V=-V,U=-U;
    if(neg==2)
    {
        printf("-1\n");
        return 0;
    }
    int128 gg=gcd(Q,P);gg=abs(gg);Q/=gg,P/=gg;gg=gcd(V,U);gg=abs(gg);U/=gg,V/=gg;
    int128 t1=Q*Q-P*P,t2=V*V-U*U;
    if(t1<=0||t2<=0)
    {
        printf("-1\n");
        return 0;
    }
    gg=gcd(t1,t2);
    t1/=gg,t2/=gg;
    ll l=0,r=1000000000ll;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(mid*mid>=t1)
            r=mid;
        else
            l=mid+1;
    }
    ll s2=r;
    l=0,r=1000000000ll;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(mid*mid>=t2)
            r=mid;
        else
            l=mid+1;
    }
    ll s1=r;
    if(s2*s2!=t1||s1*s1!=t2)
    {
        printf("-1\n");
        return 0;
    }
    int128 e1=Q*s1,e2=V*s2,e3=s1*P+s2*U;
    if(e3<=0)
    {
        printf("-1\n");
        return 0;
    }
    gg=gcd(e1,e2);
    gg=gcd(gg,e3);
    e1/=gg,e2/=gg,e3/=gg;
    int128 e[4]={0,e1,e2,e3};
    sort(e+1,e+4);
    print(e[1]),printf(" "),print(e[2]),printf(" "),print(e[3]);printf("\n");
    return 0;
}
