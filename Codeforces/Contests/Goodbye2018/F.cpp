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
ll n,k,a[MAXN];
string str;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    cin>>str;
    bool f=false;
    ll walk=0,swim=0,afterwalk=0;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(str[i-1]=='W') f=true; 
        if(!f)
        {
            if(str[i-1]=='L') 
            {
                ans+=a[i];
                if(walk>a[i]) walk-=a[i];
                else
                {
                    ll need=a[i]-walk;
                    ans+=need*5;
                    walk=0;
                }
            }
            else 
            {
                walk+=a[i];
                ans+=a[i]*5;
            }
        }
        else
        {
            if(str[i-1]=='L') 
            {
                ans+=a[i];
                ll res=walk+afterwalk;
                if(res+swim<a[i])
                {
                    ans+=(a[i]-res-swim)*3;
                    swim=walk=afterwalk=0;
                }
                else if(swim>a[i])
                {
                    swim-=a[i];
                }
                else
                {
                    res-=a[i]-swim;swim=0;
                    afterwalk=0; walk=res;
                }
            }
            else if(str[i-1]=='G')
            {
                afterwalk+=a[i];
                ll res=walk+afterwalk;
                afterwalk=min(swim,afterwalk);
                walk=res-afterwalk;
                ans+=a[i]*5;
            }
            else 
            {
                swim+=a[i];
                ans+=a[i]*3;
            }
        }
    }
    if(walk>0) ans-=walk*2;
    if(swim>afterwalk)
    {
        ans-=swim*3+afterwalk*5;
        ans+=(swim+afterwalk)*2;
    }
    else ans-=(swim+afterwalk)*2;
    printf("%lld\n",ans);
    return 0;
}

