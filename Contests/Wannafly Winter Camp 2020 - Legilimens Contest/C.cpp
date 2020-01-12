#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
int cnt[65];
int main()
{
    scanf("%d",&n);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s^=a[i];
        for(int j=0;j<=60;j++) if((a[i]>>j)&1) cnt[j]++;
        if(s==0) puts("0");
        else
        {
            int x=63-__builtin_clzll(s);
            printf("%d\n",cnt[x]);
        }
        
    }
    return 0;
}