#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x<y) swap(x,y);
            v.push_back(P(x,y));
            ans+=2*x; ans+=2*y;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++)
        {
            ans-=2*min(v[i].F,v[i+1].F);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

