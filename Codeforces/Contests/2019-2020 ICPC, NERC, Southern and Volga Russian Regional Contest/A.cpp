#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN];
int pos[MAXN],maxi[MAXN],mini[MAXN];
void update(int x)
{
    maxi[x]=max(maxi[x],pos[x]);
    mini[x]=min(mini[x],pos[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) maxi[i]=mini[i]=a[i]=pos[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if(pos[x]==1) continue;
        int r=pos[x];
        int y=a[r-1];
        swap(a[r],a[r-1]);
        swap(pos[x],pos[y]);
        update(x); update(y);
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",mini[i],maxi[i]);
    return 0;
}
