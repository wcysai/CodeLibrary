#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll get_cost(int x,int y)
{
    return max(a[x]-a[y],a[y]-a[x]);
}
vector<P> v;
int main()
{
    ll delta=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n-1;i++) delta=max(delta,get_cost(i,i+1)-get_cost(1,i+1));
    for(int i=n-1;i>=2;i--) delta=max(delta,get_cost(i,i-1)-get_cost(n,i-1));
    v.clear();
    for(int i=2;i<=n;i++)
        if(a[i-1]<=a[i])
            v.push_back(P(a[i-1],a[i]));
    sort(v.begin(),v.end());
    int curmax=-INF;
    for(auto p:v)
    {
        delta=max(delta,2LL*max(0,min(curmax,p.S)-p.F));
        curmax=max(curmax,p.S);
    }
    v.clear();
    for(int i=2;i<=n;i++)
        if(a[i-1]>=a[i])
            v.push_back(P(a[i],a[i-1]));
    sort(v.begin(),v.end());
    curmax=-INF;
    for(auto p:v)
    {
        delta=max(delta,2LL*max(0,min(curmax,p.S)-p.F));
        curmax=max(curmax,p.S);
    }
    ll ans=0;
    for(int i=2;i<=n;i++) ans+=get_cost(i-1,i);
    printf("%lld\n",ans-delta);
    return 0;
}