#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define MAXQ 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
bitset<2001> b[MAXN],adj[MAXN];
vector<int> out[MAXN],in[MAXN],G[MAXN];
int s[MAXQ],t[MAXQ],ans[MAXQ];
bool vis[MAXN];
int si;
bool f;
int read(){
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
void dfs(int v){
    if(v==si) f=true;
    if(f) return;
    vis[v]=true;
    for(auto to:G[v]){
        if(!vis[to]) dfs(to);
    }
}
bool check(int s,int t){
    memset(vis,false,sizeof(vis));
    si=t; f=false;
    dfs(s); return f;
}
void solve(int l,int r,vector<int> &qry){
    if(!qry.size()||l>r) return;
    if(l==r) {
        for(auto id:qry) ans[id]=l;
        return;
    }
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++){
        for(auto x:in[i]) G[x].push_back(i);
        for(auto x:out[i]) G[i].push_back(x);
    }
    vector<int> lhs,rhs;
    for(auto id:qry){
        if(check(s[id],t[id])) lhs.push_back(id); else rhs.push_back(id);
    }
    solve(mid+1,r,rhs);
    for(int i=l;i<=mid;i++){
        for(int j=(int)in[i].size()-1;j>=0;j--) G[in[i][j]].pop_back();
        for(auto x:out[i]) G[i].pop_back();
    }
    solve(l,mid,lhs);
}
int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) adj[i].set(i);
    for(int i=0;i<m;i++){
        int u,v; u=read(); v=read();
        adj[u].set(v);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) {s[i]=read(); t[i]=read(); ans[i]=-1;}
    for(int i=1;i<=n;i++){
        b[i]=adj[i];
        for(int u=1;u<=i;u++) if(b[i][u]) b[i]|=b[u];
        for(int u=1;u<=i;u++) if(b[u][i]) b[u]|=b[i];
        for(int j=0;j<q;j++) if(s[j]<=i&&t[j]<=i&&ans[j]==-1&&b[s[j]][t[j]]) ans[j]=i;
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

