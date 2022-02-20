#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,d,e,f;
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(1LL*a*c*e!=1LL*b*d*f)
    {
        puts("-1");
        return 0;
    }
    int g=__gcd(a,b);
    a/=g; b/=g;
    g=__gcd(e,f);
    e/=g; f/=g;
    swap(a,b);
    int x=1LL*b*f/__gcd(b,f);
    a=a*(x/b); e=e*(x/f);
    //a,e,x
    if(a+e<=x||a+x<=e||e+x<=a) puts("-1");
    else puts("1");
    return 0;
}