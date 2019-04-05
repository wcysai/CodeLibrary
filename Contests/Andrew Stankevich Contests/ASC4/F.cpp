#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int sum[MAXN];
int ans;
struct segtree
{
    int mini[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r) {mini[k]=sum[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    freopen("positive.in","r",stdin);
    freopen("positive.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
    seg.build(1,1,2*n);
    for(int i=0;i<n;i++) if(seg.query(1,1,2*n,i+1,i+n)>sum[i]) ans++;
    printf("%d\n",ans);
    return 0;
}
