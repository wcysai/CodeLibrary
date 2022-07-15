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
double a,b,d;
const double PI=acos(-1.0);
int main()
{
    scanf("%lf%lf%lf",&a,&b,&d);
    d=d/180*PI;
    double x=a*cos(d)-b*sin(d);
    double y=b*cos(d)+a*sin(d);
    printf("%.10f %.10f\n",x,y);
    return 0;
}

