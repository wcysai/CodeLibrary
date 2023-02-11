#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int bit[MAXN+1],die[MAXN];
int bit2[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void add2(int i,int x){
    while(i<=n){
        bit2[i]+=x;
        i+=i&-i;
    }
}
int bisearch(int v){
    int sum=0,pos=0;
    for(int i=MAXLOGN;i>=0;i--){
        if(pos+(1<<i)<=n&&sum+bit2[pos+(1<<i)]<v){
            sum+=bit2[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
struct segtree{
    int maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void add(int k,int v){
        maxi[k]+=v; lazy[k]+=v;
    }
    void build(int k,int l,int r){
        lazy[k]=0;
        if(l==r) {maxi[k]=-l; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int find_leftmost(int k,int l,int r){
        if(l==r) return l;
        pushdown(k);
        int mid=(l+r)/2;
        if(maxi[k*2]>0) return find_leftmost(k*2,l,mid); else return find_leftmost(k*2+1,mid+1,r);
    }
}seg;
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) bit[i]=bit2[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
        seg.build(1,1,n);
        int added=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            int before=sum(a[i]);
            if(a[i]>before)
            {
                ans+=a[i]-(before+1);
                ans-=(added-before);
                add(a[i],1);
                added++;
                seg.update(1,1,n,a[i],n,1);
                if(seg.maxi[1]>0){
                    int z=seg.find_leftmost(1,1,n);
                    seg.update(1,1,n,z,n,-1);
                    ans+=added-z;
                    add(z,-1);
                    added--;
                }
            }
            //printf("i=%d die=%d\n",i,die[i]);
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}

