#include<bits/stdc++.h>
#define MAXN 85
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 sdsad
#define y1 daskodas
#define x2 kddoas
#define y2 dksaodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P p[MAXN],tmp[MAXN];
int p2[MAXN];
int dp[MAXN][MAXN][2];
int cnt[MAXN][MAXN];//number of points inside a triangle
int dx,dy;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
//enumerate on the lower left point
//dp[i][j][k][0/1]: number of subsets of points s.t.
//we already go through i points
//current at jth
//last used is kth
//the area of hull is integer/not integer
ll cross(int x1,int y1,int x2,int y2)
{
    return 1LL*x1*y2-1LL*x2*y1;
}
bool cmp(P x,P y) //sort by angle w.r.t. (dx,dy)
{
    return cross(x.F-dx,x.S-dy,y.F-dx,y.S-dy)>0;
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=80;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].F,&p[i].S);
    sort(p,p+n);
    int ans=0;
    for(int i=0;i<n;i++)//choose i as the leftmost point
    {
        int m=n-i;
        for(int j=0;j<m;j++) tmp[j]=p[i+j];
        dx=tmp[0].F; dy=tmp[0].S;
        sort(tmp+1,tmp+m,cmp);
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<m;j++)
            for(int k=j+1;k<m;k++) //number of points in the triangle (i,j,k)
                for(int l=j+1;l<k;l++)
                    if(cross(tmp[j].F-tmp[l].F,tmp[j].S-tmp[l].S,tmp[k].F-tmp[l].F,tmp[k].S-tmp[l].S)>0) cnt[j][k]++;
        memset(dp,0,sizeof(dp));
        for(int j=1;j<m;j++) dp[0][j][0]++; //initial edge (i,j)
        for(int j=0;j<m;j++)
            for(int k=j+1;k<m;k++)
                for(int par=0;par<2;par++)
                {
                    if(!dp[j][k][par]) continue;
                    for(int l=k+1;l<m;l++)
                    {
                        if(cross(tmp[k].F-tmp[j].F,tmp[k].S-tmp[j].S,tmp[l].F-tmp[k].F,tmp[l].S-tmp[k].S)>0)
                        {
                            ll npar=cross(tmp[k].F-tmp[0].F,tmp[k].S-tmp[0].S,tmp[l].F-tmp[0].F,tmp[l].S-tmp[0].S)&1;
                            add(dp[k][l][par^npar],1LL*dp[j][k][par]*p2[cnt[k][l]]%MOD);
                        }
                    }
                }
        for(int j=1;j<m;j++)
            for(int k=j+1;k<m;k++)
                add(ans,dp[j][k][0]);
    }
    printf("%d\n",ans);
    return 0;
}
