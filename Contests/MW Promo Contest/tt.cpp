# include <queue>
# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
// # include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int M = 3e5 + 10;
const int mod = 1e9+7;

# define RG register
# define ST static

int n;

int S, T, d[M];
int head[M], nxt[M], to[M], flow[M], w[M], tot=1;
inline void add(int u, int v, int fl, int _w) {
    ++tot; nxt[tot] = head[u]; head[u] = tot;
    to[tot] = v; flow[tot] = fl; w[tot] = _w;
}
inline void adde(int u, int v, int fl, int _w) {
//    printf("%d->%d, %d, cost = %d\n", u, v, fl, _w);
    add(u, v, fl, _w);
    add(v, u, 0, -_w);
}

namespace MCF {
    queue<int> q;
    int dis[M], pre[M];
    bool vis[M];
    inline bool spfa() {
        while(!q.empty()) q.pop();
        for (int i=1; i<=n+2; ++i) vis[i] = 0, dis[i] = 1e9, pre[i] = 0;
        q.push(S); vis[S] = 1; dis[S] = 0;
        while(!q.empty()) {
            int top = q.front(); q.pop(); vis[top] = 0;
            for (int i=head[top]; i; i=nxt[i]) {
                if(flow[i] && dis[to[i]] > dis[top] + w[i]) {
                    dis[to[i]] = dis[top] + w[i];
                    pre[to[i]] = i;
                    if(!vis[to[i]]) {
                        vis[to[i]] = 1;
                        q.push(to[i]);
                    }
                }
            }
        }
//        for (int i=1; i<=n+2; ++i) cout << i << ' ' << d[i] << endl;
//        puts("");
        return dis[T] != 1e9;
    }
    inline int mcf() {
        int fl = 1e9, ans = 0;
        for (int i=pre[T]; i; i=pre[to[i^1]])
            fl = min(fl, flow[i]);
        for (int i=pre[T]; i; i=pre[to[i^1]]) {
            flow[i] -= fl;
            flow[i^1] += fl;
            ans += fl * w[i];
        }
        return ans;
    }
    inline int main() {
        int ret = 0;
        while(spfa()) ret += mcf();
        return ret;
    }
}

int main() {
    int ans = 0;
    cin >> n;
    S = n+1, T = n+2;
    for (int i=1, m, Bi, Ti; i<=n; ++i) {
        scanf("%d", &m);
        for (int j=1; j<=m; ++j) {
            scanf("%d%d", &Bi, &Ti);
            adde(i, Bi, 1e9, Ti);
            d[Bi] ++; d[i] --; ans += Ti;
        }
        if(i != 1) adde(i, 1, 1e9, 0);
    }
    
    for (int i=1; i<=n; ++i) {
        if(d[i] > 0) adde(S, i, d[i], 0);
        if(d[i] < 0) adde(i, T, -d[i], 0);
    }
    
    cout << MCF::main() + ans << endl;

    return 0;
}