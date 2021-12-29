#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
#define x1 daslod
#define y2 dakodsa
#define y1 dsakod
#define x2 ckaoc
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,dp[2][2],ndp[2][2];
int a[2],b[2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&a[0],&a[1]); scanf("%d%d",&b[0],&b[1]);
    int x=(a[0]==b[0]?1:0),y=(a[1]==b[1]?1:0);
    dp[x][y]=1;
    for(int i=0;i<k;i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int x=0;x<2;x++)
            for(int y=0;y<2;y++)
            {
                //move row
                if(x==1) add(ndp[0][y],1LL*dp[x][y]*(n-1)%MOD);
                else {add(ndp[0][y],1LL*dp[x][y]*(n-2)%MOD); add(ndp[1][y],dp[x][y]);}
                if(y==1) add(ndp[x][0],1LL*dp[x][y]*(m-1)%MOD);
                else {add(ndp[x][0],1LL*dp[x][y]*(m-2)%MOD); add(ndp[x][1],dp[x][y]);}
            }
        swap(ndp,dp);
    }
    printf("%d\n",dp[1][1]);
    return 0;
}