#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
P a[MAXN];
set<P> s;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d%d",&a[i].F,&a[i].S);
        s.clear();
        for(int i=1;i<=N;i++)
            for(int j=i+1;j<=N;j++)
            {
                if((a[i].F<=a[j].F&&a[i].S<=a[j].S)||(a[i].F>=a[j].F&&a[i].S>=a[j].S)) continue;
                int p=abs(a[i].F-a[j].F),q=abs(a[i].S-a[j].S);
                int g=__gcd(p,q);
                p/=g; q/=g;
                s.insert(P(p,q));
            }
        printf("Case #%d: %d\n",t,(int)s.size()+1);
    }
    return 0;
}
