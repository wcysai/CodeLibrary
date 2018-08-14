#include<bits/stdc++.h>
#define MAXN 2005
#define eps 1e-1
using namespace std;
int t,n;
double a[MAXN];
double calc(double x)
{
    double s=x;
    for(int i=0;i<n-1;i++)
    {
        x=a[i]/x;
        s+=x;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    int p=0;
    while(t--)
    {
        p++;
        scanf("%d",&n);
        double right=-1,left=100000;
        for(int i=0;i<n-1;i++)
        {
            scanf("%lf",&a[i]);
            right=max(right,a[i]);
            left=min(left,a[i]);
        }
        while(right-left>eps)
        {
            double mid1=left+(right-left)/3,mid2=right-(right-left)/3;
            if(calc(mid1)<calc(mid2)) left=mid1; else right=mid2;
        }
        printf("%.5f\n",calc(right));
    }
    return 0;
}
