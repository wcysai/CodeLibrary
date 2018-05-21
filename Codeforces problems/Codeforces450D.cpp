#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll x,y;
ll dp[300];
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%I64d%I64d",&x,&y);
    if(y%x!=0)
    {
        printf("-1\n");
        return 0;
    }
    y=y/x;
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(ll i=3;i<=100;i++)
    {
        for(ll k=1;k<=i;k++)
        {
            for(ll p=1;p<=i-k;p++)
            {
                if(gcd(p,k)==1&&((i-k)%p==0))
                    dp[i]+=dp[(i-k)/p];
            }
        }
    }
    for(ll i=0;i<=100;i++)
        printf("%lld\n",dp[i]);
    return 0;
}
