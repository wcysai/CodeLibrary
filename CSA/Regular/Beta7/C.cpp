/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 20:25:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<(int)A.size();i++)
        for(ll k=0;k<(int)B.size();k++)
            for(ll j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}
mat _pow(mat A,ll n)
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
};
int main()
{
    mat A(2,vec(2));mat x(2,vec(1));
    A[0][0]=4;A[0][1]=1;
    A[1][0]=2;A[1][1]=1;
    x[0][0]=x[1][0]=1;
    scanf("%lld",&n);
    A=_pow(A,n-1);
    x=mul(A,x);
    printf("%lld\n",x[0][0]);
    return 0;
}

