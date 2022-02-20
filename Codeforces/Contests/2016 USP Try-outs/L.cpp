#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s,w[MAXN],c[MAXN];
int maxi[MAXN];
vector<ll> solve(int l,int r)
{
    //printf("l=%d r=%d\n",l,r);
    //assert(r-l<=5001);
    if(r<=2000)
    {
        vector<ll> dp(2001);
        for(int i=1;i<=r;i++)
        {
            dp[i]=maxi[i];
            for(int j=1;j<i;j++) dp[i]=max(dp[i],dp[j]+dp[i-j]); 
        }
        vector<ll> ret(r-l+1);
        for(int i=l;i<=r;i++) ret[i-l]=dp[i];
        return ret;
    }
    int nl=max(0,l/2-501),nr=r/2+501;
    vector<ll> tmp=solve(nl,nr);
    vector<ll> dp(2*nr-2*nl+1);
    for(int i=2*nl;i<=2*nr;i++) dp[i-2*nl]=(i>2000?maxi[2000]:maxi[i]);
    for(int i=0;i<(int)tmp.size();i++)
        for(int j=0;j<(int)tmp.size();j++)
            dp[i+j]=max(dp[i+j],tmp[i]+tmp[j]);
    vector<ll> ret(r-l+1);
    for(int i=l;i<=r;i++) ret[i-l]=dp[i-2*nl];
    return ret;
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&w[i],&c[i]);
        maxi[w[i]]=max(maxi[w[i]],c[i]);
    }
    for(int i=1;i<=2000;i++) maxi[i]=max(maxi[i-1],maxi[i]);
    vector<ll> res=solve(s,s);
    printf("%lld\n",res[0]);
    return 0;
}