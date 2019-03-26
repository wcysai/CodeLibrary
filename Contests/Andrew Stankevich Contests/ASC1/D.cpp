#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int cnt[MAXN];
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        cnt[u]++;cnt[v]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=1LL*cnt[i]*cnt[i];
    printf("%lld\n",ans);
    return 0;
}
