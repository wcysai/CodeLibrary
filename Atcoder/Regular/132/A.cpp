#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,r[MAXN],c[MAXN];
vector<P> vc;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(r[x]+c[y]>=n+1) printf("#"); else printf(".");
    }
    return 0;
}