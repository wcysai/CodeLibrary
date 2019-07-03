#include<bits/stdc++.h>
#define MAXN 25
#define MAXM 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,mask;
string str[MAXN];
string ans[200005][10];
int id[10];
bool vis[10];
bool valid[MAXM];
int comp[MAXM];
bool dfs(int now)
{
    if(now==n) return true;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        bool flag=true;
        for(int j=0;j<now;j++)
        {
            if(ans[comp[mask]][j][now]!=str[id[i]][j]) 
            {
                flag=false;
                break;
            }
        }
        if(!flag) continue;
        vis[i]=true;
        ans[comp[mask]][now]=str[id[i]];
        if(dfs(now+1)) return true;
        vis[i]=false;
    }
    return false;
}
bool solve()
{
    int tot=0;
    for(int i=0;i<2*n;i++)
    {
        if(mask&(1<<i)) id[tot++]=i; 
    }
    assert(tot==n);
    memset(vis,false,sizeof(vis));
    return dfs(0);
}
int main()
{
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) cin>>str[i];
    int nmask=(1<<(2*n));
    mask=(1<<n)-1;
    int cnt=0;
    while(mask<nmask)
    {
        comp[mask]=cnt++;
        valid[mask]=solve();
        int x=mask&-mask,y=mask+x;
        mask=((mask&~y)/x>>1)|y;
    }
    mask=(1<<n)-1;
    while(mask<nmask)
    {
        if(valid[mask]&&valid[(nmask-1)^mask])
        {
            for(int i=0;i<n;i++) cout<<ans[comp[mask]][i]<<endl;
            cout<<endl;
            for(int i=0;i<n;i++) cout<<ans[comp[(nmask-1)^mask]][i]<<endl;
            return 0;
        }
        int x=mask&-mask,y=mask+x;
        mask=((mask&~y)/x>>1)|y;
    }
    return 0;
}
