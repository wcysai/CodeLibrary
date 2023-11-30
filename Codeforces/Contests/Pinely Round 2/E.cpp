#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN],h[MAXN],ideg[MAXN];
vector<int> G[MAXN];
int dp[MAXN];
int color[MAXN];
vector<int> order;
int num[MAXN];
multiset<ll> ms;
ll ans;
vector<int> tmp;
bool cmp(int x,int y){
    return h[x]<h[y];
}
void dfs_visit(int v){
	color[v]=1;
	for(int i=0;i<G[v].size();i++){
		int to=G[v][i];
		if(color[to]==0)
			dfs_visit(to);
	}
	color[v]=2;
	order.push_back(v);
}
void toposort()
{
    order.clear();
	for(int i=1;i<=n;i++) color[i]=0;
    for(int i=1;i<=n;i++)
		if(color[i]==0)
			dfs_visit(i);
    reverse(order.begin(),order.end());
    for(int i=0;i<n;i++) num[order[i]]=i;
}
void update(int v){
    priority_queue<int,vector<int>,greater<int> > pque;
    dp[v]=1; ms.erase(ms.find(h[v])); ms.insert(k+h[v]);
    pque.push(num[v]);
    while(pque.size()){
        int id=pque.top(); pque.pop();
        int v=order[id];
        //printf("v=%d\n",v);
        for(auto to:G[v]){
            int z=(h[to]>=h[v]?dp[v]:dp[v]+1);
            if(dp[to]<z){
                ms.erase(ms.find(1LL*dp[to]*k+h[to])); ms.insert(1LL*z*k+h[to]);
                dp[to]=z; pque.push(num[to]);
            }
        }
    }
    ans=min(ans,*(--ms.end())-*ms.begin());
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++) ideg[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); ideg[v]++;
        }
        toposort();
        //puts("done");
        tmp.clear();
        for(int i=1;i<=n;i++) if(ideg[i]==0) tmp.push_back(i);
        sort(tmp.begin(),tmp.end(),cmp);
        for(int i=1;i<=n;i++) dp[i]=0;
        ms.clear();
        for(auto x:order)
            for(auto to:G[x])
                dp[to]=max(dp[to],(h[to]>=h[x]?dp[x]:dp[x]+1));
        for(int i=1;i<=n;i++){
            ms.insert(1LL*dp[i]*k+h[i]);
        }
        ans=*(--ms.end())-*ms.begin();
        for(int i=0;i<(int)tmp.size()-1;i++){
            update(tmp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

