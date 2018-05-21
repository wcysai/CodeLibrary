#include<bits/stdc++.h>
#define MAXN 101
using namespace std;
double x[MAXN],y[MAXN];
double calc(int n)
{
    double res=1,ans=1;
    for(int i=1;i<=10;i++)
    {
        ans=ans*(-n);
        res+=ans;
    }
    return res;
}
double interpolation(int n,double a)
{
    double s=0;
    for(int i=0;i<n;i++)
    {
        double res=1;
        for(int j=0;j<n;j++)
            if(j!=i) res=res*(a-x[j]);
        for(int j=0;j<n;j++)
            if(j!=i) res=res/(x[i]-x[j]);
        res=res*y[i];
        s+=res;
    }
    return s;
}
int main()
{
    double ans=0;
    for(int i=0;i<10;i++)
    {
        x[i]=i+1;
        y[i]=calc(i+1);
        ans+=interpolation(i+1,i+2);
        printf("%lf\n",ans);
    }
    return 0;
}
