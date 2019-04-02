#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
using namespace std;
typedef long double db;
db r1,r2;
db F(db x)
{
    return sqrt((r1*r1-x*x)*(r2*r2-x*x));
}
db simpson(db a,db b)
{
    db c=a+(b-a)/2;
    return (F(a)+4*F(c)+F(b))*(b-a)/6;
}
db asr(db a,db b,db eps,db A)
{
    db c=a+(b-a)/2;
    db L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15.0;
    return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
db asr(db a,db b,db eps)
{
    return asr(a,b,eps,simpson(a,b));
}
int main()
{
    freopen("twocyl.in","r",stdin);
    freopen("twocyl.out","w",stdout);
    scanf("%Lf%Lf",&r1,&r2);
    if(r1>r2) swap(r1,r2);
    printf("%.4Lf\n",8.0*asr(0,r1,1e-10));
}
