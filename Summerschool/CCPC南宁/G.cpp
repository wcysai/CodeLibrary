#include<bits/stdc++.h>
using namespace std;
double ans[15],sum[15];
int n,k;
double r;
double cs=0.5,sn=sqrt(3)/2;
int main()
{
    scanf("%d",&n);
    scanf("%lf",&r);
    double len;
    int k=1;
    sum[0]=0;
    while(k<=n)
    {
        if(k==1) ans[k]=r/sn-r,len=(r+ans[k])/2-ans[k];
        else ans[k]=len*len/2/(len+r),len-=2*ans[k];
        k++;
    }
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        printf("%d %d\n",x,(int)ans[x]);
    }
    scanf("%d",&x);
    return 0;
}
