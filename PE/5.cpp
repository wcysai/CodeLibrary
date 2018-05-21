#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    ll ans=1;
    for(int i=2;i<=20;i++)
        ans=ans*i/gcd(ans,i);
    printf("%I64d\n",ans);
    return 0;
}
