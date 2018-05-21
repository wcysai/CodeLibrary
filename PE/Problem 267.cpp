#include<bits/stdc++.h>
using namespace std;
int check(double a)
{
    int j=0;
    while(true)
    {
        double s=1;
        for(int i=1;i<=j;i++)
            s=s*(1-a);
        for(int i=1;i<=1000-j;i++)
            s=s*(1+a);
        if (s<1000000000) break;
        j++;
    }
    return j-1;
}
// 0.182880  0.225000
int main()
{
    double left=0,right=1,mid,mmid;
    for(int i=1;i<=5000;i++)
    {
        mid=(right-left)/3+left,mmid=right-(right-left)/3;
        if(check(mid)>check(mmid)) right=mmid; else left=mid;
    }
    printf("%.12lf %d\n",mid,check(mid));
    return 0;
}
