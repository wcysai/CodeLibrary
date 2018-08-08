/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 14:35:36
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define FF first
#define S second
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll p,n,F[MAXN];
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<(int)A.size();i++)
        for(ll k=0;k<(int)B.size();k++)
            for(ll j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
    return C;
}
mat pow_(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(ll i=0;i<(int)A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
void init(long long p)
{
    F[0] = 1;
    for(ll i = 1;i <= p;i++)
        F[i] = F[i-1]*i % (1000000007);
}
long long inv(long long a,long long m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
long long Lucas(long long n,long long m,long long p)
{
    if(n<m) return 0;
    long long ans = 1;
    while(n&&m)
    {
        long long a = n%p;
        long long b = m%p;
        if(a < b)return 0;
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n /= p;
        m /= p;
    }
    return ans;
}
int main()
{
    scanf("%lld%lld",&p,&n);
    ll s=1;
    for(ll i=0;i<n;i++) s=s*p;
    init(p);
    mat A(s,vec(s));
    for(ll i=0;i<s;i++)
        for(ll j=0;j<s;j++)
            if(Lucas(i,j,p)>0) A[i][j]=1; else A[i][j]=0;
    ll sum=0;
    ll k;
    scanf("%lld",&k);
    A=pow_(A,k);
    for(ll i=0;i<s;i++)
    {
        for(ll j=0;j<s;j++)
        {
            sum+=A[i][j];
            printf("%lld ",A[i][j]);
        }
        puts("");
    }
    printf("%lld\n",sum);
    return 0;
}

