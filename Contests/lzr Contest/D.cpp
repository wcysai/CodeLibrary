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
int n,m,tot,a[MAXN][MAXN];
bool swapped;
int main()
{
    scanf("%d%d",&n,&m);
    if(n>m) {swap(n,m); swapped=true;}
    puts("Yes");
    if(n==2)
    {
        if(m%4==0)
        {
            a[1][2]=++tot; a[1][1]=++tot; a[2][1]=++tot; a[2][2]=++tot;
            for(int i=1;i<=m/4-1;i++) 
            {
                a[1][2*i+1]=++tot; a[2][2*i+2]=++tot;
                a[2][2*i+1]=++tot; a[1][2*i+2]=++tot;
            }
            int last=2*(m/4-1)+3;
            for(int i=last;i<=m;i++) a[1][i]=++tot;
            for(int i=m;i>=last;i--) a[2][i]=++tot;
        }
        else
        {
            a[2][2]=++tot; a[2][1]=++tot; a[1][1]=++tot; a[1][2]=++tot;
            for(int i=1;i<=m/4-1;i++) 
            {
                a[1][2*i+1]=++tot; a[2][2*i+2]=++tot;
                a[2][2*i+1]=++tot; a[1][2*i+2]=++tot;
            }
            int last=2*(m/4-1)+3;
            a[1][last]=++tot; a[2][last]=++tot;
            for(int i=last+1;i<=m;i++) a[2][i]=++tot;
            for(int i=m;i>=last+1;i--) a[1][i]=++tot;
        }
    }
    else
    {

    }`
    if(swapped)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(i<j) swap(a[i][j],a[j][i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            printf("%d%c",a[i][j],j==m?'\n':' ');
    return 0;
}

