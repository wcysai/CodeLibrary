#include<bits/stdc++.h>
#define MAXN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN][MAXN],ans;
bool valid[MAXN];
void dfs(int now,int val)
{
    if(now==n+1)
    {
        ans=max(ans,val);
        return;
    }
    int st=-1;
    for(int i=1;i<=2*n;i++)
    {
        if(valid[i])
        {
            st=i;
            break;
        }
    }
    valid[st]=false;
    for(int j=st+1;j<=2*n;j++)
    {
        if(valid[j])
        {
            valid[j]=false;
            dfs(now+1,val^a[st][j]);
            valid[j]=true;
        }
    }
    valid[st]=true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        for(int j=i+1;j<=2*n;j++)
            scanf("%d",&a[i][j]);
    ans=0;
    memset(valid,true,sizeof(valid));
    dfs(1,0);
    printf("%d\n",ans);
}