#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN];
int comb[2*MAXN][2*MAXN];
vector<P> pos[MAXN*MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int get_ans(P x,P y)
{
    if(x.F>y.F) swap(x,y);
    if(x.S>y.S) return 0;
    return comb[y.F-x.F+y.S-x.S][y.F-x.F];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            pos[a[i][j]].push_back(P(i,j));
        }
    comb[0][0]=1;
    for(int i=1;i<=800;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=0;j<i;j++) {comb[i][j]=comb[i-1][j-1]; add(comb[i][j],comb[i-1][j]);}
    }
    int ans=n*n;
    for(int i=1;i<=n*n;i++)
    {
        if(pos[i].size()<=n)
        {
            for(int j=0;j<(int)pos[i].size();j++)
                for(int k=j+1;k<(int)pos[i].size();k++)
                    add(ans,get_ans(pos[i][j],pos[i][k]));
        }
        else
        {
            for(int j=n;j>=1;j--)
                for(int k=n;k>=1;k--)
                {
                    if(j==n) dp[j][k]=0; else dp[j][k]=dp[j+1][k];
                    if(k!=n) {add(dp[j][k],dp[j][k+1]);}
                    if(a[j][k]==i) {add(ans,dp[j][k]); add(dp[j][k],1);}
                }
        }
    }
    printf("%d\n",ans);
    return 0;
}

