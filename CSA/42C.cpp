#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5;

int n;
int A[MAX_N];

int main() {
    cin >> n;
    assert(2 <= n && n <= MAX_N);

    queue<int> q;
    for (int i = 2; i <= n; ++i) {
        cin >> A[i];
        if (A[i]) {
            if (!q.size() || A[q.back()] + q.back() < A[i] + i) {
                q.push(i);
            }
        }
        if (q.size() && A[q.front()] + q.front() <= i) {
            q.pop();
        }
        if (q.size()) {
            cout << i - q.front() + 1 << " ";
        } else {
            cout << "0 ";
        }
    }
}
