#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int t;
ll lb,rb;
P get_int(int x){
    ll r=rb/x,l=rb/(x+1)+1;
    return P(l,r);
}
ll calc(ll l1,ll r1,ll l2,ll r2){
    ll l3=max(l1,l2),r3=min(r1,r2);
    if(l3>r3) return 0; else return r3-l3+1;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&lb,&rb);
        ll ans=lb-1;
        if(lb<=rb/2) ans+=rb/2-lb+1;
        for(ll i=1,r;i<=lb-1;i=r+1)
	    {
            ll x=(lb-1)/i;
		    r=(lb-1)/((lb-1)/i);//[i,r]
            P p=get_int(x); ans-=calc(i,r,p.F,p.S);
            p=get_int(x+1); ans-=calc(i,r,p.F,p.S);
	    }
        printf("%lld\n",ans);
    }
    return 0;
}

