#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	if(k<__builtin_popcount(n)) {
		cout << "NO";
		return 0;
	}
	priority_queue<int> pq;
	for(int i=0; i<30; ++i)	
		if(n>>i&1)
			pq.push(i);
	while(pq.size()<k) {
		if(!pq.top()) {
			cout << "NO";
			return 0;
		}
		int a=pq.top();
		pq.pop();
		pq.push(a-1);
		pq.push(a-1);
	}
	cout << "YES\n";
	while(pq.size()) {
		cout << (1<<pq.top()) << " ";
		pq.pop();
	}
}
