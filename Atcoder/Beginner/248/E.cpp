#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x[MAXN],y[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		if(m == 1) {
			puts("Infinity");
			return 0;
		}
	int res = 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)	
		{

			int cnt = 2;
			int can = 1;
			for (int k = 1; k <= n; k += 1) {
				if(k == i || k == j) continue;
				int x1 = x[k] - x[i];
				int y1 = y[k] - y[i];
				int x2 = x[j] - x[i];
				int y2 = y[j] - y[i];
				if(1ll * x1 * y2 - 1ll * x2 * y1 == 0) {
					if(k < max(i, j)) {
						can = 0;
					}
					cnt += 1;
				}
			}

			if(cnt >= m) {
				res += can;
			}
		}
		cout << res << '\n';
		return 0;
}