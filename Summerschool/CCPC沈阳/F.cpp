#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;
int n,query;
int a[MAXN],sum[MAXN],dp[MAXN][2],save[250];
int main()
{
    scanf("%d",&query);
    for(int i=0;i<205;i++)
        save[i]=i*(i+1)/2;
    while(query--)
    {
        int t=0;
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<205;i++)
            if(save[i]>=n) {t=i; break;}
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=t;i>=1;i--)
        {
            if(i==t)
            {
                for(int j=save[i-1]+1;j<=n;j++)
                {
                    if(j+i-1==n)
                    {
                        dp[j][0]=sum[n]-sum[j-1];
                        dp[j][1]=sum[j-1]-sum[n];
                    }
                    else dp[j][0]=dp[j][1]=0;
                }
            }
            else
            {
                for(int j=save[i-1]+1;j<=save[i];j++)
                {
                    int a,b,c,d;
                    if(j+i-1>n) {a=b=0;}
                    else if(j+i-1==n) {sum[n]-sum[j-1]; b=-sum[n]+sum[j-1];}
                    else
                    {
                        a=sum[j+i-1]-sum[j-1]+dp[j+i][1];
                        b=sum[j+i-1]-sum[j-1]+dp[j+i][0];
                    }
                    if(j+i>n) c=d=0;
                    else if(j+i==n) {c=sum[n]-sum[j-1]; d=sum[j-1]-sum[n];}
                    else
                    {
                        c=sum[j+i]-sum[j-1]+dp[j+i+1][1];
                        d=sum[j+i]-sum[j-1]+dp[j+i+1][0];
                    }
                    dp[j][0]=max(a,c);
                    dp[j][1]=min(b,d);
                }
            }
        }
        printf("%d\n",dp[1][0]);
    }
    return 0;
}
