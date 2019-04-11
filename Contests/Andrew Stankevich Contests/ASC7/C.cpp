#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3001
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],tot;
unordered_map<int,short> mp;
short dp[MAXN][MAXN];
vector<short> v;
int main()
{
    freopen("fibsubseq.in","r",stdin);
    freopen("fibsubseq.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==1)
    {
        printf("%d\n%d\n",1,a[1]);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int dif=a[j]-a[i];
            if(!mp[dif]) {dp[i][j]=2; continue;}
            dp[i][j]=dp[mp[dif]][i]+1;
        }
        mp[a[i]]=i;
    }
    int ans=0,x=-1,y=-1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dp[i][j]>ans)
            {
                ans=dp[i][j];
                x=i; y=j;
            }
    printf("%d\n",ans);
    v.push_back(y); v.push_back(x);
    while(dp[x][y]>2)
    {
        int cur=x-1;
        while(a[cur]!=a[y]-a[x]) cur--;
        v.push_back(cur);
        y=x; x=cur;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i++) printf("%d ",a[v[i]]);
    return 0;
}
