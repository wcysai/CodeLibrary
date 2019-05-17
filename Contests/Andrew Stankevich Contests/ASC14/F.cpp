#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
db rat,l;
const double PI=acos(-1.0);
int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    scanf("%lf%lf",&rat,&l);
    db tang=asin(rat);
    db reang=asin(1.0/l);
    if(tang<reang)
    {
        printf("%.10f\n",1.0);
        return 0;
    }
    db ang=PI/2-tang+reang;
    db sang=PI-2*ang;
    db alpha=PI/2-tang;
    db beta=sang;
    db r1=cos(alpha)-cos(alpha+beta);
    db r2=cos(alpha)-cos(PI);
    printf("%.10f\n",1.0-r1/r2);
    return 0;
}
