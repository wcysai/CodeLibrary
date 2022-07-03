#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN];
string str;
int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={1,-1,-1,0,1,-1,0,1};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        for(int j=1;j<=n;j++) a[i][j]=str[j-1]-'0';
    }
    ll ans=0;
    int x=0,y=0,dir=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            for(int ndir=0;ndir<8;ndir++)
            {
                int nx=i,ny=j;
                ll sum=0;
                for(int k=0;k<n;k++)
                {
                    sum=10LL*sum+a[nx][ny];
                    nx+=dx[ndir]; if(nx<=0) nx+=n; if(nx>n) nx-=n;
                    ny+=dy[ndir]; if(ny<=0) ny+=n; if(ny>n) ny-=n;
                }
                if(sum>ans) ans=sum;
            }
        }
    printf("%lld\n",ans);
    return 0;
}

