/*************************************************************************
    > File Name: GMEDIAN.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 08:58:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int T,N,A[MAXN];
int fact[MAXN],invf[MAXN];
bool g[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=2000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2000]=pow_mod(fact[2000],MOD-2);
    for(int i=1999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        memset(g,false,sizeof(g));
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&A[i]);
            g[A[i]]=true;
        }
        sort(A+1,A+N+1);
        for(int i=1;i<=N;i++)
        {
            int l=i-1,r=N-i;
            add(ans,comb(l+r,r));
        }
        for(int i=1;i<=N;i++)
            for(int j=i+1;j<=N;j++)
            {
                if(A[i]!=A[j]) continue;
                int l=i-1,r=N-j;
                add(ans,comb(l+r,r));
            }
        printf("%d\n",ans);
    }
    return 0;
}

