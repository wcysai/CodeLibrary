#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,K,R;
int a[MAXN],pref[MAXN],preg[MAXN],suff[MAXN],sufg[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&K,&R);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        pref[0]=preg[0]=0;
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1];
            preg[i]=preg[i-1]+a[i];
            if(preg[i]>=K)
            {
                preg[i]=0;
                pref[i]++;
            }
            else if(preg[i]<0) preg[i]=0;
        }
        suff[n+1]=sufg[n+1]=0;
        for(int i=n;i>=1;i--)
        {
            suff[i]=suff[i+1];
            sufg[i]=sufg[i+1]+a[i];
            if(sufg[i]>=K)
            {
                sufg[i]=0;
                suff[i]++;
            }
            else if(sufg[i]<0) sufg[i]=0;
        }
        int ans1=-INF,ans2=INF;
        for(int i=R+1;i<=n+1;i++)
        {
            ans1=max(ans1,pref[i-R-1]+suff[i]+(preg[i-R-1]+sufg[i]>=K?1:0));
            ans2=min(ans2,pref[i-R-1]+suff[i]+(preg[i-R-1]+sufg[i]>=K?1:0));
        }
        printf("%d %d\n",ans1,ans2);
    }
}