// F
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)

const int MAXN = 20005;

int n, c;
int wt[MAXN];
int _dp[2][MAXN * 2 + 1];

inline
int& dp(int x, int y) {
    return _dp[x&1][y - c + MAXN];
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &c);
        Rep (i, n) scanf("%d", wt + i);
        int totw = 0, ptr;
        for (ptr = 1; ptr <= n; ptr++) {
            totw += wt[ptr];
            if (totw > c) break;
        }
        if (totw <= c) {
            printf("%d\n", totw);
            continue;
        }
        memset(_dp, 0, sizeof _dp);
       // for(int w = c +MAXN-1; w>=c;w--) dp(ptr-1,w)=1;
        dp(ptr-1, totw - wt[ptr]) = ptr;
        for (int t = ptr; t <= n; t++) {
            memset(_dp[t&1], 0, sizeof _dp[0]);
            for(int w=c-MAXN+1;w<=c+MAXN;w++) dp(t,w)=dp(t-1,w);
            // balanced adding
            for (int w = c - MAXN+1; w <= c; w++)
            {
                dp(t, w) = max(dp(t,w), dp(t-1,w));
                dp(t, w + wt[t]) = max(dp(t-1, w), dp(t, w + wt[t]));
            }
            // balanced deleting
            for (int w = c + MAXN; w > c; w--)
            {
                for (int j = dp(t, w)-1 ; j >= dp(t-1, w); j--)
                    dp(t, w - wt[j]) = max(dp(t, w - wt[j]), j);
            }
            //for(int w= c-MAXN+1;w<=c+MAXN;w++) printf("%d %d %d\n",t,w,dp(t,w));
        }
        for (totw = c; dp(n, totw) == 0; totw--); // cout << totw << ' ' << dp(n, totw) << endl;
        printf("%d\n", totw);
    }
}
