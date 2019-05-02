#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot;
ll fib[100];
int main()
{
    freopen("choco.in","r",stdin);
    freopen("choco.out","w",stdout);
    scanf("%d%d",&n,&m);
    fib[1]=fib[2]=1;
    for(int i=3;;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>INF)
        {
            tot=i;
            break;
        }
    }
    ll ans=0;
    for(int i=1;i<=tot;i++)
        if(n%fib[i]==0||m%fib[i]==0) ans=max(ans,1LL*n*m-1LL*n*m/fib[i]);
    printf("%lld\n",ans);
}
