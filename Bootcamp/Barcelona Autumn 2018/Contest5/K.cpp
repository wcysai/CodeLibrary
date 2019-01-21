/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 16:10:27
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
typedef pair<int,int> P;
ll k,p,ans;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<(int)A.size();i++)
        for(ll k=0;k<(int)B.size();k++)
            for(ll j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%p;
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
}
ll pow_mod(ll a,ll i)
{
    ll s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%p;
        a=1LL*a*a%p;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%lld%lld",&k,&p);
    if(k==1) {printf("%lld\n",1%p);}
    else 
    {
        ans=k%p;
        ans=(ans+((k-1)%p)*pow_mod(10,k-1))%p;
        mat x(2,vec(1));x[0][0]=1;x[1][0]=1;
        mat A(2,vec(2)); A[0][0]=10;A[0][1]=1;A[1][0]=0;A[1][1]=1;
        //assert(0);
        A=_pow(A,k-2);x=mul(A,x);
        ans=((ans-x[0][0])%p+p)%p;
        printf("%lld\n",ans);
    }
    return 0;
}

