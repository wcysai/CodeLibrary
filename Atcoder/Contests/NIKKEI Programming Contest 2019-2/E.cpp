#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
#define exit dskosad
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
ll get_sum(ll l,ll r)
{
    return 1LL*(l+r)*(r-l+1)/2;
}
struct node
{
    int x,y,z;
};
vector<node> ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    if(get_sum(k,k+2*n-1)>get_sum(k+2*n,k+3*n-1)) {puts("-1"); return 0;}
    int x=k,y=2*n,z=k+2*n;
    while(y<=k+2*n-1&&z<=k+3*n-1)
    {
        ans.push_back((node){x,y,z});
        assert(x+y<=z);
        z+=2; x++; y++;
    }
    vector<int> has;
    while(z<=k+3*n-1)
    {
        has.push_back(z);
        z+=2;
    }
    z=k+2*n+1;
    while(z<=k+3*n-1)
    {
        has.push_back(z);
        z+=2;
    }
    sort(has.begin(),has.end());
    y=k+n;
    int now=0;
    while(x<=k+n-1)
    {
        z=has[now];
        ans.push_back((node){x,y,z});
        assert(x+y<=z);
        now++; x++; y++;
    }
    for(auto p:ans) printf("%d %d %d\n",p.x,p.y,p.z);
    return 0;
}
