#include<bits/stdc++.h>
#define MAXN 20
#define MAXM (1<<19)
using namespace std;
int n;
int dp[MAXM],tot;
vector<int> ans[MAXN];
bool has[1005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<(1<<n);i++) scanf("%d",&dp[i]);
    int sz=(int)dp[(1<<n)-1];
    for(int i=0;i<(1<<n);i++) dp[i]=sz-dp[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            if(!(j&(1<<i)))
                dp[j]-=dp[j^(1<<i)];
    bool f=true;
    for(int i=0;i<(1<<n);i++)
    {
        if(dp[i]<0) f=false;
        for(int j=0;j<dp[i];j++)
        {
            ++tot;
            for(int k=0;k<n;k++)
            {
                if(i&(1<<k))
                {
                    ans[k+1].push_back(tot);
                }
            }
        }
    }
    if(tot!=sz) f=false;
    if(!f){puts("No"); return 0;}
    puts("Yes");
    for(int i=1;i<=n;i++)
    {
        memset(has,false,sizeof(has));
        for(auto x:ans[i]) has[x]=true;
        ans[i].clear();
        for(int j=1;j<=sz;j++) if(!has[j]) ans[i].push_back(j);
        printf("%d",(int)ans[i].size());
        for(auto x:ans[i]) printf(" %d",x);
        puts("");
    }
}
