#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,T;
vector<int> v;
P a[MAXN];
int dp[MAXN][40];
void upd(int &a,int b) {a=min(a,b);}
bool cmp(P x,P y)
{
    return 1LL*y.F*x.S+y.F<1LL*x.F*y.S+x.F;
}
int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==0) v.push_back(y);
        else
        {
            ++tot;
            a[tot].F=x; a[tot].S=y;
        }
    }
    sort(v.begin(),v.end());
    sort(a+1,a+tot+1,cmp);
    for(int i=0;i<=tot;i++)
        for(int j=0;j<40;j++) 
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<tot;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(dp[i][j]==INF) continue;
            upd(dp[i+1][j],dp[i][j]);
            if(1LL*a[i+1].F*(dp[i][j]+1)+dp[i][j]+1+a[i+1].S<=T) upd(dp[i+1][j+1],1LL*a[i+1].F*(dp[i][j]+1)+dp[i][j]+1+a[i+1].S);
        }
    }
    int ans=0;
    for(int j=0;j<40;j++)
    {
        if(dp[tot][j]<=T)
        {
            int cur=j;
            int now=dp[tot][j];
            for(auto x:v)
            {
                now+=x+1;
                if(now>T) break;
                cur++;
            }
            ans=max(ans,cur);
        }
    }
    printf("%d\n",ans);
    return 0;
}