/*************************************************************************
    > File Name: NMNMX.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 21:22:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,fact[MAXN],invf[MAXN],a[MAXN];
int comb[MAXN][MAXN];
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
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000]=pow_mod(fact[10000],MOD-2);
    for(int i=9999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    comb[0][0]=1;
    for(int i=1;i<=10000;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%(MOD-1);
    }
    scanf("%d",&t);
    while(t--)
    {
        int ans=1;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ans=1LL*ans*a[i]%MOD;
        }
        //printf("%d %d\n",invf[1],fact[0]);
        ans=pow_mod(ans,comb[n-1][k-1]);
        //printf("%d\n",ans);
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            int cnt=comb[i][k-1],inv=1LL*invf[a[i]]*fact[a[i]-1]%MOD;
            //printf("%d\n",cnt);
            ans=1LL*ans*pow_mod(inv,cnt)%MOD;
            cnt=comb[n-1-i][k-1];
            //printf("%d\n",cnt);
            ans=1LL*ans*pow_mod(inv,cnt)%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}

