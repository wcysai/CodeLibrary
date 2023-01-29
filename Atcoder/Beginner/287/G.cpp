#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],b[MAXN];
int type[MAXN],x[MAXN],z[MAXN];
vector<int> dis,cnt;
struct segtree{
    int num[4*MAXN];
    ll val[4*MAXN];
    void pushup(int k){
        num[k]=num[k*2]+num[k*2+1];
        val[k]=val[k*2]+val[k*2+1];
    }
    void build(int k,int l,int r){
        if(l==r){
            num[k]=cnt[l];
            val[k]=1LL*cnt[l]*dis[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            num[k]+=v; val[k]+=1LL*v*dis[l];
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int need){
        if(l==r){
            return 1LL*dis[l]*min(need,num[k]);
        }
        int mid=(l+r)/2;
        if(num[k*2+1]>=need) return query(k*2+1,mid+1,r,need); 
        else return val[k*2+1]+query(k*2,l,mid,need-num[k*2+1]);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d%d",&a[i],&b[i]); dis.push_back(a[i]);}
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&type[i],&x[i]);
        if(type[i]!=3) scanf("%d",&z[i]); else z[i]=0; 
        if(type[i]==1) dis.push_back(z[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    cnt.resize(sz);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin();
        cnt[a[i]]+=b[i];
    }
    seg.build(1,0,sz-1);
    for(int i=1;i<=q;i++){
        if(type[i]==3){
            if(x[i]>seg.num[1]) puts("-1");
            else printf("%lld\n",seg.query(1,0,sz-1,x[i]));
        }
        else if(type[i]==1){
            z[i]=lower_bound(dis.begin(),dis.end(),z[i])-dis.begin();
            seg.update(1,0,sz-1,a[x[i]],-b[x[i]]);
            a[x[i]]=z[i];
            seg.update(1,0,sz-1,a[x[i]],b[x[i]]);
        }
        else{
            seg.update(1,0,sz-1,a[x[i]],-b[x[i]]);
            b[x[i]]=z[i];
            seg.update(1,0,sz-1,a[x[i]],b[x[i]]);
        }
    }
    return 0;
}

