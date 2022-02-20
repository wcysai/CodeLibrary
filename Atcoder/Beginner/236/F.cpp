#include<bits/stdc++.h>
#define MAXN 17
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[(1<<16)];
bool has[(1<<16)];
int main()
{
    scanf("%d",&n);
    has[0]=true;
    for(int i=1;i<(1<<n);i++) scanf("%d",&c[i]);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        P p=P(INF+1,0);
        for(int j=1;j<(1<<n);j++)
            if(!has[j]) p=min(p,P(c[j],j));
        ans+=p.F;
        for(int j=0;j<(1<<n);j++)
            if(has[j]) has[j^(p.S)]=true;
    }
    printf("%lld\n",ans);
    return 0;
}