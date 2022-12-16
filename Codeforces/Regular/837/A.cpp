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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(a[1]==a[n])
        {
            printf("%lld\n",1LL*n*(n-1));
            continue;
        }
        int c1=1,c2=1;
        for(int i=2;i<=n;i++) if(a[i]==a[1]) c1++;
        for(int i=1;i<=n-1;i++) if(a[i]==a[n]) c2++;
        printf("%lld\n",2LL*c1*c2);
    }
    return 0;
}

