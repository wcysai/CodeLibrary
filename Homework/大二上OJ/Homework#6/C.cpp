#include<bits/stdc++.h>
#define MAXN 55
#define INF 1e9
using namespace std;
const double eps=1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
int t,n,m;
vec gauss_jordan(const mat& A, const vec& b)
{
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];

    for(int i=0;i<n;i++) B[i][n]=b[i];
    for(int i=0;i<n;i++)
    {
        int pivot=i;
        for(int j=i;j<n;j++)
            if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
        swap(B[i],B[pivot]);
        if(abs(B[i][i])<eps) return vec();
        for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(int k=i+1;k<=n;k++)
                    B[j][k]-=B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)
        x[i]=B[i][n];
    return x;
}
int main()
{
    scanf("%d",&t);
    int cnt=0;
    while(t--)
    {
        cnt++;
        scanf("%d%d",&n,&m);
         mat A(n,vec(n));
        vec B(n);
        vec x(n);
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            A[x-1][y-1]+=1.0/z;
            A[y-1][x-1]+=1.0/z;
            A[x-1][x-1]-=1.0/z;
            A[y-1][y-1]-=1.0/z;
        }

        for(int i=0;i<n;i++)
            B[i]=i==0?1:0;
        B[n-1]=0;
        for(int i=0;i<n;i++)
            A[n-1][i]=i==0?1:0;
        x=gauss_jordan(A,B);
        printf("Case #%d: %.2f\n",cnt,x[n-1]);
    }
    return 0;
}
