#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
int M;
mat mul(mat&A,mat &B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
    {
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++)
        {
            C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
        }
    }
    return C;
}
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        B[i][i]=1;
    }
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
    ll n;
    scanf("%lld%d",&n,&M);
    while(n!=0)
    {
    mat A(5,vec(5));
    A[0][0]=1;
    A[0][1]=1;
    A[0][2]=1;
    A[0][3]=2;
    A[0][4]=0;
    A[1][0]=1;
    A[1][1]=0;
    A[1][2]=0;
    A[1][3]=0;
    A[1][4]=0;
    A[2][0]=1;
    A[2][1]=0;
    A[2][2]=0;
    A[2][3]=0;
    A[2][4]=1;
    A[3][0]=1;
    A[3][1]=0;
    A[3][2]=0;
    A[3][3]=1;
    A[3][4]=0;
    A[4][0]=0;
    A[4][1]=0;
    A[4][2]=1;
    A[4][3]=0;
    A[4][4]=0;
    A=pow(A,n);
    printf("%d\n",A[0][0]);
    scanf("%lld%d",&n,&M);
    }
}

