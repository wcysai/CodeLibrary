#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
P p[MAXN];
int dp[MAXN];
vector<pair<P,int> > v;
bool cmp(P x,P y)
{
    if(x.F==y.F) return x.S>y.S;
    return x.F<y.F;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d",&p[i].F,&p[i].S);
    sort(p,p+m,cmp);
    fill(dp,dp+m+1,INF);
    for(int i=0;i<m;i++) *lower_bound(dp,dp+m+1,p[i].S)=p[i].S;
    printf("%d\n",lower_bound(dp,dp+m+1,INF)-dp);
    return 0;
}