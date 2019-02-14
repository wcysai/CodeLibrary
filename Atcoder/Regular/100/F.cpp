#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25005
#define MAXK 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,m,a[MAXN];
int cnt[MAXN],res,premax,sufmax,save;
int pre[MAXN][MAXK],suf[MAXN][MAXK],ss[MAXN][MAXK];
int fact[MAXK],invf[MAXK];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int check()
{
    memset(cnt,0,sizeof(cnt));
    int res=0;
    premax=-1;sufmax=-1;
    bool flag=true;
    for(int i=1;i<=m;i++)
    {
        if(!cnt[a[i]]) res++;
        cnt[a[i]]++;
        if(i>k)
        {
            cnt[a[i-k]]--;
            if(!cnt[a[i-k]]) res--;
        }
        if(cnt[a[i]]>1&&premax==-1) premax=i-1;
        if(res==k) flag=false;
    }
    memset(cnt,0,sizeof(cnt));res=0;
    for(int i=m;i>=1;i--)
    {
        if(!cnt[a[i]]) res++;
        cnt[a[i]]++;
        if(i+k<=m)
        {
            cnt[a[i+k]]--;
            if(!cnt[a[i+k]]) res--;
        }
        if(i+k<=m) cnt[a[i+k]]--;
        if(cnt[a[i]]>1&&sufmax==-1) sufmax=m-i;
    }
    return flag;
}
void calcdp(int flag)
{
    auto dp=(flag?pre:suf);
    int sum[MAXK],sum2[MAXK];
    if(flag==2)
    {
        dp[0][0]=1;        
        for(int i=0;i<n;i++)
        {
            sum[k-1]=dp[i][k-1];
            sum2[k-1]=ss[i][k-1];
            for(int j=k-2;j>=0;j--) 
            {
                sum[j]=sum[j+1];sum2[j]=sum2[j+1];
                add(sum[j],dp[i][j]);add(sum2[j],ss[i][j]);
            }
            for(int j=1;j<k;j++)
            {
                add(dp[i+1][j],1LL*dp[i][j-1]*(k-j+1)%MOD);
                add(ss[i+1][j],1LL*ss[i][j-1]*(k-j+1)%MOD);
                add(dp[i+1][j],sum[j]);
                add(ss[i+1][j],sum2[j]);
                if(j>=m) add(ss[i+1][j],dp[i+1][j]);
            }
        }
        for(int j=1;j<k;j++) add(save,ss[n][j]);
        return;
    }
    if(flag) dp[0][premax]=1; else dp[0][sufmax]=1;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n-m;i++)
    {
        sum[k-1]=dp[i][k-1];
        for(int j=k-2;j>=0;j--) 
        {
            sum[j]=sum[j+1];
            add(sum[j],dp[i][j]);
        }
        for(int j=1;j<k;j++)
        {
            add(dp[i+1][j],1LL*dp[i][j-1]*(k-j+1)%MOD);
            add(dp[i+1][j],sum[j]);
        }
    }
    for(int i=0;i<=n-m;i++)
        for(int j=1;j<=k-1;j++) add(dp[i][j],dp[i][j-1]);
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=400;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[400]=pow_mod(fact[400],MOD-2);
    for(int i=399;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    int ans=1LL*(n-m+1)*pow_mod(k,n-m)%MOD;
    if(!check())
    {
        printf("%d\n",ans);
        return 0;
    }
    if(premax==-1||sufmax==-1)
    {
        save=0;calcdp(2);
        dec(ans,1LL*save*invf[k]%MOD*fact[k-m]%MOD);
        printf("%d\n",ans);
        return 0;
    }
    calcdp(0);calcdp(1);
   /* for(int i=0;i<=n-m;i++)
    {
        for(int j=1;j<=k-1;j++)
            printf("%d ",pre[i][j]);
        puts("");
    }*/
    for(int i=0;i<=n-m;i++) dec(ans,1LL*pre[i][k-1]*suf[n-m-i][k-1]%MOD);
    printf("%d\n",ans);
    return 0;
}

