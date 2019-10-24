#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int n,m;
vector<edge> G[MAXN];
