#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
int n,i,j,sum,a[100001],mini,t,m,f;
scanf("%d",&m);
for(int k=1;k<=m;k++)
{
scanf("%d %d",&n,&t);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
sum=a[1];
i=1;
j=1;
f=1;
while(sum<t)
{
    j++;
    if(j>n)
    {
        printf("0\n");
        f=0;
        break;
    }
    sum+=a[j];
}
if(f)
{
mini=j-i+1;
while(i<j&&j<=n)
{
    sum-=a[i];
    i++;
    while(sum<t&&j<n)
    {
        j++;
        sum+=a[j];
    }
    if(sum>=t) mini=min(mini,j-i+1);
}
    printf("%d\n",mini);
}
}
return 0;
}