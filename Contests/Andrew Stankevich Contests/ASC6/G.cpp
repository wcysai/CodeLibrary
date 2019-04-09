#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN][MAXN];
int dx1[6]={0,0,0,1,0,1};
int dy1[6]={1,-1,1,1,-1,1};
int dx2[6]={0,0,-1,0,-1,0};
int dy2[6]={1,-1,-1,-1,-1,1};
bool go(int x,int y,int dir)
{
    if(y&1)
    {
        int nx=x+dx2[dir],ny=y+dy2[dir];
        if(nx>=0&&nx<n&&ny>=0&&ny<=2*nx&&str[nx][ny]=='1') return false;
        return true;
    }
    else
    {
        int nx=x+dx1[dir],ny=y+dy1[dir];
        if(nx>=0&&nx<n&&ny>=0&&ny<=2*nx&&str[nx][ny]=='1') return false;
        return true;
    }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int tot=0;
    while(scanf("%d",&n)==1)
    {
        tot++;
        if(n==0) break;
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        bool f=false;
        for(int i=0;i<6;i++)
        {
            bool flag=true;
            for(int j=0;j<n;j++)
                for(int k=0;k<=2*j;k++)
                    if(str[j][k]=='0') flag=flag&&go(j,k,i);
            if(flag)
            {
                f=true;
                break;
            }
        }
        printf("Puzzle %d\n",tot);
        if(f) puts("Parts can be separated\n"); else puts("Parts cannot be separated\n");
    }
    return 0;
}
