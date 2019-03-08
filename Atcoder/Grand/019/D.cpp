#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next dsodfds
#define prev dskjfodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char a[MAXN],b[MAXN];
int sum[MAXN];
int next[MAXN],prev[MAXN];
int dp[MAXN];
void left_shift()
{
    char ch=a[1];
    for(int i=1;i<n;i++) a[i]=a[i+1];
    a[n]=ch;
}
void right_shift()
{
    char ch=a[n];
    for(int i=n;i>=2;i--) a[i]=a[i-1];
    a[1]=ch;
}
//go left
int dist(int from,int to)
{
    if(from>=to) return from-to;
    else return from+(n-to);
}
int main()
{
    scanf("%s",a+1);scanf("%s",b+1);
    n=strlen(a+1);
    bool f=false;
    for(int i=1;i<=n;i++) if(b[i]=='1') f=true;
    if(!f)
    {
        for(int i=1;i<=n;i++) if(a[i]!=b[i]) {puts("-1"); return 0;}
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++) if(b[i]=='1') {next[1]=i;break;}
    for(int i=n;i>=2;i--) if(b[i]=='1') next[i]=i; else next[i]=next[i%n+1];
    for(int i=n;i>=1;i--) if(b[i]=='1') {prev[n]=i; break;}
    for(int i=1;i<=n-1;i++) if(b[i]=='1') prev[i]=i; else prev[i]=prev[i-1+(i==1?n:0)];
    int ans=2*n;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++) if(a[j]!=b[j]) cnt++;
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=n;j++)
        {
            if(a[j]!=b[j])
            {
                int ori=j+i;
                if(ori>n) ori-=n;
                int l=prev[ori],r=next[ori];
                int f=max(i,dist(ori,l)),g=dist(r,ori);
                dp[f-1]=max(dp[f-1],g);
            }
        }
        for(int j=n;j>=i;j--) dp[j]=max(dp[j],dp[j+1]);
        for(int j=n;j>=i;j--) ans=min(ans,2*(j+dp[j])-i+cnt);
        left_shift();
    }
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++) if(a[j]!=b[j]) cnt++;
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=n;j++)
        {
            if(a[j]!=b[j])
            {
                int ori=j-i;
                if(ori<=0) ori+=n;
                int l=prev[ori],r=next[ori];
                int f=dist(ori,l),g=max(i,dist(r,ori));
                dp[g-1]=max(dp[g-1],f);
                //printf("%d %d %d\n",j,g,f);
            }
        }
        for(int j=n;j>=i;j--) dp[j]=max(dp[j],dp[j+1]);
        for(int j=n;j>=i;j--) ans=min(ans,2*(j+dp[j])-i+cnt);
        right_shift();
    }
    printf("%d\n",ans);
    return 0;
}

