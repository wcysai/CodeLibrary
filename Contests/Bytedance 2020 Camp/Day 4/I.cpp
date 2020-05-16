#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 100000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,a[MAXN],X;
int pool[MAXM];
int getmu(int n)
{
    int res=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            res=-res;
            for(;n%i==0;n/=i) cnt++;
            if(cnt>1) return 0;
        }
    }
    if(n!=1) res=-res;
    return res;
}
ll solve(int x)
{
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=pool[a[i]%x],pool[a[i]%x]++;
    for(int i=1;i<=n;i++) pool[a[i]%x]--;
    return ans*getmu(x);
}
int main()
{
    while(scanf("%d%d",&n,&X)==2)
    {
        if(!n) break;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ll ans=0;
        for(int i=1;i*i<=X;i++)
        {
            if(X%i) continue;
            ans+=solve(i);
            if(i*i!=X) ans+=solve(X/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}