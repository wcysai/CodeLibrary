#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> dis;
P a[MAXN],b[MAXN];
ll sum[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        dis.push_back(a[i].F);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].F,&b[i].S);
        dis.push_back(b[i].F);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++) a[i].F=lower_bound(dis.begin(),dis.end(),a[i].F)-dis.begin()+1;
    for(int i=1;i<=m;i++) b[i].F=lower_bound(dis.begin(),dis.end(),b[i].F)-dis.begin()+1;
    for(int i=1;i<=m;i++) sum[b[i].F]+=b[i].S;
    for(int i=1;i<=200000;i++) sum[i]+=sum[i-1];
    ll sm=0,eq=0,gr=0;
    for(int i=1;i<=n;i++)
    {
        sm+=a[i].S*(sum[200000]-sum[a[i].F]);
        eq+=a[i].S*(sum[a[i].F]-sum[a[i].F-1]);
        gr+=a[i].S*sum[a[i].F-1];
    }
    printf("%lld %lld %lld\n",gr,eq,sm);
    return 0;
}
