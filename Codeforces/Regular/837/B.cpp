#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
int fst[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) fst[i]=n+1;
        set<P> s;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            fst[x]=min(fst[x],y);
        }
        ll ans=0;
        int r=n+1;
        for(int i=n;i>=1;i--)
        {
            r=min(r,fst[i]);
            ans+=(r-i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

