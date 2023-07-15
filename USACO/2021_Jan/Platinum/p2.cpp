#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,q,c[MAXN];
int all;
vector<P> queries[MAXN];
ll ans[MAXN];
vector<pair<P,P> >st; //(a,b,c,d): ax^2+bx+c+d, takes over minimum at position d
ll eval(int id, int x){
    ll a=st[id].F.F,b=st[id].F.S,c=st[id].S.F;
    return 1LL*x*x*(a+all)+1LL*b*x+c;
}
ll query(int x){
    int l=0,r=(int)st.size();
    while(r-l>1){
        int mid=(l+r)/2;
        if(st[mid].S.S<=x) l=mid; else r=mid;
    }
    return eval(l,x);
}
//f(x)=ax^2+bx+c
//f(x+1)-f(x)=2ax+a+b
void add(int slope){
    if(st.size()>=1){
        auto q=st.back();
        if((q.F.F+all)*(2*n-1)+q.F.S<=slope) return;
    }
    while(st.size()>=2){
        int sz=(int)st.size();
        int x=st[sz-1].S.S;
        ll delta=eval(sz-1,x)-eval(sz-2,x-1);
        if(delta>=slope) st.pop_back(); else break;
    }
    pair<P,P> tmp;
    tmp.F.F=-all; tmp.F.S=slope; 
    int sz=(int)st.size();
    auto q=st.back();
    int l=q.S.S-1,r=n;
    //assert(l<=r);
    while(r-l>1){
        int mid=(l+r)/2;
        if((q.F.F+all)*(2*mid+1)+q.F.S>=slope) r=mid; else l=mid;
    }
    //assert(r!=n);
    ll res=eval(sz-1,r);
    tmp.S.F=res-1LL*(r)*slope;
    tmp.S.S=r+1;
    st.push_back(tmp);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        queries[y].push_back(P(x,i));
    }
    for(int i=1;i<=m;i++){
        if(i==1){
            st.push_back(make_pair(P(0,c[1]),P(-c[1],1)));
        }
        else{
            all++;
            int sz=(int)st.size();
            add(c[i]);
        }
        //printf("i=%d\n",i);
        //for(auto p:st) printf("%d %d %d %d\n",p.F.F+all,p.F.S,p.S.F,p.S.S);
        for(auto q:queries[i]){
            ans[q.S]=query(q.F);
        }
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}

