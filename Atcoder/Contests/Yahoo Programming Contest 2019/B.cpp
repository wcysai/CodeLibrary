#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],deg[MAXN];
int main()
{
    for(int i=0;i<3;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
    }
    int cnt=0;
    for(int i=1;i<=4;i++) if(deg[i]&1) cnt++;
    if(cnt>2) puts("NO"); else puts("YES");
    return 0;
}

