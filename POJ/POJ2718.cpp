#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define INF 10000000
using namespace std;
int k;
int digit[11];
int process(int m[],int z)
{
    int mult;
    mult=1;
    for(int i=1;i<(z+1)/2;i++)
        mult*=10;
    int t1,t2,res;
    t1=0;
    t2=z;
    res=0;
    while(t1<t2)
    {
        res+=(m[t2]-m[t1])*mult;
        mult/=10;
        t1++;
        t2--;
    }
    return res;
}
int init(int q[],int x,int y)
{
    int mult;
    int p[11];
    for(int i=0;i<10;i++)
      p[i]=q[i];
    mult=p[y]-p[x];
     for(int i=1;i<(k+1)/2;i++)
        mult*=10;
    for(int i=x+1;i<=k;i++)
        p[i-1]=p[i];
    if(y<k)
        for(int i=y;i<k;i++)
          p[i-1]=p[i];
    return mult-process(p,k-2);
}
int main()
{
    int n,ans;
    char c[1000];
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        k=-1;
        ans=INF;
        memset(digit,0,sizeof(digit));
        gets(c);
        for(int j=0;j<strlen(c);j++)
        {
            if (c[j]>=48&&c[j]<=57)
            {
                k++;
                digit[k]=c[j]-48;
            }
        }
        if(k==1)
        {
            printf("%d\n",digit[1]-digit[0]);
            continue;
        }
        else
        {
        if ((k+1)%2==0)
        {
        for(int j=0;j<k;j++)
                if(digit[j]!=0&&init(digit,j,j+1)>0) ans=min(ans,init(digit,j,j+1));
        }
        else
        {
            int t;
            for(int j=0;j<=k;j++)
                if(digit[j]>0)
                  {
                      t=j;
                      break;
                  }
            ans=digit[t];
            for(int j=0;j<k/2;j++)
                ans*=10;
              int p[11];
              memset(p,0,sizeof(p));
             for(int i=0;i<10;i++)
               p[i]=digit[i];
                for(int i=t+1;i<=k;i++)
                  p[i-1]=p[i];
            ans-=process(p,k-1);
        }
     printf("%d\n",ans);
        }
    }
  return 0;
}