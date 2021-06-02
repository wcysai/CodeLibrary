#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",c[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(j==0) a[i][j]='1';
            else if((i&1)&&(j!=m-1)) a[i][j]='1';
            else a[i][j]='0';
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(j==m-1) b[i][j]='1';
            else if((!(i&1))&&(j!=0)) b[i][j]='1';
            else b[i][j]='0';
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(c[i][j]=='1') a[i][j]=b[i][j]='1';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
    return 0;
}