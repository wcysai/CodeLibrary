#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int t,n,k;
P a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int maxi=0;
        for(int i=1;i<=n;i++) {scanf("%lld",&a[i].F); a[i].S=i;}
        sort(a+1,a+n+1);
        vector<P> ans;
        for(int i=2;i<=n;i++)
        {
            if(a[i].F%a[i-1].F)
            {
                ans.push_back(P(a[i].S,a[i-1].F-(a[i].F%a[i-1].F)));
                a[i].F+=a[i-1].F-(a[i].F%a[i-1].F);
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%lld %d\n",p.F,p.S);
    }
    return 0;
}

