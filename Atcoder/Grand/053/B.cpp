#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,v[MAXN];
multiset<int> ms;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&v[i]);
    int l=n,r=n+1;
    for(int i=1;i<=n;i++)
    {
        ms.insert(v[l]);
        ms.insert(v[r]);
        ms.erase(ms.begin());
        l--; r++;
    }
    ll ans=0;
    for(auto x:ms) ans+=x;
    printf("%lld\n",ans);
    return 0;
}