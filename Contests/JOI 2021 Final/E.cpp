#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN];
int s[MAXN],t[MAXN],u[MAXN],r[MAXN];
ll x[MAXN];
ll ans[MAXN];
int st[MAXN],tot;
P spt[MAXN][20];
int pre[MAXN];
bool bad[MAXN];
vector<int> disu;
vector<pair<int,P> > v[MAXN];//(id,(U,cont));
void init(int n,int *arr,int op){//op==0:min,max otherwise
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i){
        spt[i][0]=P(arr[i],i);
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            spt[i][j]=op?max(spt[i][j-1],spt[i+(1<<j-1)][j-1]):min(spt[i][j-1],spt[i+(1<<j-1)][j-1]);
    }
}
P query(int l,int r,int op){
    int len=r-l+1,k=pre[len];
    return op?max(spt[l][k],spt[r-(1<<k)+1][k]):min(spt[l][k],spt[r-(1<<k)+1][k]);
};
ll bit[2][MAXN+1];
vector<pair<P,P> > op;
ll sum(int id,int i){
    ll s=0;
    while(i>0){
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,ll x){
    if(!i) return;
    while(i<=n+1){
        bit[id][i]+=x;
        i+=i&-i;
    }
}
void update_interval(ll xl,ll xr,ll x,ll cont){
    if(xr-x<=x-xl){
        int pos1=lower_bound(disu.begin(),disu.end(),xr-x)-disu.begin()+1;
        int pos2=lower_bound(disu.begin(),disu.end(),x-xl)-disu.begin()+1;
        int pos3=lower_bound(disu.begin(),disu.end(),xr-xl)-disu.begin()+1;
        add(1,1,cont);
        add(1,pos1,-cont);
        add(0,pos1,cont*(xr-x));
        add(0,pos2,-cont*(xr-x));
        add(1,pos2,-cont);
        add(1,pos3,cont);
        add(0,pos2,cont*(xr-xl));
        add(0,pos3,cont*(xl-xr));
    }
    else{
        int pos1=lower_bound(disu.begin(),disu.end(),x-xl)-disu.begin()+1;
        int pos2=lower_bound(disu.begin(),disu.end(),xr-x)-disu.begin()+1;
        int pos3=lower_bound(disu.begin(),disu.end(),xr-xl)-disu.begin()+1;
        add(1,1,cont);
        add(1,pos1,-cont);
        add(0,pos1,cont*(x-xl));
        add(0,pos2,-cont*(x-xl));
        add(1,pos2,-cont);
        add(1,pos3,cont);
        add(0,pos2,cont*(xr-xl));
        add(0,pos3,cont*(xl-xr));
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    init(n,a,1);
    for(int i=1;i<=n;i++) x[i+1]=x[i]+a[i];
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&s[i],&t[i],&u[i]); 
        P p=query(s[i],t[i]-1,1);
        //printf("p=%d %d\n",p.F,p.S);
        if(p.F>u[i]) bad[i]=true; else disu.push_back(u[i]);
        //if(bad[i]) printf("i=%d\n",i);
    }
    disu.push_back(INF);
    sort(disu.begin(),disu.end());
    disu.erase(unique(disu.begin(),disu.end()),disu.end());
    for(int i=n;i>=1;i--){
        while(tot&&b[st[tot-1]]>=b[i]) tot--;
        r[i]=(tot==0?n+1:st[tot-1]);
        st[tot++]=i;
    }
    init(n,b,0);
    for(int i=1;i<=m;i++){
        if(bad[i]) continue;
        int l=s[i]-1,r=t[i];
        while(r-l>1){
            int mid=(l+r)/2;
            //printf("i=%d mid=%d dif=%lld\n",i,mid,x[t[i]]-x[mid]);
            if(x[t[i]]-x[mid]<=u[i]) r=mid; else l=mid; 
        }
        int pos=query(r,t[i]-1,0).S;
        v[s[i]].push_back(make_pair(i,P(u[i],1)));
        v[pos].push_back(make_pair(i,P(u[i],-1)));
        ans[i]+=1LL*(x[t[i]]-x[pos])*b[pos];
    }
    tot=0;
    for(int i=n;i>=1;i--){
        while(tot&&b[st[tot-1]]>=b[i]){
            //i is the lj for st[tot-1]
            int w=st[tot-1];
            update_interval(-INF,x[r[w]],x[w],-b[w]);
            update_interval(x[i],x[r[w]],x[w],b[w]);
            tot--;
        }
        st[tot++]=i;
        update_interval(-INF,x[r[i]],x[i],b[i]);
        for(auto p:v[i]){
            int id=lower_bound(disu.begin(),disu.end(),p.S.F)-disu.begin()+1;
            ans[p.F]+=p.S.S*(1LL*sum(1,id)*p.S.F+sum(0,id));
        }
    }
    for(int i=1;i<=m;i++){
        if(bad[i]) printf("-1\n"); else printf("%lld\n",ans[i]);
    }
    return 0;
}

