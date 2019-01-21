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
ll t,a,b,k;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        if(a<b) swap(a,b);
        ll ans=0;
        if(a>=99&&b>=99)
        {
            if(k==1) {puts("0"); continue;}
            ans=min(a-99,b-99);
            a-=ans;b-=ans;
        }
        bool f=false;
        while(a>0&&b>0)
        {
            if(b*k==min(99LL,a)) {printf("%lld\n",ans); f=true; break;}
            a--;b--;ans++;
        }
        if(!f) puts("-1");
    }
    return 0;
}

