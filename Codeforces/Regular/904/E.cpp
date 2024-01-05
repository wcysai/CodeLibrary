#include<bits/stdc++.h>
#define MAXN 2000015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int p[MAXN],len[MAXN],st[MAXN],l[MAXN];
bool alive[MAXN];
ll op[MAXN];
int coin0[MAXN],coin1[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void add_op_constant(int l,int r,int x){
    if(l>r) r+=n;
    op[l]+=x; op[r+1]-=x;
}
void add_coin_constant(int l,int r,int x){
    if(l>r) r+=n;
    add(coin0[l],x); dec(coin0[r+1],x);
}
void add_coin_quad(int l,int r,int x){
    if(l>r) r+=n;
    int len=r-l+1;
    add(coin1[l],x); add(coin1[l+1],x); dec(coin1[r+1],1LL*(len+1)*(len+1)%MOD*x%MOD);
    dec(coin1[r+3],1LL*len*len%MOD*x%MOD); add(coin1[r+2],(1LL*(len+1)*(len+1)+1LL*len*len-2)%MOD*x%MOD);
}
void add_coin_rev_quad(int l,int r,int x){
    if(l>r) r+=n;
    int len=r-l+1;
    dec(coin1[r+2],x); dec(coin1[r+3],x); add(coin1[l+2],1LL*(len+1)*(len+1)%MOD*x%MOD);
    add(coin1[l],1LL*len*len%MOD*x%MOD); dec(coin1[l+1],(1LL*(len+1)*(len+1)+1LL*len*len-2)%MOD*x%MOD);
}
void add_interval(int len,int from,int to,int left){
    //printf("len=%d from=%d to=%d left=%d\n",len,from,to,left);
    if(from>=to) return;
    if(len==1){
        add_op_constant(0,n-1,to-from);
        add_coin_constant(0,n-1,to-from);
        return;
    }
    int x=(left+1); while(x>=n) x-=n; while(x<0) x+=n;
    int y=(x+len-2)%n; 
   // printf("x=%d y=%d\n",x,y);
    add_op_constant(0,n-1,to-from);
    add_op_constant(x,y,to-from);
    add_coin_constant(0,n-1,1LL*len*len%MOD*(to-from)%MOD);
    add_coin_constant(x,y,(MOD-1LL*len*len%MOD*(to-from)%MOD)%MOD);
    add_coin_quad(x,y,to-from);
    add_coin_rev_quad(x,y,to-from);
}
void init(int n){
    for(int i=0;i<=n-1;i++) {p[i]=i; l[i]=i; len[i]=1; st[i]=0; alive[i]=false;}
    for(int i=0;i<=2*n+5;i++) op[i]=coin0[i]=coin1[i]=0;
}
int find(int x){
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x); y=find(y);
    p[x]=y; len[y]+=len[x]; 
}
void turn(int x,int val){
    alive[x]=true; 
    int pre=(x==0?n-1:x-1),nxt=(x==n-1?0:x+1);
    if(alive[pre]&&!same(x,pre)){
        add_interval(len[find(pre)],st[find(pre)],val,l[find(pre)]);
        unite(x,pre);
    }
    if(alive[nxt]&&!same(x,nxt)){
        add_interval(len[find(nxt)],st[find(nxt)],val,l[find(nxt)]);
        unite(nxt,x);
    }
    st[find(x)]=val;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<P> v; 
        for(int i=0;i<=n-1;i++) {scanf("%d",&a[i]); v.push_back(P(a[i],i));}
        sort(v.begin(),v.end());
        init(n);
        for(auto p:v) turn(p.S,p.F);
        for(int i=1;i<=2*n;i++) op[i]+=op[i-1];
        for(int i=1;i<=2*n;i++) add(coin1[i],coin1[i-1]);
        for(int i=1;i<=2*n;i++) add(coin1[i],coin1[i-1]);
        for(int i=0;i<=2*n;i++) add(coin0[i],coin1[i]);
        for(int i=1;i<=2*n;i++) add(coin0[i],coin0[i-1]); 
        for(int i=n;i<2*n;i++){
            add(coin0[i-n],coin0[i]);
            op[i-n]+=op[i];
        }
        for(int i=0;i<n;i++) printf("%lld %d\n",op[i],coin0[i]);
    }
    return 0;
}

