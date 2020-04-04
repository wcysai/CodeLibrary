#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double threshold=0.25;
typedef vector<double> vec;
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
mat pow_(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
double p[MAXN];
mat construct_matrix()
{
    mat A(n,vec(n));
    for(int i=0;i<n;i++)
    {
        if(p[i]<=threshold)
        {
            for(int j=0;j<n;j++) A[i][j]=(i==j?1:0);
        }
        else
        {
            int cnt=0;
            for(int j=0;j<n;j++)
                if(__builtin_popcount(i^j)==1)
                    cnt++;
            for(int j=0;j<n;j++)
                if(__builtin_popcount(i^j)==1)
                {
                    A[i][i]+=1.0/cnt*p[i]/(p[i]+p[j]);
                    A[i][j]+=1.0/cnt*p[j]/(p[i]+p[j]);
                }
        }
    }
    return A;
}
int main()
{
    n=4;
    p[0]=1; p[1]=p[2]=0.5; p[3]=0.25;
    mat A=construct_matrix();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%.10f ",A[i][j]);
        puts("");
    }
    mat x(1,vec(4));
    x[0][0]=1.0;
    A=pow_(A,10);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%.10f ",A[i][j]);
        puts("");
    }
    x=mul(x,A);
    double ans=0.0;
    for(int i=3;i<4;i++) ans+=x[0][i];
    printf("%.10f\n",ans);
    return 0;
}