#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXK 100005
#define MAXM 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,s;
int w[MAXN],c[MAXN];
vector<int> items[MAXM];
ll dp[MAXK],ndp[MAXK],val[MAXK];
void solve(int l,int r,int x,int y,int mod,int num)
{
    if(l>r) return;
    int mid=(l+r)/2;
    P p=P(-INF,0);
    for(int i=x;i<=min(y,mid);i++)
        if(P(val[(mid-i)*num]+dp[i*num+mod],i)>p) p=P(val[(mid-i)*num]+dp[i*num+mod],i);
    ndp[mid*num+mod]=p.F;
    solve(l,mid-1,x,p.S,mod,num); solve(mid+1,r,p.S,y,mod,num);
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&w[i],&c[i]);
        items[w[i]].push_back(c[i]);
    }
    for(int i=1;i<=300;i++) sort(items[i].begin(),items[i].end(),greater<int>());
    for(int i=1;i<=300;i++)
    {
        if(!items[i].size()) continue;
        memset(val,0,sizeof(val));
        memset(ndp,0,sizeof(ndp));
        ll sum=0;
        for(int j=0;i*(j+1)<=s;j++)
        {
            if(j<(int)items[i].size()) sum+=items[i][j];
            val[i*(j+1)]=sum;
        }
        for(int j=0;j<i;j++)
            solve(0,(s-j)/i,0,(s-j)/i,j,i);
        swap(dp,ndp);
    }
    for(int i=1;i<=s;i++) printf("%lld ",dp[i]);
    return 0;
}