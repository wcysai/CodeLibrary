#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define prev dksaodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int a[MAXN],b[MAXN];
ll suma[MAXN],sumb[MAXN];
int dp[MAXN],prev[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
        for(int i=1;i<=n;i++) sumb[i]=sumb[i-1]+b[i];
        int limit=n;
        for(int i=1;i<=n;i++)
        {
            int l=-1,r=i;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                ll ladd=suma[mid],radd=sumb[mid];
                ll mini=min(ladd,radd);
                ladd-=mini; radd-=mini;
                if(suma[i]-suma[mid]+ladd<k) r=mid; else l=mid;
            }
            if(r==i)
            {
                limit=i-1;
                break;
            }
            dp[i]=dp[r]+1; prev[i]=r;
        }
        int ans=INF,id=-1;
        for(int i=0;i<=limit;i++)
        {
            ll ladd=suma[i],radd=sumb[i];
            ll mini=min(ladd,radd);
            ladd-=mini; radd-=mini;
            int l=i-1,r=limit+1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(sumb[mid]-sumb[i]+radd>=k) r=mid; else l=mid;
            }
            if(r>limit||suma[r]-suma[i]+ladd>=k) continue;
            if(dp[i]<ans)
            {
                ans=dp[i];
                id=i;
            }
        }
        if(ans==INF) puts("-1"); else
        {
            printf("%d\n",ans);
            int cur=id;
            vector<int> v; v.clear();
            while(cur)
            {
                v.push_back(cur);
                cur=prev[cur];
            }
            sort(v.begin(),v.end());
            for(auto x:v) printf("%d ",x);
            puts("");
        }
    }
    return 0;
}
