#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef bitset<202> bs;
int t,n,k;
int l[MAXN],r[MAXN],c[MAXN];
vector<int> dis;
vector<P> rect;
bs has[MAXN][MAXN];
int cnt[MAXN][MAXN],cc[MAXN][MAXN];
vector<int> color[MAXN][MAXN];
int dp[2][MAXN][MAXK];
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        dis.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&l[i],&r[i],&c[i]);
            dis.push_back(l[i]); dis.push_back(r[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        rect.clear();
        for(int i=1;i<=n;i++)
        {
            l[i]=lower_bound(dis.begin(),dis.end(),l[i])-dis.begin()+1;
            r[i]=lower_bound(dis.begin(),dis.end(),r[i])-dis.begin()+1;
           // printf("%d %d %d\n",i,l[i],r[i]);
            rect.push_back(P(r[i],l[i]));
        }
        int sz=(int)dis.size();
        for(int i=1;i<=sz;i++)
            for(int j=1;j<=sz+1;j++)
                color[i][j].clear(),has[i][j].reset();
        for(int i=1;i<=n;i++) color[l[i]][r[i]].push_back(c[i]);
        for(int i=1;i<=sz;i++)
            for(int j=sz;j>=1;j--)
            {
                has[i][j]=has[i-1][j]|has[i][j+1];
                for(auto x:color[i][j]) has[i][j].set(x);
                cnt[i][j]=has[i][j].count()-has[i][j].test(0);
                if(cnt[i][j]) cc[i][j]=has[i][j]._Find_next(0);
               // printf("%d %d %d %d\n",i,j,cnt[i][j],cc[i][j]);
            }
        sort(rect.begin(),rect.end(),greater<P>());
        memset(dp,0,sizeof(dp));
        for(int i=0;i<(int)rect.size();i++)
        {
            int now=i&1,nxt=now^1;
            for(int j=1;j<=sz;j++)
                for(int k=0;k<=200;k++)
                    dp[nxt][j][k]=0;
            for(int j=1;j<=sz;j++)
            {
                int x=rect[i].F,y=rect[i].S;
                //printf("x=%d y=%d\n",x,y);
                for(int k=0;k<=200;k++)
                {
                   // if(dp[now][j][k])printf("%d %d %d %d\n",i,j,k,dp[now][j][k]);
                    upd(dp[nxt][j][k],dp[now][j][k]);
                    if(cnt[x][y]>=2) continue;
                    bool any=(cnt[x][y])||(has[x][y].test(0));
                    bool colored=(cnt[x][j]||(has[x][j].test(0)));
                    if(colored&&k)
                    {
                        if(!cnt[x][y]) upd(dp[nxt][any?min(j,y):j][k],dp[now][j][k]+1);
                        else if(cc[x][y]==k) upd(dp[nxt][min(j,y)][k],dp[now][j][k]+1);
                    }
                    else
                    {
                        if(!cnt[x][y])
                        {
                            if(!any) upd(dp[nxt][j][k],dp[now][j][k]+1);
                            else
                            {
                                for(int newcolor=1;newcolor<=200;newcolor++) upd(dp[nxt][y][newcolor],dp[now][j][k]+1);
                            }
                        }
                        else upd(dp[nxt][y][cc[x][y]],dp[now][j][k]+1);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=sz;i++)
            for(int j=0;j<=200;j++)
                ans=max(ans,dp[(int)rect.size()&1][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
