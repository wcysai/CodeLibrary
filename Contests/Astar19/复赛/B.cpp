#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
ll a,b,c,d;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a==c&&b==d)
        {
            puts("Yes");
            puts("");
            continue;
        }
        ll d1=b-a,d2=d-c;
        if(d1==0||d2==0||d2%d1) {puts("No"); continue;}
        ll x=d2/d1;
        int digit=63-__builtin_clzll(x);
        if(x<0||__builtin_popcountll(x)!=1) {puts("No"); continue;}
        if((a-c)%d1) {puts("No"); continue;}
        x=(a-c)/(d1);
        if(x<0||x>=(1LL<<digit)) {puts("No"); continue;}
        puts("Yes");
        for(int i=0;i<digit;i++) if(x&(1LL<<i)) printf("B"); else printf("A");
        puts("");
    }
    return 0;
}
