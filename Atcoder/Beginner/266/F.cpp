#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> f;

    DSU(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int leader(int x) {
        return x == f[x] ? x : f[x] = leader(f[x]);
    }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if(x == y) return false;
        f[y] = x;
        return true;
    }
};

int n;

int main(){
    cin >> n;
    vector adj(n + 1, vector<int>());
    vector<int> cnt(n + 1);
    vector<pair<int, int> > edge;
    for (int i = 1; i <= n; i += 1) {
        int x, y;
        cin >> x >> y;
        edge.emplace_back(x, y);
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        cnt[x] += 1;
        cnt[y] += 1; 
    }
    vector<int> vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i += 1) {
        if(cnt[i] == 1) q.emplace(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto v : adj[u]) {
            --cnt[v];
            if(cnt[v] == 1) q.emplace(v);
        }
    }
    DSU dsu(n + 1);
    for (auto [x, y] : edge) {
        if(vis[x] or vis[y]) {
            dsu.merge(x, y);
        }

    }
    int _;
    cin >> _;
    while(_--) {
        int x, y;
        cin >> x >> y;
        cout << (dsu.leader(x) == dsu.leader(y) ? "Yes" : "No") << "\n";
    }
    return 0;
}
