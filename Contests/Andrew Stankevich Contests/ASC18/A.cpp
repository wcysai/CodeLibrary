#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,string> P;
ll n,d;
P a[MAXN];
ll need[MAXN];
ll dp[MAXM];
int main()
{
    freopen("addict.in","r",stdin);
    freopen("addict.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].S;
        scanf("%lld",&a[i].F);
    }
    sort(a,a+n);
    ll cnt=0;
    for(ll i=0;i<=10000;i++) dp[i]=INF;
    dp[0]=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll cur=INF;
        for(ll j=a[i].F;j>=max(0LL,a[i].F-d);j--) cur=min(cur,dp[j]);
        if(cur==INF) break;
        need[i]=cur+1;
        cnt++;
        ans+=cur+1;
        for(ll j=10000;j>=0;j--) if(j>=a[i].F) dp[j]=min(dp[j],dp[j-a[i].F]+need[i]);
    }
    printf("%lld %lld\n",cnt,ans);
    vector<string> v;
    for(ll i=0;i<cnt;i++) v.push_back(a[i].S);
    sort(v.begin(),v.end());
    for(auto str:v) cout<<str<<endl;
    return 0;
}
