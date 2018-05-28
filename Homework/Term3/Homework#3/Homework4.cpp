#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define MAXN 105
#define INF 1000000000
using namespace std;
typedef long long ll;
ll d[MAXN][MAXN],pre[MAXN][MAXN],w[MAXN][MAXN],save[MAXN];
int n,m,cnt;
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(n==-1) break;
        scanf("%d",&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=d[j][i]=w[i][j]=w[j][i]=INF,pre[i][j]=i;
        for(int i=0;i<m;i++)
        {
            ll x,y,z;
            scanf("%lld %lld %lld",&x,&y,&z);
            d[x-1][y-1]=d[y-1][x-1]=w[x-1][y-1]=w[y-1][x-1]=min(d[x-1][y-1],z);
        }
        int ans=INF;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(d[i][j]+w[i][k]+w[k][j]<ans)
                    {
                        ans=d[i][j]+w[i][k]+w[k][j];
                        int t=j;
                        cnt=0;
                        while(t!=i)
                        {
                            save[cnt++]=t;
                            t=pre[i][t];
                        }
                        save[cnt++]=i;
                        save[cnt++]=k;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(d[i][k]+d[k][j]<d[i][j])
                    {
                        d[i][j]=d[i][k]+d[k][j];
                        pre[i][j]=pre[k][j];
                    }
                }
            }
        }
        if(ans==INF)
        {
            printf("No solution.\n");
            continue;
        }
        for(int i=0;i<cnt;i++)
            printf("%d ",save[i]+1);
        printf("\n");
    }
    return 0;
}
