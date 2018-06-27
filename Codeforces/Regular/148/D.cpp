#include<bits/stdc++.h>
#define MAXN 50
#define MAXM 50
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char mp[MAXN][MAXM],rmp[MAXN][MAXM];
char nmp[2][MAXN][MAXM];
int sg[2][MAXN][MAXN][MAXN][MAXN];
int n,m;
int grundy(int p,int a,int b,int c,int d)
{
    if(a>c||b>d||a<0||b<0||c<0||d<0||a>=n+m-1||b>=n+m-1||c>=n+m-1||d>=n+m-1) return 0;
    if(sg[p][a][b][c][d]>=0) return sg[p][a][b][c][d];
    int s[200]={0};
    for(int i=a;i<=c;i++)
        for(int j=b;j<=d;j++)
        {
            if(nmp[p][i][j]=='L')
            {
                int x=grundy(p,a,b,i-1,d)^grundy(p,i+1,b,c,d);
                s[x]++;
            }
            else if(nmp[p][i][j]=='R')
            {
                int x=grundy(p,a,b,c,j-1)^grundy(p,a,j+1,c,d);
                s[x]++;
            }
            else if(nmp[p][i][j]=='X')
            {
                int x=grundy(p,a,b,i-1,j-1)^grundy(p,a,j+1,i-1,d)^grundy(p,i+1,b,c,j-1)^grundy(p,i+1,j+1,c,d);
                s[x]++;
            }
            else continue;
        }
    int g=0;
    while (s[g]) g++;
    return sg[p][a][b][c][d]=g;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXM;j++)
            rmp[i][j]=' ';
    for(int k=0;k<=n+m-2;k++)
    {
        for(int i=max(0,k-m+1);i<=min(n-1,k);i++)
        {
            int j=k-i;
            int l=k==n-1?0:max(n-1-k,k-n+1);
            int r=l+(min(n-1,k)-i)*2;
            rmp[k][r]=mp[i][j];
        }
    }
    for(int i=0;i<n+m-1;i++)
        for(int j=0;j<n+m-1;j++)
          nmp[0][i][j]=nmp[1][i][j]=' ';
    int a=0,b=0;
    for(int i=0;i<n+m-1;i++)
    {
        int id=0;
        for(int j=0;j<n+m-1;j++)
        {
            if(rmp[i][j]!=' ')
            {
                if(i%2==0) {nmp[0][a][id]=rmp[i][j]; id++;}
                else {nmp[1][b][id]=rmp[i][j]; id++;}
            }
        }
        if(i%2==0) a++; else b++;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%c",nmp[0][i][j]);
        printf("\n");
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%c",nmp[1][i][j]);
        printf("\n");
    }
    memset(sg,-1,sizeof(sg));
    int x=grundy(0,0,0,n+m-2,n+m-2);
    x=grundy(1,0,0,n+m-2,n+m-2);
    printf("%d %d\n",sg[0][0][0][n+m-2][n+m-2],sg[1][0][0][n+m-2][n+m-2]);
    printf((sg[0][0][0][n+m-2][n+m-2]^sg[1][0][0][n+m-2][n+m-2])==0?"LOSE\n":"WIN\n");
    return 0;
}
