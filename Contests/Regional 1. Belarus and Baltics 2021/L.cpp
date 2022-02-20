#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
ll sum[MAXN];
int main()
{
    for(int i=1;i<=1000000;i++) sum[i]=sum[i-1]+1LL*i*i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int x=(int)sqrt(n);
        while(1LL*(x+1)*(x+1)<=n) x++;
        while(1LL*x*x>n) x--;
        printf("%lld\n",1LL*x*(n+1)-sum[x]);
    }
    return 0;
}