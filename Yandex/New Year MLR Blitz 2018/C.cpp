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
double n,l,w,r,a[MAXN];
int main()
{
    scanf("%lf%lf%lf%lf",&n,&l,&w,&r);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    if(2*r>l) {puts("No"); return 0;}
    double mmin=0,mmax=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]*r-mmax>w) {puts("No"); return 0;}
        double l1,r1,l2,r2;
        if(a[i]*r+mmin>w) 
        {
            l1=INF;
            r1=-INF;
        }
        else
        {
            l1=a[i]*r+mmin;
            r1=min(w,a[i]*(l/2)+mmax);
        }
        if((a[i]*r-mmax)*(a[i]*(l/2)-mmin)<=0) 
        {
            l2=0;
            r2=max(abs(a[i]*r-mmax),abs(a[i]*(l/2)-mmin));
        }
        else if(a[i]*r-mmax>0) 
        {
            l2=a[i]*r-mmax;
            r2=a[i]*(l/2)-mmin;
        }
        else 
        {
            l2=mmin-a[i]*(l/2);
            r2=mmax-a[i]*r;
        }
        mmin=min(l1,l2); mmax=max(r1,r2);
        mmin=max((double)0,mmin); mmax=min(w,mmax);
    }
    puts("Yes");
    return 0;
}

