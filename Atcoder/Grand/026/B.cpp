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
int T;
ll A,B,C,D;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
        if(A<B||D<B) puts("No");
        else if(C>=B) puts("Yes");
        else
        {
            A=A%B;
            ll g=__gcd(D,B);
            A=A%g;
            ll need=(C-A)/g;
            A+=need*g;
            if(A<=C) A+=g;
            if(A>=B) puts("Yes"); else puts("No");
        }
    }
    return 0;
}

