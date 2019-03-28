#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 128
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,k,x[MAXN];
int a[MAXN][MAXM],dp[MAXN][MAXM],last[MAXN][MAXM],save[MAXN][MAXM];
void upd(int &a,int b) {a=min(a,b);}
vector<int> v;
int main()
{
    freopen("quant.in","r",stdin);
    freopen("quant.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    scanf("%d%d",&m,&s);
    for(int i=0;i<m;i++)
        for(int j=0;j<s;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<=n;i++) fill(dp[i],dp[i]+128,INF);
    dp[0][0]=0;
    memset(last,-1,sizeof(last));
    memset(save,-1,sizeof(save));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==INF) continue;
            for(int k=0;k<s;k++) 
            {
                if(dp[i][j]+abs(a[j][k]-x[i+1])<dp[i+1][k&(m-1)])
                {
                    dp[i+1][k&(m-1)]=dp[i][j]+abs(a[j][k]-x[i+1]);
                    last[i+1][k&(m-1)]=j;
                    save[i+1][k&(m-1)]=k;
                }
            }
        }
    }
    int ans=INF,id=-1;
    for(int k=0;k<m;k++)
    {
        if(dp[n][k]<ans)
        {
            ans=dp[n][k];
            id=k;
        }
    }
    printf("%d\n",ans);
    for(int i=n;i>=1;i--)
    {
        v.push_back(save[i][id]);
        id=last[i][id];
    }
    reverse(v.begin(),v.end());
    for(auto x:v) printf("%d ",x);
    return 0;
}

