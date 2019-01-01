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
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int n,a;
int main()
{
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d %d\n",1,i,1);
        fflush(stdout);
        int now;
        scanf("%d",&now);
        if(now!=a)
        {
            int inc=now-a;if(inc<0) inc+=MOD;
            printf("%d %d %lld\n",1,i,1LL*(MOD-now)*pow_mod(inc,MOD-2)%MOD);
            fflush(stdout);
            scanf("%d",&now);
            assert(now==0);
            return 0;
        }
        else a=now;
    }
    return 0;
}

