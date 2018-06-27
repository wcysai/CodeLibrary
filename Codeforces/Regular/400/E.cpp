#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k;
ll getphi(ll n) {
    if(n==1) return 1;
    ll ans = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ans -= ans / n;
    }
    return ans;
}
int main()
{
    scanf("%I64d %I64d",&n,&k);
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    ll res=getphi(n);
    printf("%I64d\n",res);
    return 0;
}
