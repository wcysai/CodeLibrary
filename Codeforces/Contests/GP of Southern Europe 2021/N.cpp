#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d%d",&a[i],&b[i]);
    ll ans=0;
    for(int i=1;i<=2*n;i++) 
    {
        ans+=max(a[i],b[i]);
        v.push_back(a[i]+b[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) ans-=v[i];
    printf("%lld\n",ans);
    return 0;
}