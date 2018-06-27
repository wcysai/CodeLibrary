#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    scanf("%I64d %I64d",&n,&k);
    ll cnt1=0,cnt2=0,cnt3=0;
    ll t=n;
    while(n%10==0)
    {
        n/=10;
        cnt1++;
    }
    n=t;
    if(cnt1>=k)
    {
        printf("%I64d\n",n);
        return 0;
    }
    k-=cnt1;
    ll x=1,y=1;
    while(n%5==0)
    {
        n/=5;
        x*=5;
        cnt2++;
        if(cnt2==k) break;
    }
    n=t;
    while(n%2==0)
    {
        n/=2;
        y*=2;
        cnt3++;
        if(cnt3==k) break;
    }
    n=t;
    for(int i=1;i<=k;i++)
        n*=10;
    printf("%I64d\n",(n/x)/y);
    return 0;
}
