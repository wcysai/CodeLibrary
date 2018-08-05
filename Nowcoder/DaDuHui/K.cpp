/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 12:25:30
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
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
    return C;
}
int t,m,n,p,q;
int main()
{
    scanf("%d",&t);
    int tot=0;
    while(t--)
    {
        tot++;printf("Case %d:\n",tot);
        scanf("%d%d%d%d",&n,&m,&p,&q);
        mat A(n,vec(m));mat B(p,vec(q));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&A[i][j]);
        for(int i=0;i<p;i++) for(int j=0;j<q;j++) scanf("%d",&B[i][j]);
        if(m!=p) puts("ERROR");
        else
        {
            mat C=mul(A,B);
            for(int i=0;i<n;i++)
                for(int j=0;j<q;j++)
                    printf("%d%c",C[i][j],j==q-1?'\n':' ');
        }
    }
    return 0;
}

