#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,K;
string str;
int dp[MAXN][5][2],ndp[MAXN][5][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&K);
    n--;
    cin>>str;
    memset(dp,0,sizeof(dp));
    if(str[0]!='B') dp[1][1][0]=1; //(1,0)
    if(str[0]!='A') dp[0][3][1]=1; //(0,1)
    for(int t=1;t<n;t++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int i=0;i<=t;i++)
        {
            for(int j=0;j<5;j++)
            {
                for(int k=0;k<2;k++)
                {
                    if(!dp[i][j][k]) continue;
                    for(int l=0;l<2;l++)
                    {
                        if(l==0&&str[t]=='B') continue;
                        if(l==1&&str[t]=='A') continue;
                        if(k==0&&l==0) 
                        {
                            if(j==0) add(ndp[i][j][k],dp[i][j][k]);
                            else add(ndp[i+1][j-1][k],dp[i][j][k]);
                        }
                        if(k==1&&l==1)
                        {
                            if(j==4) add(ndp[i][j][k],dp[i][j][k]);
                            else add(ndp[i][j+1][k],dp[i][j][k]);
                        }
                        if(k==0&&l==1)
                        {
                            int x=i,y=i+(j-2),nx,ny;
                            ny=min(x+1,y+1); nx=min(x,ny+1);
                            assert(ny<=nx+2&&ny>=nx-2);
                            add(ndp[nx][2+ny-nx][1],dp[i][j][k]);
                        }
                        if(k==1&&l==0)
                        {
                            int x=i,y=i+(j-2),nx,ny;
                            nx=min(x+1,y+1); ny=min(y,nx+1);
                            assert(ny<=nx+2&&ny>=nx-2);
                            add(ndp[nx][2+ny-nx][0],dp[i][j][k]);
                        }
                    }
                }
            }
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<=K+1;i++)
        for(int j=0;j<5;j++)
            for(int k=0;k<2;k++)
            {
                int x=i,y=i+(j-2),val=min(x,y)+1;
                if(val<=K) add(ans,dp[i][j][k]);
            }
    printf("%d\n",ans);
    return 0;
}