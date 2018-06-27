#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n,m;
mat mul(mat A,mat B)
{
    int x=A.size(),y=B.size(),z=B[0].size();
    mat C(x,vec(z));
    for(int i=0;i<x;i++)
    {
        for(int k=0;k<y;k++)
        {
            for(int j=0;j<z;j++)
            {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
            }
        }
    }
    return C;
}
mat pow(mat A,ll n)
{
     int x=A.size();
     mat B(x,vec(x));
     for(int i=0;i<x;i++)
        B[i][i]=1;
     while(n>0)
     {
         if(n&1) B=mul(B,A);
         A=mul(A,A);
         n >>= 1;
     }
     return B;
}
int main()
{
    int t;
    scanf("%d",&t);
    mat P(4,vec(2));
    mat X(4,vec(4));
    X[0][0]=1;
    X[0][1]=2;
    X[1][0]=1;
    X[1][1]=0;
    for(int i=0;i<2;i++)
        for(int j=2;j<4;j++)
            X[i][j]=0;
    for(int i=2;i<4;i++)
        for(int j=2;j<4;j++)
            X[i][j]=i==j?1:0;
    for(int i=2;i<4;i++)
        for(int j=0;j<2;j++)
            X[i][j]=i-2==j?1:0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                P[i][j]=i==j?1:0;
        for(int i=2;i<4;i++)
            for(int j=0;j<2;j++)
                P[i][j]=0;
    mat A(4,vec(4));
    mat B(4,vec(2));
    mat Q(2,vec(2));
    for(int i=0;i<t;i++)
    {
        scanf("%I64d %I64d",&n,&m);
        A=pow(X,n);
        B=mul(A,P);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                Q[i][j]=B[i+2][j];
        Q=pow(Q,m-1);
        printf("%I64d\n",Q[0][0]);
    }
    return 0;
}
