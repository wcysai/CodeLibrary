#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 5000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],q[MAXN];
int posp[MAXN],posq[MAXN];
vector<P> v;
int dp[MAXM];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        posp[p[i]]=i;
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&q[i]);
        posq[q[i]]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            v.push_back(P(posp[i],-posq[j]));
    sort(v.begin(),v.end());
    int sz=(int)v.size();
    fill(dp,dp+sz,INF);
    for(int i=0;i<sz;i++) *lower_bound(dp,dp+sz,-v[i].S)=-v[i].S;
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    return 0;
}