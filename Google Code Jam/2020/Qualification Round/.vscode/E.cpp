#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int res[MAXN];
int ans[MAXN][MAXN];
vector<int> G[2*MAXN];
int match[2*MAXN];
bool used[2*MAXN];
bool validr[MAXN],validc[MAXN];
int cnt[MAXN];
int ord[MAXN];
bool cmp(int x,int y)
{
    return cnt[x]>cnt[y];
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=n;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d",&n,&k);
        memset(cnt,0,sizeof(cnt));
        printf("Case #%d: ",_);
        if(k==n+1||k==n*n-1) {puts("IMPOSSIBLE"); continue;}
        if(n==3&&k==5) {puts("IMPOSSIBLE"); continue;}
        if(n==3&&k==7) {puts("IMPOSSIBLE"); continue;}
        for(int i=1;i<=n;i++) res[i]=1,k--;
        for(int i=n;i>=1;i--)
        {
            int x=min(n-1,k);
            res[i]+=x; k-=x;
        }
        if(res[n-1]==1&&res[n]!=1) {res[n]--; res[n-1]++;}
        else if(res[2]==n&&res[1]!=n) {res[1]++; res[2]--;}
        puts("POSSIBLE");
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++) ans[i][i]=res[i];
        for(int i=1;i<=n;i++) cnt[res[i]]++;
        for(int i=1;i<=n;i++) ord[i]=i;
        sort(ord+1,ord+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            memset(validr,true,sizeof(validr));
            memset(validc,true,sizeof(validc));
            int cnt=n;
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(ans[j][k]==ord[i]) {validr[j]=validc[k]=false; cnt--;}
            for(int j=1;j<=2*n;j++) G[j].clear();
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                {
                    if(!validr[j]||!validc[k]) continue;
                    if(!ans[j][k]) add_edge(j,n+k);
                }
            assert(bipartite_matching()==cnt);
            for(int j=1;j<=n;j++) if(validr[j]) ans[j][match[j]-n]=ord[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
                printf("%d%c",ans[i][j],j==n?'\n':' ');
    }
    return 0;
}