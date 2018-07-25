/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-25 12:08:56
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,A,B;
int fact[MAXN],invf[MAXN],pow2[10000005];
int a[4][4],cnt[5][5];
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
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;pow2[0]=1;
    for(int i=1;i<=3000;i++) fact[i]=1LL*i*fact[i-1]%MOD;
    invf[3000]=pow_mod(fact[3000],MOD-2);
    for(int i=2999;i>=1;i--) invf[i]=1LL*(i+1)*invf[i+1]%MOD;
    for(int i=1;i<=10000000;i++) pow2[i]=2LL*pow2[i-1]%MOD;
    for(int i=0;i<(1<<12);i++)
    {
        for(int j=0;j<4;j++)
            for(int k=0;k<3;k++)
            {
                int num=j*3+k;
                a[j][k]=(i>>num)&1;
            }
        int cnt1=0,cnt2=0;
        for(int i=0;i<4;i++) if(a[i][0]&&a[i][1]&&a[i][2]) cnt1++;
        for(int i=0;i<3;i++) if(a[0][i]&&a[1][i]&&a[2][i]&&a[3][i]) cnt2++;
        cnt[cnt1][cnt2]++;
        
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
            printf("%8d ",cnt[i][j]);
        puts("");
    }
    return 0;
}

