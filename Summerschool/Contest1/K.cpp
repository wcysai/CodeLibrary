#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    int m=0;
    while(scanf("%lld %lld",&n,&k)==2)
    {
        m++;
        printf("Case #%d: ",m);
    if(k<=n) printf("%I64d\n",k);
    else
    {
        ll x=(k-n)/(n-1);
        if(x%2==1)
        {
            ll p=(k-n)%(n-1);
            if(p==0) p=n-1;
            printf("%I64d\n",p);
        }
        else
        {
            ll p=(k-n)%(n-1);
            if(p==0) printf("%I64d\n",n);
            else printf("%I64d\n",p);
        }
    }
    }
    return 0;
}
