#include<bits/stdc++.h>
#define MAXN 3005
int n,t,G[5][5],deg[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(deg,0,sizeof(deg));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if(n<=5)
            {
            G[i][j]=x;
            G[j][i]=x;
            }
            if(x==1) {deg[i]++; deg[j]++;}
        }
    }
    int f=1;
    for(int i=0;i<n;i++)
    {
        if(deg[i]>=3||n-1-deg[i]>=3||n>5)
        {
            printf("Bad Team!\n");
            f=0;
            break;
        }
        else
        {
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
        {
            if(j!=i&&k!=i)
            {
                if((G[i][j]==1&&G[i][k]==1&&G[j][k]==1)||(G[i][j]==0&&G[i][k]==0&&G[j][k]==0))
                {
                    printf("Bad Team!\n");
                    f=0;
                    break;
                }
            }
        }
        }
        if(!f) break;
    }
    if(f) printf("Great Team!\n");
    }
    return 0;
}
