#include<bits/stdc++.h>
#define MAXN 1020
#define MAXM 550
using namespace std;
int num[MAXN];
int n,m,k;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x,y,r;
        scanf("%d",&r);
        scanf("%d",&x);
        int max1,max2,t1,t2;
        max1=max2=t1=t2=0;
        while(x!=-1)
        {
            scanf("%d",&y);
            if(y>=r)
            {
                if(y>max1)
                {
                    max2=max1;
                    t2=t1;
                    max1=y;
                    t1=x;
                }
                else if(y==max1)
                {
                    if(x<t1)
                    {
                        max2=max1;
                        t2=t1;
                        t1=x;
                    }
                    else
                    {
                        if(y>max2||(y==max2&&x<t2))
                        {
                            max2=y;
                            t2=x;
                        }
                    }
                }
                else
                {
                    if(y>max2||(y==max2&&x<t2))
                    {
                        max2=y;
                        t2=x;
                    }
                }
            }
            scanf("%d",&x);
        }
        if(max1==0) continue;
        else if(max2==0) num[t1]+=min(max1,(int)(1.1*r));
        else num[t1]+=min(max1,(int)(1.1*max2));
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int p;
        scanf("%d",&p);
        printf("%d\n",num[p]);
    }
    return 0;
}
