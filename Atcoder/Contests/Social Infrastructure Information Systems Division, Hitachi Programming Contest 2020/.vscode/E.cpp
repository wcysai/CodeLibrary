#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
#define x1 dsamjodka
#define y1 dsajkid
#define x2 dsakosd
#define y2 asjdaiodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[10][10],s[10][10];
int best[10][10];
void compute_prefix_sum()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]+=s[i][j-1];
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]+=s[i-1][j];
}
int get(int x1,int y1,int x2,int y2)
{
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<n)-1;i++)
    {
        for(int j=0;j<(1<<m)-1;j++)
        {
            if((i==(1<<(n-1))-1)&&(j==(1<<(m-1))-1)) printf("0");
            else printf("1");
        }
        puts("");
    }
    return 0;
}