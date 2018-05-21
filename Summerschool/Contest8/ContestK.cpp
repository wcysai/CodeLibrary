#include<bits/stdc++.h>
#define MAXN 2005
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,t;
ll c[MAXN],tri[MAXN][MAXN];
ll save[MAXN];
void cal(int n)
{
    tri[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            if(j==1||j==i) tri[i][j]=1; else tri[i][j]=(tri[i-1][j-1]+tri[i-1][j])%MOD;
    }
}
int com(int x,int y)
{
    return tri[x+1][y+1];
}
int main()
{
    scanf("%d",&t);
    cal(2001);
    for(int k=0;k<t;k++)
    {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        save[i]=1;
        for(int j=1;j<=n;j++)
            save[i]=(save[i]*i)%MOD;
    }
    for(int i=1;i<m;i++)
    {
        c[i]=save[i];
        for(int j=1;j<i;j++)
            if((i-j)%2==1) c[i]=((c[i]-com(i,j)*save[j])%MOD+MOD)%MOD; else c[i]=((c[i]+com(i,j)*save[j])%MOD+MOD)%MOD;

    }
    ll ans=0;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<=m-i;j++)
            ans=(ans+(com(m,i)*c[i]%MOD)*(com(m-i,j)*c[j]%MOD)+MOD)%MOD;
    }
    printf("%lld\n",ans);
    }
    return 0;
}
