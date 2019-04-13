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
int r;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%r;
    return C;
}
mat pow_mod(mat A,int i)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<(int)A.size();i++) B[i][i]=1;
    while(i)
    {
        if(i&1) B=mul(B,A);
        A=mul(A,A);
        i>>=1;
    }
    return B;
}
map<P,int> mp;
int main()
{
    freopen("fibonacci.in","r",stdin);
    freopen("fibonacci.out","w",stdout);
    scanf("%d",&r);
    int t=(int)sqrt(r)+1;
    mat x(2,vec(1)); x[0][0]=0; x[0][1]=1;
    mat A(2,vec(2)); A[0][0]=A[0][1]=A[1][0]=1; A[1][1]=0;
    mat dummy=A;
    mp[P(0,1)]=0;
    for(int i=1;i<t;i++) 
    {
        P p;
        p.F=dummy[0][1],p.S=dummy[1][1];
        mp[p]=i;
        dummy=mul(dummy,A);
    }
    A[0][1]=A[1][0]=1; A[0][0]=0; A[1][1]=r-1;
    mat B(2,vec(2)); B[0][0]=B[1][1]=1; B[0][1]=B[1][0]=0;
    dummy=B;
    for(int i=1;i<=t;i++) B=mul(B,A);
    for(int i=1;;i++)
    {
        dummy=mul(dummy,B);
        P p;
        p.F=dummy[0][1],p.S=dummy[1][1];
        if(mp.find(p)!=mp.end())
        {
            printf("%lld\n",1LL*i*t+mp[p]);
            return 0;
        }
    }
    return 0;
}
