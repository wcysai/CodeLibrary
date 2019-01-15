#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
int N,Q;
P a[MAXN],q[MAXN];
int sum[MAXN],cnt[MAXN],lpos[MAXN],rpos[MAXN];
ll ans[MAXN],nowsum[MAXN];
ll dp[405][405];
const int blocks=400;
void add(ll &a,ll b) {a+=b;}
bool cmp(P x,P y)
{
    return x.S<y.S;
}
int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++) {scanf("%d",&a[i].F); a[i].S=i;}
    for(int i=0;i<Q;i++) scanf("%d%d",&q[i].F,&q[i].S);
    sort(a+1,a+N+1);
    for(int i=1;i<=(N-1)/blocks+1;i++)
    {
        vector<P> v; v.clear();
        int l=(i-1)*blocks+1,r=min(i*blocks,N);
        memset(nowsum,0,sizeof(nowsum));
        for(int j=l;j<=r;j++) {v.push_back(a[j]); nowsum[a[j].S]+=a[j].F;}
        for(int j=1;j<=N;j++) nowsum[j]+=nowsum[j-1];
        for(int j=0;j<Q;j++)
        {
            int cnt0=sum[q[j].S]-sum[q[j].F-1];
            ll sum1=nowsum[q[j].S]-nowsum[q[j].F-1];
            add(ans[j],2LL*cnt0*sum1);
        }
        sort(v.begin(),v.end(),cmp);
        int sz=(int)v.size();
        memset(dp,0,sizeof(dp));
        for(int j=0;j<sz;j++)
        {
            dp[j][j]=v[j].F;
            int tmp=0;
            ll s=0;
            for(int k=j-1;k>=0;k--)
            {
                if(v[k]<v[j]) tmp++; else s+=2LL*v[k].F;
                dp[k][j]=dp[k][j-1]+(2LL*tmp+1)*v[j].F+s;
            }
        }
        for(int j=1;j<=N+1;j++) lpos[j]=INF;
        for(int j=0;j<sz;j++) lpos[v[j].S]=j;
        for(int j=N;j>=1;j--) lpos[j]=min(lpos[j],lpos[j+1]);
        memset(rpos,-1,sizeof(rpos));
        for(int j=0;j<sz;j++) rpos[v[j].S]=j;
        for(int j=1;j<=N;j++) rpos[j]=max(rpos[j],rpos[j-1]);
        for(int j=0;j<Q;j++)
        {
            int l=q[j].F,r=q[j].S;
            if(lpos[l]==INF||rpos[r]==-1) continue;
            add(ans[j],dp[lpos[l]][rpos[r]]);
        }
        for(auto p:v) cnt[p.S]++;
        for(int j=1;j<=N;j++) sum[j]=sum[j-1]+cnt[j];
    }
    for(int i=0;i<Q;i++) printf("%.10Lf\n",(db)ans[i]/(1LL*(q[i].S-q[i].F+1)*(q[i].S-q[i].F+1)));
    return 0;
}
