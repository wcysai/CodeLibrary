#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 20005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int a[MAXN],d[MAXN],c[MAXN],q[MAXN];
ll all[MAXN];
ll dp[20][MAXM];
ll nuse[MAXN][MAXM];
void solve(int l,int r,int d)
{
    if(l==r)
    {
        for(int i=0;i<=20000;i++) nuse[l][i]=dp[d][i];
        return;
    }
    int mid=(l+r)/2;
    for(int i=0;i<=20000;i++) dp[d+1][i]=dp[d][i];
    for(int i=mid+1;i<=r;i++)
        for(int j=20000;j>=c[i];j--)
            dp[d+1][j]=min(dp[d+1][j],dp[d+1][j-c[i]]+all[i]);
    solve(l,mid,d+1);
    for(int i=0;i<=20000;i++) dp[d+1][i]=dp[d][i];
    for(int i=l;i<=mid;i++)
        for(int j=20000;j>=c[i];j--)
            dp[d+1][j]=min(dp[d+1][j],dp[d+1][j-c[i]]+all[i]);
    solve(mid+1,r,d+1);
}
struct node
{
    int a,d,c;
};
bool cmp(node &x,node &y)
{
    return x.a<y.a;
}
ll cur[MAXN],ans[MAXN];
bool cmp2(int x,int y)
{
    return cur[x]<cur[y];
}
int order[MAXN];
vector<node> v;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v.push_back((node){x,y,z});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=n;i++)
    {
        a[i]=v[i-1].a;
        d[i]=v[i-1].d;
        c[i]=v[i-1].c;
        all[i]=1LL*(a[i]+a[i]-(c[i]-1)*d[i])*c[i]/2;
    }
    for(int i=1;i<=20000;i++) dp[0][i]=INF;
    solve(1,n,0);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&q[i]);
        ans[i]=INF;
    }
   /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=27;j++) printf("%lld ",nuse[i][j]);
        puts("");
    }*/
    for(int i=1;i<=n;i++) order[i]=i,cur[i]=a[i];
    for(int i=1;i<=20000;i++)
    {
        for(int j=1;j<=min(n,20000/i);j++)
        {
            int x=order[j];
            for(int id=0;id<k;id++) if(q[id]>=i) ans[id]=min(ans[id],cur[x]+nuse[x][q[id]-i]);
        }
        for(int j=1;j<=n;j++)
        {
            if(c[j]<i+1) cur[j]=INF;
            else cur[j]=1LL*(a[j]+a[j]-i*d[j])*(i+1)/2;
        }
        sort(order+1,order+n+1,cmp2);
    }
    for(int i=0;i<k;i++) printf("%lld\n",ans[i]);
    return 0;
}
