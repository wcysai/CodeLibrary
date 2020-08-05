#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
vector<int> dis;
vector<int> G[4*MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
void build(int k,int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    build(k*2,l,mid); build(k*2+1,mid+1,r);
    add_edge(k,k*2); add_edge(k,k*2+1);
    add_edge(k*2,k); add_edge(k*2+1,k);
}
void seg_add_edge(int k,int l,int r,int x,int y,int v,int type)
{
    if(l>y||x>r) return;
    if(l>=x&&r<=y)
    {
        if(!type) add_edge(k,v); else add_edge(v,k);
        return;
    }
    int mid=(l+r)/2;
    seg_add_edge(k*2,l,mid,x,y,v,type); seg_add_edge(k*2+1,mid+1,r,x,y,v,type);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        dis.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
            b[i]+=a[i]; d[i]+=c[i];
            dis.push_back(a[i]); dis.push_back(b[i]); dis.push_back(c[i]); dis.push_back(d[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        int sz=(int)dis.size();
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
            b[i]=lower_bound(dis.begin(),dis.end(),b[i])-dis.begin()+1;
            c[i]=lower_bound(dis.begin(),dis.end(),c[i])-dis.begin()+1;
            d[i]=lower_bound(dis.begin(),dis.end(),d[i])-dis.begin()+1;
            seg_add_edge(1,1,sz,a[i],b[i],)
        }
    }
}