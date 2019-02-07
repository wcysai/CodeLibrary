#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&n);
    ll ans=INF,suma=0,sumb=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        suma+=a[i];sumb+=b[i];
        v.push_back(a[i]);v.push_back(b[i]);
    }
    ans=min(ans,suma);ans=min(ans,sumb);
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n-2;i++) sum+=v[i];
    for(int i=0;i<n;i++)
    {
        int id1=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        int id2=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        if(id1>=n-1&&id2>=n-1) ans=min(ans,sum+a[i]+b[i]);
        else if(id1<n&&id2<n) ans=min(ans,sum+v[n-2]+v[n-1]);
        else if(id1<n-1) ans=min(ans,sum+v[n-2]+b[i]);
        else ans=min(ans,sum+v[n-2]+a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

