#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll ans[MAXN];
vector<P> v;
ll k;
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(P(a[i],i));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) ans[i]+=k/n;
    for(int i=0;i<k%n;i++) ans[v[i].S]++;
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}