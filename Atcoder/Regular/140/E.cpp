#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int table[MAXN][MAXN];
int main()
{
    for(int i=0;i<23;i++)
        for(int j=0;j<23;j++)
        {
            int stx=i*23,sty=j*23;
            for(int x=0;x<23;x++)
                for(int y=0;y<23;y++)
                    table[stx+x][sty+y]=(x*j+y+i)%23+1;
        }
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) printf("%d ",table[i][j]);
        puts("");
    }
    return 0;
}

