#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,a;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&a);
        if(a>2)
        {
            printf("1 ");
            for(int i=0;i<n;i++)
                printf("%c",'a'+i%3);
            printf("\n");
            continue;
        }
        else if(a==1)
        {
            printf("%d ",n);
            for(int i=0;i<n;i++)
                printf("a");
            printf("\n");
            continue;
        }
        else
        {
            if(n==1)
            {
                printf("1 a\n");
                continue;
            }
            else if(n==2)
            {
                printf("1 ab\n");
                continue;
            }
            else if(n==3)
            {
                printf("2 aab\n");
                continue;
            }
            else if(n==4)
            {
                printf("2 aabb\n");
                continue;
            }
            else if(n==5)
            {
                printf("3 aaabb\n");
                continue;
            }
            else if(n==6)
            {
                printf("3 aaabab\n");
                continue;
            }
            else if(n==7)
            {
                printf("3 aaababb\n");
                continue;
            }
            else if(n==8)
            {
                printf("3 aaababbb\n");
                continue;
            }
            else
            {
                printf("4 ");
                for(int i=0;i<n;i++)
                    if(i%6==0||i%6==1||i%6==3) printf("a"); else printf("b");
                printf("\n");
                continue;
            }
        }
    }
    return 0;
}
