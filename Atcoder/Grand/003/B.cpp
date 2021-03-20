#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=0,s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) s=0;
        else
        {
            s+=a[i];
            ans+=s/2;
            s=s&1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
