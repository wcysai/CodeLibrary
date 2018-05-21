#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

mat mult(mat &a, mat &b)
{
    int S = a.size();
    mat c(S, vec(S, 0));
    for (int i = 0; i < S; i ++) {
        for (int j = 0; j < S; j ++) {
            if (a[j][i]) {
                for (int k = 0; k < S; k ++) {
                    c[j][k] += a[j][i]*b[i][k];
                }
            }
        }
    }
    return c;
}

mat pow(mat &a, int k)
{
    int S = a.size();
    mat c(S, vec(S, 0));
    for (int i = 0; i < S; i ++)
        c[i][i] = 1;
    while (k) {
        if (k & 1) c = mult(c, a);
        k >>= 1;
        a = mult(a, a);
    }
    return c;
}

int main(void)
{
    int n, m, k;
    while (cin >> n >> m >> k) {
        if (!n && !m && !k) break;

        mat a(n+1, vec(n+1, 0));
        for (int i = 0; i < n; i ++)
            a[i][i] = 1;
        a[n][n] = 1;

        while (k--) {
            char s[2];
            int x, y;
            scanf("%s", s);
            scanf("%d", &x);
            x --;

            if (s[0] == 'g') {
                a[n][x] ++;
            }
            else if (s[0] == 'e') {
                for (int i = 0; i <= n; i ++)
                    a[i][x] = 0;
            }
            else {
                scanf("%d", &y);
                y --;
                for (int i = 0; i <= n; i ++)
                    swap(a[i][x], a[i][y]);
            }
        }

        a = pow(a, m);
        for (int i = 0; i < n; i ++)
            printf("%lld%c", a[n][i], (i+1 == n)? '\n' : ' ');
    }

    return 0;
}