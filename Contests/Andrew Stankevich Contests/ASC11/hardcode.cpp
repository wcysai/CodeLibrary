#include<bits/stdc++.h>
#define MAXN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int m,n;
ll dp[10][(1<<17)];
bool check_valid(int mask,int mask3,bool isodd)
{
    int mask1,mask2;
    if(isodd)
    {
        mask1=mask>>(m+1);
        mask2=mask&((1<<(m+1))-1);
        for(int i=0;i<m+1;i++)
        {
            if(mask2&(1<<i))
            {
                int dl=i==0?0:(mask1>>(i-1))&1;
                int dr=i==m?0:(mask1>>i)&1;
                int ul=i==0?0:(mask3>>(i-1))&1;
                int ur=i==m?0:(mask3>>i)&1;
                int l=i==0?0:(mask2>>(i-1))&1;
                int r=i==m?0:(mask2>>(i+1))&1;
                if(!dl&&!dr) return false;
                if(dl&&dr) continue;
                if(dl)
                {
                    if(ul&&!ur) continue;
                    if(r) continue;
                    return false;
                }
                else
                {
                    if(ur&&!ul) continue;
                    if(l) continue;
                    return false;
                }
            }
        }
    }
    else
    {
        mask1=mask>>m;
        mask2=(mask&((1<<m)-1));
        for(int i=0;i<m;i++)
        {
            if(mask2&(1<<i))
            {
                int dl=(mask1>>i)&1;
                int dr=(mask1>>(i+1))&1;
                int ul=(mask3>>i)&1;
                int ur=(mask3>>(i+1))&1;
                int l=i==0?0:(mask2>>(i-1))&1;
                int r=i==m-1?0:(mask2>>(i+1))&1;
                if(!dl&&!dr) return false;
                if(dl&&dr) continue;
                if(dl)
                {
                    if(ul&&!ur) continue;
                    if(r) continue;
                    return false;
                }
                else
                {
                    if(ur&&!ul) continue;
                    if(l) continue;
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int tot=0;
    while(scanf("%d%d",&m,&n)==2)
    {
        if(n==1)
        {
            tot++;
            if(tot%10==0) printf("1,\n"); else printf("1,");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int mask=1;mask<(1<<(m+1));mask++) dp[1][(((1<<m)-1)<<(m+1))+mask]=1;
        for(int i=1;i<n-1;i++)
        {
            for(int mask=1;mask<(1<<(2*m+1));mask++)
            {
                if(!dp[i][mask]) continue;
                for(int j=1;j<(1<<(i&1?m:m+1));j++)
                {
                    if(check_valid(mask,j,i&1)) 
                    {
                        int mask2=(i&1?mask&((1<<(m+1))-1):mask&((1<<m)-1));
                        int newmask=(mask2<<(i&1?m:m+1))+j;
                        dp[i+1][newmask]+=dp[i][mask];
                    }
                }
            }
        }
        ll ans=0;
        for(int mask=1;mask<(1<<(2*m+1));mask++) 
            if(check_valid(mask,0,(n-1)&1)) 
                ans+=dp[n-1][mask];
        tot++;
        if(tot%10==0) printf("%lld,\n",ans); else printf("%lld,",ans);
    }
    return 0;
}
