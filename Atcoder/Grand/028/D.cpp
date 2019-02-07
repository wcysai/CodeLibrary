#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,K,a[MAXN],b[MAXN];
int unpaired[MAXN];
int sum[MAXN];
int ffact[MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&K);
    n*=2;
    ffact[0]=1;
    for(int i=1;i<=600;i++)
    {
        if(i&1) ffact[i]=1LL*i*ffact[i-1]%MOD;
        else ffact[i]=ffact[i-1];
    }
    for(int i=1;i<=600;i+=2) ffact[i]=0;
    for(int i=1;i<=n;i++) unpaired[i]=1;
    for(int i=0;i<K;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        unpaired[a[i]]=unpaired[b[i]]=0;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+unpaired[i];
    int ans=0;
    for(int len=2;len<=n;len+=2)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            bool f=true;
            for(int k=0;k<K;k++)
            {
                bool f1=(a[k]>=i&&a[k]<=j);
                bool f2=(b[k]>=i&&b[k]<=j);
                if(f1^f2) f=false;
            }
            if(!f)
            {
                dp[i][j]=0;
                continue;
            }
            int x=sum[j]-sum[i-1];
            dp[i][j]=ffact[x];
            for(int k=i+1;k<j;k+=2)
            {
                int y=sum[j]-sum[k];
                dec(dp[i][j],1LL*dp[i][k]*ffact[y]%MOD);
            }
            add(ans,1LL*dp[i][j]*ffact[sum[n]-x]%MOD);
        }
    }
    printf("%d\n",ans);
    return 0;
}

