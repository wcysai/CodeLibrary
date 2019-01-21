/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 05:08:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%m;
    return C;
}
mat _pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<(int)A.size();i++)
        B[i][i]=1;
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
    scanf("%d%d",&n,&m);
    mat A(m,vec(m));
    for(int i=0;i<m;i++)
    {
        int last=(i-1+m)%m;
        A[i][last]=1;
        A[i][i]=i;
    }
    mat x(m,vec(1));x[0][0]=1;
    A=_pow(A,n);x=mul(A,x);
    printf("%d\n",x[0][0]);
    return 0;
}

