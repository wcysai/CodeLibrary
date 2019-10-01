#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(k>n||(k&1))
        {
            puts("renrendoushijwj");
            continue;
        }
        ll ans=1LL*n*(n-1)/2;
        if(n&1) printf("%lld\n",ans-k/2);
        else printf("%lld\n",ans-(n-k)/2);
    }
    return 0;
}


