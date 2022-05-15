#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
int x[MAXN],y[MAXN];
bool dp[(1<<10)][(1<<10)];
P pre[(1<<10)][(1<<10)];
vector<int> calc(int mask2,int j)
{
    vector<int> v;
    ll dist=INF;
    for(int i=n;i<=2*n;i++)
    {
        if(i!=n&&(mask2&(1<<(i-n-1)))) continue;
        ll d=1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]);
        if(d==dist) v.push_back(i-n);
        else if(d<dist)
        {
            v.clear();
            v.push_back(i-n);
            dist=d;
        }
    }
    return v;
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        memset(dp,false,sizeof(dp));
        for(int i=0;i<2*n+1;i++) scanf("%d%d",&x[i],&y[i]);
        dp[0][0]=true;
        for(int mask1=0;mask1<(1<<n);mask1++)
        {
            for(int mask2=0;mask2<(1<<n);mask2++)
            {
                if(!dp[mask1][mask2]) continue;
                for(int chosen=0;chosen<n;chosen++)
                {
                    if(mask1&(1<<chosen)) continue;
                    vector<int> v=calc(mask2,chosen);
                    for(auto to:v) 
                    {
                        if(to!=0)
                        {
                            dp[mask1|(1<<chosen)][mask2|(1<<(to-1))]=true;
                            pre[mask1|(1<<chosen)][mask2|(1<<(to-1))]=P(chosen,to-1);
                        }
                    }
                }
            }
        }
        printf("Case #%d: ",t);
        if(!dp[(1<<n)-1][(1<<n)-1]) {puts("IMPOSSIBLE"); continue;}
        puts("POSSIBLE");
        int mask1=(1<<n)-1,mask2=(1<<n)-1;
        vector<P> ans;
        while(mask1&&mask2)
        {
            P p=pre[mask1][mask2];
            ans.push_back(pre[mask1][mask2]);
            mask1^=(1<<p.F); mask2^=(1<<p.S);
        }
        reverse(ans.begin(),ans.end());
        for(auto p:ans) printf("%d %d\n",p.F+1,p.S+2);
    }
    return 0;
}

