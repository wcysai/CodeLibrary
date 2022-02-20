#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll m;
int main()
{
    scanf("%d%lld",&n,&m);
    if(n>=43) printf("%lld\n",m);
    else
    {
        ll g=1;
        for(int i=1;i<=n;i++)
        {
            ll gcd=__gcd(1LL*i,g);
            g=g/gcd*i;
        }
        printf("%lld\n",min(m,g));
    }
    return 0;
}