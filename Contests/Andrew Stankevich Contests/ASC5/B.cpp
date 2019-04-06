#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
const db PI=acos(-1.0);
const db eps=1e-8;
int n;
db x[MAXN],y[MAXN];
int main()
{
    freopen("angle.in","r",stdin);
    freopen("angle.out","w",stdout);
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        for(int i=0;i<n;i++) scanf("%Lf%Lf",&x[i],&y[i]);
        db ang=0;
        printf("%.20Lf\n",(db)0.0);
        for(int i=1;i<n;i++) ang-=atan2(y[i]-y[i-1],x[i]-x[i-1]);
        if(n>1) ang=ang/(n-1);
        while(ang<0-eps) ang+=2*PI;
        while(ang>2*PI+eps) ang-=2*PI;
        printf("%.20Lf\n",ang);
        db cosa=cos(ang);
        db sina=sin(ang);
        for(int i=0;i<n;i++) printf("%.20Lf %.20Lf\n",x[i]*cosa-y[i]*sina,x[i]*sina+y[i]*cosa);
        printf("\n");
    }
    return 0;
}
