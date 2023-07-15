#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,q;
string str;
multiset<int> in[MAXN],out[MAXN];
struct segtree1{
    P mini[4*MAXN],maxi[4*MAXN];
    int lazy[4*MAXN];
    void add(int k,int v){
        mini[k].F+=v; maxi[k].F+=v; lazy[k]+=v;
    }
    void pushup(int k){
        mini[k]=min(mini[k*2],mini[k*2+1]);
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
            add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r,int type){
        lazy[k]=0;
        if(l==r){
            mini[k].S=maxi[k].S=l;
            if(type==1){mini[k].F=maxi[k].F=l;} 
            else {mini[k].F=INF; maxi[k].F=-INF;}
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid,type); build(k*2+1,mid+1,r,type);
        pushup(k);
    }
    void interval_add(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(k,v); return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        interval_add(k*2,l,mid,x,y,v); interval_add(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void modify(int k,int l,int r,int pos,int v){
        if(l==r){
            mini[k].F=maxi[k].F=v; return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) modify(k*2,l,mid,pos,v); else modify(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    P query_min(int k,int l,int r,int x,int y){
        if(l>y||x>r) return P(INF,INF);
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query_min(k*2,l,mid,x,y),query_min(k*2+1,mid+1,r,x,y));
    }
    P query_max(int k,int l,int r,int x,int y){
        if(l>y||x>r) return P(-INF,-INF);
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query_max(k*2,l,mid,x,y),query_max(k*2+1,mid+1,r,x,y));
    }
    int rightmost_zero(int k,int l,int r){
        if(l==r) return l;
        int mid=(l+r)/2;
        pushdown(k);
        if(mini[k*2+1].F==0) return rightmost_zero(k*2+1,mid+1,r);
        else return rightmost_zero(k*2,l,mid);
    }
}segval,segin,segout;
int main()
{
    scanf("%d%d",&T,&q);
    segval.build(1,1,T,1);
    segin.build(1,1,T,2); segout.build(1,1,T,2);
    ll ans=0;
    while(q--){
        cin>>str;
        int t,p;
        scanf("%d%d",&t,&p);
        if(str=="ADD"){
            segval.interval_add(1,1,T,t,T,-1);
            in[t].insert(p); ans+=p;
            segin.modify(1,1,T,t,(!in[t].size())?INF:(*in[t].begin()));
            P q=segval.query_min(1,1,T,1,T);
            if(q.F<0){
                P z=segin.query_min(1,1,T,1,q.S);
                int pos=z.S; ans-=z.F;
                in[pos].erase(in[pos].find(z.F));
                out[pos].insert(z.F);
                segin.modify(1,1,T,pos,(!in[pos].size())?INF:(*(in[pos].begin())));
                segout.modify(1,1,T,pos,(!out[pos].size())?-INF:(*(--out[pos].end())));
                segval.interval_add(1,1,T,pos,T,1);
            }
        }
        else{
            if(out[t].find(p)!=out[t].end()){
                out[t].erase(out[t].find(p));
                segout.modify(1,1,T,t,(!out[t].size())?-INF:(*(--out[t].end())));
            }
            else{
                segval.interval_add(1,1,T,t,T,1);
                assert(in[t].find(p)!=in[t].end());
                in[t].erase(in[t].find(p)); ans-=p;
                segin.modify(1,1,T,t,(!in[t].size())?INF:(*(in[t].begin())));
                int val=segval.query_min(1,1,T,1,T).F,tmp;
                if(val==0) tmp=segval.rightmost_zero(1,1,T); else tmp=0;
                P z=segout.query_max(1,1,T,tmp+1,T);
                if(z.F!=-INF){ 
                    int pos=z.S; ans+=z.F;
                    out[pos].erase(out[pos].find(z.F));
                    in[pos].insert(z.F);
                    segin.modify(1,1,T,pos,(!in[pos].size())?INF:(*(in[pos].begin())));
                    segout.modify(1,1,T,pos,(!out[pos].size())?-INF:(*(--out[pos].end())));
                    segval.interval_add(1,1,T,pos,T,-1);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

