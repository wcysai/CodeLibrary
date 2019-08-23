#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],t[MAXN],id[MAXN];
bool cmp(int x,int y)
{
    if(t[x]!=t[y]) return t[x]>t[y];
    return x<y;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x; scanf("%d",&x);
        t[x]=i;
    }
    for(int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++) printf("%d ",a[id[i]]);
    return 0;
}
