#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,q,a[MAXN];
char s[MAXN][MAXN];
P d[MAXN][MAXN];
void floyd_warshall(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],P(d[i][k].F+d[k][j].F,d[i][k].S+d[k][j].S));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) d[i][j]=P(0,0);
            else if(s[i][j]=='Y') d[i][j]=P(1,-a[j]);
            else d[i][j]=P(INF,0);
        }
    }
    floyd_warshall();
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(d[u][v].F>=INF) puts("Impossible");
        else printf("%lld %lld\n",d[u][v].F,-d[u][v].S+a[u]);
    }
    return 0;
}
