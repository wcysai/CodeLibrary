#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int t,n;
P a[MAXN];
int save[MAXN],res[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].F);
            save[i]=a[i].F;
            a[i].S=i;
        }
        if(n==1)
        {
            printf("0\n%d\n",a[0].F);
            continue;
        }
        else if(n==2)
        {
            if(a[0].F==a[1].F) printf("0\n"); else printf("2\n");
            printf("%d %d\n",a[1].F,a[0].F);
            continue;
        }
        else if(n==3)
        {
            if((a[0].F==a[1].F)||(a[0].F==a[2].F)||(a[1].F==a[2].F)) printf("2\n"); else printf("3\n");
            printf("%d %d %d\n",a[1].F,a[2].F,a[0].F);
            continue;
        }
        else
        {
            printf("%d\n",n);
            sort(a,a+n);
            for(int i=0;i<n;i++)
            {
                int dest=i+2>=n?i+2-n:i+2;
                res[a[dest].S]=save[a[i].S];
            }
            for(int i=0;i<n;i++)
                printf("%d ",res[i]);
            printf("\n");
        }
    }
    return 0;
}
