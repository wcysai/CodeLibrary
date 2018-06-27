#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,m;
int main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        m=n-m+1;
        ll s=1;
        if(n-m>=40)
        {
            s=6;
            n-=((n-m)/40)*40;
        }
        for(ll i=m;i<=n;i++)
        {
            s=s*i;
            while(s%10==0) s=s/10;
            s=s%10;
        }
        printf("%lld\n",s);
    }
    return 0;
}
