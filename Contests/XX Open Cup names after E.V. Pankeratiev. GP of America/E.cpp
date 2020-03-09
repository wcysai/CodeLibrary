#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 1005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,MOD;
int save[13];
int dp[MAXN][(1<<12)],ndp[MAXN][(1<<12)];
int tmp[MAXN][MAXN][(1<<12)];
int s[MAXN][MAXN][(1<<12)];
//mask: 0: to left 1: to right
//fourth demension 0: up 1: down
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
bool check(int mask1,int id1,int mask2,int id2)
{
    
    int m1=0,m2=0;
    for(int i=0;i<n/2;i++)
    {
        if(!(mask1&(1<<i))) continue;
        else
        {
            if(save[id1]&(1<<i)) m1+=(1<<(2*i+1));
            else m1+=(1<<(2*i));
        }
    }
    for(int i=0;i<n/2;i++)
    {
        if((mask2&(1<<i))) continue;
        else
        {
            if(save[id2]&(1<<i)) m2+=(1<<(2*i+1));
            else m2+=(1<<(2*i));
        }
    } 
    for(int i=0;i<n-1;i++)
        if((!(m1&(1<<i)))&&(!(m2&(1<<i)))&&(!(m1&(1<<(i+1))))&&(!(m2&(1<<(i+1))))) return false;
    return true;
}
int get_type(int mask1,int mask2,int i)
{
    int s=(((mask2>>i)&1)<<1)+(mask1>>i)&1;
    return s;
}
int main()
{
    scanf("%d%d%d",&n,&m,&MOD);
    if(n%2==1&&m%2==1) {puts("1"); return 0;}
    if(m%2==1) {printf("%d\n",pow_mod(n/2+1,m/2)); return 0;}
    if(n%2==1) {printf("%d\n",pow_mod(m/2+1,n/2)); return 0;}
    for(int i=0;i<=n/2;i++)
        for(int j=0;j<n/2;j++)
            if(j<i) save[i]+=(1<<j);
    for(int i=0;i<=n/2;i++)
        for(int j=0;j<=n/2;j++)
            for(int mask=0;mask<(1<<(n/2));mask++)
            {
                int sub=mask;
                do
                {
                    if(check(mask,i,sub,j)) s[i][j][mask]|=sub;
                    //operation here
                    sub=(sub-1)&mask;
                }while(sub!=mask);
            }
    for(int i=0;i<(1<<(n/2));i++)
        for(int j=0;j<=n/2;j++)
            dp[j][i]=1;
    for(int i=0;i<m/2-1;i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=n/2;j++)
            for(int k=0;k<=n/2;k++)
                for(int mask=0;mask<(1<<(n/2));mask++)
                    add(ndp[k][s[j][k][mask]],dp[j][mask]);
        
        for(int j=0;j<=n/2;j++)
            for(int l=0;l<(n/2);l++)
                for(int mask=0;mask<(1<<(n/2));mask++)
                    if(!(mask&(1<<l)))
                        add(ndp[j][mask],ndp[j][mask^(1<<l)]);
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<(1<<(n/2));i++)
        for(int j=0;j<=n/2;j++)
            add(ans,dp[j][i]);
    printf("%d\n",ans);
    return 0;
}