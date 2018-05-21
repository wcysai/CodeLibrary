#include<cstdio>
#include<cmath>
int main()
{
double a[2049],b[2049];
int i,j,k;
for(i=1;i<=2048;i++) a[i]=0;
for(i=2;i<=2048;i++) a[i]=a[i-1]+(double)1/i;
i=1;
scanf("%lf",&b[i]);
while(b[i]!=0)
{
    i++;
    scanf("%lf",&b[i]);
}
for(j=1;j<=i-1;j++)
    for(k=1;k<=2048;k++)
 if (a[k]>=b[j])
 {
    printf("%d card(s)\n",k-1);
    break;
 }
return 0;
}
