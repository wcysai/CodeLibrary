#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)
#ifdef __LOCAL_DEBUG__
#define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, ##__VA_ARGS__);
#else
#define _debug(...) ((void) 0)
#endif
typedef long long LL;
typedef unsigned long long ULL; 
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt;
string str[MAXN];
struct edge
{
    int to,cost;
};
vector<edge> G[MAXN];
typedef pair<LL, int> pii;
struct MDST 
{
    priority_queue<pii, vector<pii>, greater<pii>> heap[MAXN];
    LL shift[MAXN];
    int fa[MAXN], vis[MAXN];

    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    
    void unite(int x, int y) 
    {
        x = find(x); y = find(y); fa[y] = x; if (x == y) return;
        if (heap[x].size() < heap[y].size()) 
        { 
            swap(heap[x], heap[y]); 
            swap(shift[x], shift[y]); 
        }
        while (heap[y].size()) 
        {
            auto p = heap[y].top(); heap[y].pop();
            heap[x].emplace(p.first - shift[y] + shift[x], p.second);
        }
    }
    
    void add_edge(int u, int v, LL w) { heap[v].emplace(w, u); }
    
    LL run(int n, int rt) 
    {
        LL ans = 0;
        iota(fa, fa + n + 1, 0);
        Rep (i, n) if (find(i) != find(rt)) 
        {
            int u = find(i);
            stack<int, vector<int>> s;
            while (find(u) != find(rt)) 
            {
                if (vis[u]) while (s.top() != u) 
                { 
                    vis[s.top()] = 0; unite(u, s.top()); s.pop(); 
                } else { vis[u] = 1; s.push(u); }
                while (heap[u].size()) 
                {
                    int w=heap[u].top().first, v=heap[u].top().second;
                    ans += heap[u].top().first - shift[u];
                    shift[u] = heap[u].top().first;
                    if (find(heap[u].top().second) != u) break;
                    heap[u].pop();
                }
                if (heap[u].empty()) return LLONG_MIN;
                int w=heap[u].top().first, v=heap[u].top().second;
                G[u].push_back((edge){v,w});
                G[v].push_back((edge){u,w});
                cnt++;
                u = find(heap[u].top().second);
            } 
            while (s.size()) { vis[s.top()] = 0; unite(rt, s.top()); s.pop(); }
        }
        return ans;
    }
} mdst;
int tot=0;
int id[MAXN];
void dfs(int v,int p,int w)
{
    if(w) id[v]=++tot; else id[v]=id[p];
    if(v==1) puts("0");
    else if(w) printf("%d %c\n",id[p],str[v-1].back());
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,e.cost);
    }
}
int main()
{
    scanf("%d",&n);
    vector<string> vv;
    for(int i=1;i<=n;i++) 
    {
        string ss;
        cin>>ss;
        for(int j=1;j<=(int)ss.size();j++) vv.push_back(ss.substr(0,j));
    }
    n=(int)vv.size();
    for(int i=1;i<=n;i++) str[i]=vv[i-1];
    for(int i=1;i<=n;i++) 
    {
        if(str[i].size()==1) mdst.add_edge(1,i+1,1);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            int sz1=(int)str[i].size(),sz2=(int)str[j].size();
            if(sz2==sz1+1&&str[j].substr(0,sz1)==str[i].substr(0,sz1)) mdst.add_edge(i+1,j+1,1);
            if(sz1>=sz2&&str[i].substr(sz1-sz2,sz2)==str[j]) mdst.add_edge(i+1,j+1,0);
        }
    printf("%lld\n",mdst.run(n+1,1)+1);
    printf("cnt=%d\n",cnt);
    //dfs(1,0,1);
    return 0;
}

