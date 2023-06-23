#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000000000000LL
#define INF2 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int t,n,k,a[MAXN];
ll dp[MAXN];
struct segtree{
    ll maxi[4*MAXN],lazy[4*MAXN];
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r){
        lazy[k]=maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void add(int k,ll v){
        maxi[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++){
            add(i,lazy[k]);
        }
        lazy[k]=0;
    }
    void update(int k,int l,int r,int x,int y,ll v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<int> st;
        seg.build(1,0,n);
        dp[0]=0;
        //i: dp[i-1]-max(a[i],a[i+1],...,a[cur])
        for(int i=1;i<=n;i++){
            seg.update(1,0,n,i,i,dp[i-1]-a[i]);
            while(st.size()&&a[st.back()]<=a[i]){
                int pos=st.back();
                st.pop_back();
                int pre=(st.size()?st.back()+1:0);
                seg.update(1,0,n,pre,pos,-a[i]+a[pos]);
            }
            st.push_back(i);
            dp[i]=1+seg.query(1,0,n,1,i);
        }
        printf("%lld\n",dp[n]);
        
    }

    return 0;
}

