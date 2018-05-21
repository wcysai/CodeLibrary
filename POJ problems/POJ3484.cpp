#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
vector<long long> x, y, z;
char a[100];

bool read() {
    x.clear(); y.clear(); z.clear();
    bool have = false;
    while(gets(a)) {
        if(!strlen(a)) {
            if(have) break;
            else continue;
        }
        long long xx, yy, zz;
        sscanf(a, "%lld%lld%lld", &xx, &yy, &zz);
        have = true;
        x.push_back(xx);
        y.push_back(yy);
        z.push_back(zz);
    }
    n = x.size();
    return have;
}

long long calc(long long mid) {
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if(mid < x[i]) continue;
        long long t = min(mid, y[i]);
        sum += (t - x[i]) / z[i] + 1;
    }
    //cout<<sum<<endl;
    return sum;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(read()) {
        /*for(int i = 0; i < n; ++i) {
            cout << x[i] << ' ' << y[i] << ' ' << z[i] << endl;
        }
        cout << endl;*/

        long long l = 1, r = 1LL << 33;
        while(l < r) {
            long long mid = l + (r - l >> 1);
            if(calc(mid) & 1) r = mid;
            else l = mid + 1;
        }

        if(l == 1LL << 33) printf("no corruption\n");
        else printf("%lld %lld\n", l, calc(l) - calc(l - 1));
    }
    return 0;
}