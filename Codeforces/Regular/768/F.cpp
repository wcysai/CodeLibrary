#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,n1,n2;
int a[MAXN];
vector<int> H[MAXN];
vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool vis[MAXN];
int lab[MAXN];
void add_edge(int u,int v){
    H[u].push_back(v); H[n+u].push_back(n+v);
}
bool find(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1)
        {
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]]))
            {
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
int matching()
{
    for(int i=1;i<=n1+n2;i++) mx[i]=0;
    for(int i=1;i<=n1+n2;i++) my[i]=0;
    int ans=0;
    while(true)
    {
        bool flag=false;
        while(!que.empty()) que.pop();
        for(int i=1;i<=n1+n2;i++) dx[i]=0;
        for(int i=1;i<=n1+n2;i++) dy[i]=0;
        for(int i=1;i<=n1;i++)
            if(!mx[i]) que.push(i);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
                if(!dy[G[u][i]])
                {
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]])
                    {
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
        }
        if(!flag) break;
        for(int i=1;i<=n1+n2;i++) vis[i]=0;
        for(int i=1;i<=n1;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}
int min_chain_cover(int n){
    n1=n2=n;
    for(int i=1;i<=n;i++){
        for(auto to:H[i]){
            G[i].push_back(n+to);
            G[n+to].push_back(i);
        }
    }
    return n-matching();
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) H[i].clear();
        for(int i=1;i<=4*n;i++) G[i].clear();
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); lab[a[i]]=i;}
        for(int i=1;i<=n;i++) H[i].push_back(n+i);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=a[i];j++){
                if(a[i]%j) continue;
                if(j!=a[i]&&lab[j]) add_edge(lab[j],i);
                if(j!=1&&j*j!=a[i]&&lab[a[i]/j]) add_edge(lab[a[i]/j],i);
            }
        }
        for(int i=1;i<=n;i++) lab[a[i]]=0;
        printf("%d\n",n-min_chain_cover(2*n));
    }
    return 0;
}

