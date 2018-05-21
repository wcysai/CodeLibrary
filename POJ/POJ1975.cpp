#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#define MAXN 130
#define INF 1000000
using namespace std;
int d[MAXN][MAXN];
int V,E;
int query;
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d %d",&V,&E);
        memset(d,0,sizeof(d));
        for(int i=0;i<E;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            d[a][b]=1;
            d[b][a]=-1;
        }
        for(int k=1;k<=V;k++)
            for(int i=1;i<=V;i++)
                for(int j=1;j<=V;j++)
                {
                    if(d[i][k]==1 && d[k][j]==1)
                        d[i][j]=1;
                    if(d[i][k]==-1 && d[k][j]==-1)
                        d[i][j]=-1;
                }
        int cnt=0;
        for(int i=1;i<=V;i++)
        {
            int cnt1=0,cnt2=0;
            for(int j=1;j<=V;j++)
            {
                if(d[i][j]==1)
                    cnt1++;
                if(d[i][j]==-1)
                    cnt2++;
            }
            if(cnt1>=V/2+1 || cnt2>=V/2+1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
