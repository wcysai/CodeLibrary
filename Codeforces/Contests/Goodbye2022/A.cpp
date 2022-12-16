#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        multiset<int> ms;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            ms.insert(a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            ms.erase(ms.begin());
            ms.insert(x);
        }
        ll sum=0;
        for(auto x:ms) sum+=x;
        printf("%lld\n",sum);
    }
    return 0;
}

