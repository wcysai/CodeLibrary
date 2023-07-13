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
int n,p,q,a[MAXN],b[MAXN];
double calc(double x){
    double y=1.0;
    for(int i=1;i<=n;i++){
        y=min(y,(1.0-a[i]*x)/b[i]);
    }
    return p*x+q*y;
}
int main()
{
    scanf("%d%d%d",&n,&p,&q);
    double l=0.0,r=1.0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        r=min(r,1.0/a[i]);
    }
    for(int i=0;i<60;i++){
        double lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2.0;
        if(calc(lb)>calc(rb)) r=rb; else l=lb;
    }
    printf("%.10f\n",calc(l));
    return 0;
}

