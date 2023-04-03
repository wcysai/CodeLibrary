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
int T,a,b,c,d;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if((a+1)%b==(c+1)%d){
            printf("%d\n",1);
            continue;
        }
        int g=__gcd(b,d);
        printf("%lld\n",1LL*b*d/g-min(b,d)+1);
    }
    return 0;
}

