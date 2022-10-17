#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        ll ans=INF;
        for(int k=1;k<=100000;k++)
        {
            ll res=b-1LL*k*a;
            if(res<=0) ans=min(ans,-res);
            else
            {
                ll need=(k-(res%k))%k;
                ans=min(ans,(res-1)/k+1+need);
            }
        }
        for(int x=0;x<=100000;x++)
        {
            ll y=(a+x)-b%(a+x);
            if(y==a+x) y=0;
            ans=min(ans,x+y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

