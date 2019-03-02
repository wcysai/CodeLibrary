#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<P,greater<P>,pairing_heap_tag> pq;
int n,m;
pq a[MAXN];
int p[MAXN],r[MAXN];
bool deleted[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; a[y].join(a[x]);}
    else
    {
        p[y]=x;a[x].join(a[y]);
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a[i].push(P(x,i));
    }
    memset(deleted,false,sizeof(deleted));
    for(int i=0;i<m;i++)
    {
        int opt,x,y;scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&x,&y);
            if(deleted[x]||deleted[y]||same(x,y)) continue;
            unite(x,y);
        }
        else
        {
            scanf("%d",&x);
            if(deleted[x]) puts("-1");
            else
            {
                x=find(x);
                P v=a[x].top();deleted[v.S]=true;
                a[x].pop();
                printf("%d\n",v.F);
            }
        }
    }
    return 0;
}

