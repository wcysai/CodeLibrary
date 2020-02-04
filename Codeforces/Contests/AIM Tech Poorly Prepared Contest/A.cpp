#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
P row[MAXN],col[MAXN];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        row[i]=P(-INF,0);
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>row[i].F) row[i]=P(a[i][j],1);
            else if(a[i][j]==row[i].F) row[i].S++;
        }
    }    
    for(int i=1;i<=m;i++)
    {
        col[i]=P(INF,0);
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]<col[i].F) col[i]=P(a[j][i],1);
            else if(a[j][i]==col[i].F) col[i].S++;
        }
    }
    int x=0,y=0;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            if(a[i][j]==row[i].F&&a[i][j]==col[j].F&&row[i].S==1&&col[j].S==1)
            {
                x=i;
                y=j;
            }
        }
    printf("%d %d\n",x,y);
    return 0;
}