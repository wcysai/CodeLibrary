/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 16:06:23
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<assert.h>
#include<time.h>
#define MAXN 3005
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
int n;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
    return C;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        srand(time(NULL));
        mat A(n,vec(n)),B(n,vec(n)),C(n,vec(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&A[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&B[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&C[i][j]);
        bool f=true;
        for(int i=0;i<2;i++)
        {
            mat D(n,vec(1));
            for(int j=0;j<n;j++)
                D[j][0]=rand()%201;
            if(mul(A,mul(B,D))!=mul(C,D))
            {
                f=false;
                break;
            }
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}



