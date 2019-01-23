#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll t,x,y;
P a[9];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        for(ll i=0;i<9;i++)
        {
            ll l=x,r=y;
            while(((l%9)+9)%9!=i) l++;
            while(((r%9)+9)%9!=i) r--;
            a[i].F=(r-l)/9+1;
            a[i].S=(i==0?9:i);
        }
        sort(a,a+9,greater<P>());
        vector<ll> ans;ans.clear();
        for(ll i=0;i<9;i++) if(a[i].F==a[0].F) ans.push_back(a[i].S);
        sort(ans.begin(),ans.end());
        printf("%lld\n",(int)ans.size());
        for(auto v:ans) printf("%lld ",v);
        puts("");
    }
    return 0;
}

