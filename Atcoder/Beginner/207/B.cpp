#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,d;
//a<=k(cd-b)
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(1LL*c*d<=b) puts("-1");
    else 
    {
        ll x=1LL*c*d-b;
        printf("%lld\n",(a-1)/x+1);
    }
    return 0;
}