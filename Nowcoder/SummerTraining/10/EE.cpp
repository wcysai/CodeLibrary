/*************************************************************************
    > File Name: EE.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 15:19:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,M,k,a[MAXN];
int gcd(int a,int b) {if(b==0) return a; return gcd(b,a%b);}
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
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&M);
        int ans=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=M;i++)
        {
            int res=0;
            for(int j=1;j<(1<<n);j++)
            {
                int cnt=0,g=i;
                for(int k=0;k<n;k++)
                {
                    if((j>>k)&1)
                    {
                        cnt++;
                        g=gcd(g,a[k]);
                    }
                }
                res=(res+1LL*g*pow_mod(i,cnt-1))%MOD;
            }
            printf("%d\n",res);
            ans=ans^res;
        }
        printf("%d\n",ans);
    }
    return 0;
}

