#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,sz,a[MAXN],x[MAXN],y[MAXN];
vector<int> dis;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
struct segtree
{
    int cnt[8*MAXN],sum[8*MAXN];
    void pushup(int k)
    {
        cnt[k]=cnt[k*2]; add(cnt[k],cnt[k*2+1]);
        sum[k]=sum[k*2]; add(sum[k],sum[k*2+1]);
    }
    void update(int k,int l,int r,int p,int delta)
    {
        if(l==r)
        {
            add(cnt[k],delta);
            add(sum[k],1LL*delta*dis[p-1]%MOD);
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,delta); else update(k*2+1,mid+1,r,p,delta);
        pushup(k);
    }
    int query_cnt(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return cnt[k];
        int mid=(l+r)/2;
        return (query_cnt(k*2,l,mid,x,y)+query_cnt(k*2+1,mid+1,r,x,y))%MOD;
    }
    int query_sum(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return (query_sum(k*2,l,mid,x,y)+query_sum(k*2+1,mid+1,r,x,y))%MOD;
    }
}seg;
int calc_contri(int val)
{
    int id=lower_bound(dis.begin(),dis.end(),val)-dis.begin()+1;
    int lsum=1LL*seg.query_cnt(1,1,sz,1,id)*val%MOD;
    dec(lsum,seg.query_sum(1,1,sz,1,id));
    int rsum=seg.query_sum(1,1,sz,id+1,sz);
    dec(rsum,1LL*seg.query_cnt(1,1,sz,id+1,sz)*val%MOD);
    add(lsum,rsum);
    return lsum;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]);
    }
    for(int i=1;i<=q;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        dis.push_back(y[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    sz=(int)dis.size();
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        seg.update(1,1,sz,id,1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,calc_contri(a[i]));
    for(int i=1;i<=q;i++)
    {
        dec(ans,2LL*calc_contri(a[x[i]])%MOD);
        int id=lower_bound(dis.begin(),dis.end(),a[x[i]])-dis.begin()+1;
        seg.update(1,1,sz,id,MOD-1);
        a[x[i]]=y[i];
        id=lower_bound(dis.begin(),dis.end(),a[x[i]])-dis.begin()+1;
        seg.update(1,1,sz,id,1);
        add(ans,2LL*calc_contri(a[x[i]])%MOD);
        printf("%d\n",1LL*ans*INV%MOD*INV%MOD);
    }
    return 0;
}