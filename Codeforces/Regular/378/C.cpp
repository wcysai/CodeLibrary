#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 500
#define INF 100000
using namespace std;
int n,k,a[MAXN],b[MAXN],save[MAXN][2];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    memset(save,0,sizeof(save));
        int f=0,s=0,ans=a[0],t=0,res=0,cnt=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]!=ans) f=1;
            s+=a[j];
            if(a[j]>ans)
            {
                ans=a[j];
                t=j;
            }
            if(s>b[cnt])
            {
                printf("NO\n");
                return 0;
            }
            if(s==b[cnt])
            {
                if(!f&&j-res>0)
                {
                    printf("NO\n");
                    return 0;
                }
                else
                {
                    save[cnt][0]=t;
                    save[cnt][1]=j-res+1;
                    f=0;
                    t=j+1;
                    res=t;
                    ans=a[t];
                    s=0;
                    cnt++;
                }
            }
        }
        if(s!=0)
        {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        int cal=n-1;
        for(int i=k-1;i>=0;i--)
        {
            int rb=cal,lb=cal-save[i][1]+1;
            cal-=save[i][1];
            int cnt=0,x=save[i][0];
            for(int j=0;j<save[i][1]-1;j++)
            {
                if(x>lb&&a[x]>a[x-1])
                {
                    printf("%d L\n",x+1);
                    a[x-1]=a[x]+a[x-1];
                    x--;
                    for(int l=x+1;l<n-1;l++)
                        a[l]=a[l+1];
                    n--;
                }
                else
                 if(x<rb&&a[x]>a[x+1])
                {
                    printf("%d R\n",x+1);
                    a[x]=a[x]+a[x+1];
                    for(int l=x+1;l<n-1;l++)
                        a[l]=a[l+1];
                    n--;
                }
            }
        }
      return 0;
}
