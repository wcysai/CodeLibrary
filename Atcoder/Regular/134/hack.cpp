#include <bits/stdc++.h>
using namespace std;
 
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif
 
const int maxn = 2e5 + 233;
int a[maxn], n;
vector<pair<int, int> > s;
 
bool cmp1(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i += 1) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return true;
}
 
bool cmp2(vector<int> a, vector<int> b) {
    /*
    for (auto x : a) {
        debug(x);
    }
 
    for (auto x : b) {
        debug(x);
    }
    */
    for (int i = 0; i < b.size(); i += 1) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}
 
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; i += 1){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i += 1){
        while(!s.empty() && 
        cmp1(vector<int>{a[i], a[i + n]}, vector<int>{s.back().first, s.back().second}) && 
        cmp1(vector<int>{a[i], a[i + n]}, vector<int>{s.back().first, a[i], s.back().second, a[i + n]})
        ){
            s.pop_back();
        }
        if(s.empty() || cmp2(vector<int>{s.back().first, a[i], s.back().second, a[i + n]}, vector<int>{s.back().first, s.back().second})) {
            s.emplace_back(a[i], a[i + n]);
        }
    }
    for (auto [x, y] : s) {
        cout << x << " ";
    }
    for (auto [x, y] : s) {
        cout << y << " ";
    }
    cout << "\n";
    return 0;
}