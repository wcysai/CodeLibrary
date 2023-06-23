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
int n,k,a[MAXN];
vector<ll> v;
ll m,ans,cur;
void solve(ll pos){
    if(pos<0||pos>m) return;
    int sz=(int)v.size();
    ll l,r;
    int id=upper_bound(v.begin(),v.end(),pos)-v.begin()-1;
    if(id+1<k) l=0; else l=(pos+v[id-k+1])/2+1;
    id=lower_bound(v.begin(),v.end(),pos)-v.begin();
    if(sz-id<k) r=m; else r=(pos+v[id+k-1]-1)/2;
    if(r-l+1>ans||((r-l+1==ans)&&pos<cur)){
        ans=r-l+1;
        cur=pos;
    }
}
int main()
{
    scanf("%d%lld%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        ll x; scanf("%lld",&x);
        v.push_back(x);
    }
    ans=-INF;
    cur=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        solve(v[i]-1);  solve(v[i]+1);
        solve(v[i]-2);  solve(v[i]+2);
    }
    solve(0); solve(m);
    printf("%lld %lld\n",ans,cur);
    return 0;
}

