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
ll T,n;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",(1LL<<__builtin_popcountll(n-1)));
    }
    return 0;
}

