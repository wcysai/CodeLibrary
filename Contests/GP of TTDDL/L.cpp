#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int T,l,r;
ull ans;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        ans=0;
        scanf("%d%d",&l,&r);
        if(r-l<=10)
        {
            for(int i=1;i<=r-l;i++) ans+=(1LL*i*(l+r-i)*(r-l-i+1)/2);
        }
        printf("%llu\n",ans);
    }
}
