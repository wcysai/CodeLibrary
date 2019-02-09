#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll K,A,B,ans;
int main()
{
    ans=1;
    scanf("%lld%lld%lld",&K,&A,&B);
    if(B-A<=2) ans=K+1;
    else
    {
        if(K>=A-1)
        {
            ans=A;K-=(A-1);
            ll moves=K/2;
            ans+=(B-A)*moves;
            if(K&1) ans++;
        }
        else
        {
            ans=K+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

