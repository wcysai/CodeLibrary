#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
vector<int> pos[MAXN];
int s[MAXN];
int bit[MAXN+1];
vector<P> query[MAXN];
vector<int> upd[MAXN];
int ans[MAXN];
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
struct segtree{
    int maxi[4*MAXN];
    void pushup(int k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void update(int k,int l,int r,int pos,int v){
        if(l==r){
            maxi[k]=v; return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        pos[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) if(pos[i].size()) s[i]=1;
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    for(int i=1;i<=n;i++){
        if(pos[i].size()>1){
            for(int j=1;j<(int)pos[i].size();j++){
                int x=pos[i][j-1],y=pos[i][j];
                int maxi=seg.query(1,1,n,x+1,y-1);
                if(maxi>i) continue;
                //printf("l=%d r=%d\n",maxi,i);
                upd[maxi].push_back(i);
            }
        }
        for(auto x:pos[i]) seg.update(1,1,n,x,i);
    }
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        ans[i]=s[r]-s[l-1];
        //printf("i=%d ans=%d\n",i,ans[i]);
        query[l].push_back(P(r,i));
    }
    for(int i=n;i>=1;i--){
        for(auto x:upd[i]) add(x,1);
        for(auto p:query[i]) ans[p.S]+=sum(p.F);
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

