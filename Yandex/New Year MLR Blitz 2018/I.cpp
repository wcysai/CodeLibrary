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
typedef long double db;
db C[55][55];
db p2[55];
int T,N,Z;
int main()
{
    C[1][0]=C[1][1]=1.0;
    for(int i=2;i<=50;i++)
    {
        C[i][0]=C[i][i]=1.0;
        for(int j=1;j<i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    p2[0]=1.0;
    for(int i=1;i<=50;i++) p2[i]=2.0*p2[i-1];
    while(scanf("%d%d",&N,&Z)==2)
    {
        if(Z==0) {printf("%.10Lf\n",(long double)0.0); continue;}
        if(Z>N) {printf("%.10Lf\n",(long double)100.0); continue;}
        db res=0;
        for(int i=0;i<=Z;i++) res+=C[N][i]*p2[N-i];
        printf("%.10Lf\n",100-100*C[N][Z]*p2[N-Z]/res);
    }
    return 0;
}

