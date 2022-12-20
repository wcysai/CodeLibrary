#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
P p[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&p[i].F);
        for(int i=1;i<=n;i++) scanf("%d",&p[i].S);
        p[n+1]=P(INF,INF);
        sort(p+1,p+n+1);
        for(int i=n-1;i>=1;i--) p[i].S=min(p[i+1].S,p[i].S);
        while(k>0)
        {
            sum+=k;
            int alive=lower_bound(p+1,p+n+2,P(sum+1,0))-p;
            if(alive==n+1) break;
            k-=p[alive].S;
        }
        if(k>0) puts("YES"); else puts("NO");
    }
    return 0;
}

