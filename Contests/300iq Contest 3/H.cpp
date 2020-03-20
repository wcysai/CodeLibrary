#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define INV 499122177
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,a[MAXN];
int dp[MAXN],ndp[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cur=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=cur+1;j<=a[i];j++)
        {
            memset(ndp,0,sizeof(ndp));
            for(int k=0;k<=n;k++) 
            {
                add(ndp[k],dp[k]);
                add(ndp[k+1],dp[k]);
            }
            swap(dp,ndp);
        }
        cur=a[i];
        memset(ndp,0,sizeof(ndp));
        for(int k=0;k<=n;k++)
        {
            add(ndp[k],dp[k]);
            if(k>1)
            {
                add(ndp[k-1],1LL*dp[k]*k%MOD*(k-1)%MOD);
            }
            else if(k==1) add(ans,dp[k]%MOD);
        }
        swap(dp,ndp);
    }
    for(int i=1;i<=n;i++) dec(ans,a[i]);
    ans=1LL*ans*INV%MOD;
    printf("%d\n",ans);
    return 0;
}