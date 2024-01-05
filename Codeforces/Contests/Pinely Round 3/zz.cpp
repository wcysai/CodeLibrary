#include<bits/stdc++.h>
using namespace std;
using s64 = long long;
bool vis[26];
vector<int> ans[26];
void init() {
    for(int n = 1; n <= 24; n++) {
        int to = n / 5;
        for(int S = 1; S < (1 << n); S++) {
            fill(vis, vis + 1 + n, 0);
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if((S >> i) & 1) {
                    for(int j = i + 1; j <= n; j += i + 1) vis[j] ^= 1;
                }
                if(vis[i + 1]) cnt++;
                if(cnt > to) break;
            }
            if(cnt <= to) ans[n].push_back(S);
        }
    }
}
constexpr int MN = 2e5 + 5;
int n, m, a[MN];
int SS[MN];
void solve() {
    cin >> n >> m;
    fill(SS, SS + 27, 0);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(n < 25) {
            SS[u - 1] |= (1 << (v - 1));
        }
    }
    if(n >= 25) {
        cout << n << '\n';
        for(int i = 1; i <= n; i++) cout << i << " \n"[i == n];
        return;
    }
    for(int x : ans[n]) {
        bool flag = 1;
        for(int i = 0; i < n; i++) {
            if((x >> i) & 1 ^ 1) continue;
            if((SS[i] & x) != SS[i]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            vector<int> Ans;
            for(int i = 0; i < n; i++) {
                if((x >> i) & 1) Ans.push_back(i + 1);
            }
            cout << Ans.size() << '\n';
            for(int y : Ans)
                cout << y << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    int TT = 1;
    cin >> TT;
    for( ;TT--; ) {
        solve();
    }
}
