#include <iostream>
#include <deque>

using namespace std;

// (k, b) := 直线kx+b
struct Line
{
    int k, b;

    Line(int k, int b) : k(k), b(b)
    {}
};

const int MAX_N = 10000 + 8;
int N;
int S;
int sum_T[MAX_N];
int sum_F[MAX_N];
int dp[MAX_N];              // dp[i] := 从 1 ~ i 的最小耗时贡献


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &S);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", sum_T + i, sum_F + i);
        sum_T[i] += sum_T[i - 1];
        sum_F[i] += sum_F[i - 1];
    }
    deque<Line> lines;
    lines.push_back(Line(sum_F[N], S * sum_F[N]));
    for (int i = 1; i <= N; i++)
    {
        int k1, b1;
        int k2, b2;
        int k3, b3;

        while (lines.size() > 1)
        {
            k1 = lines[0].k;
            b1 = lines[0].b;
            k2 = lines[1].k;
            b2 = lines[1].b;
            if (k1 * sum_T[i] + b1 >= k2 * sum_T[i] + b2)
                lines.pop_front();  // 若头部的值不是最小值了则删去
            else
                break;
        }

        k1 = lines[0].k;
        b1 = lines[0].b;
        dp[i] = k1 * sum_T[i] + b1;
        k3 = sum_F[N] - sum_F[i];
        b3 = dp[i] + (S - sum_T[i]) * (sum_F[N] - sum_F[i]);

        while (lines.size() > 1)
        {
            k1 = lines[lines.size() - 2].k;
            b1 = lines[lines.size() - 2].b;
            k2 = lines[lines.size() - 1].k;
            b2 = lines[lines.size() - 1].b;
            if ((k2 - k1) * (b3 - b2) >= (b2 - b1) * (k3 - k2)) // tail不可能成为最小值的直线
                lines.pop_back();
            else
                break;
        }

        lines.push_back(Line(k3, b3));
    }

    printf("%d\n", dp[N]);
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
