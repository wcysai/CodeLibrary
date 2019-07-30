#include<bits/stdc++.h>
#define INF 1000000000LL
using namespace std;
typedef long long ll;
ll S;
int main()
{
    scanf("%lld",&S);
    ll need=(S+INF-1)/INF*INF-S;
    printf("0 0 %lld %lld %lld %lld\n",1LL,INF,(S+need)/INF,need);
    return 0;
}
