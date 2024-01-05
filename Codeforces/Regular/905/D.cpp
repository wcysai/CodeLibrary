#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],pos[MAXN];
int p[MAXN],l[MAXN],r[MAXN],rk[MAXN];
set<int> s;
bool has[MAXN];
vector<pair<P,int> > upd[MAXN];
vector<P> qry[MAXN];
int ans[MAXN];
int bit[MAXN+1];
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
void init(int n)
{
    for(int i=1;i<=n;i++){
        p[i]=i;
        rk[i]=0;
        l[i]=r[i]=i;
    }
}
int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; l[y]=min(l[x],l[y]); r[y]=max(r[x],r[y]);}
    else
    {
        p[y]=x;
        l[x]=min(l[x],l[y]); r[x]=max(r[x],r[y]);
        if(r[x]==r[y]) r[x]++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]]=i;}
    init(n);
    memset(has,false,sizeof(has));
    for(int i=1;i<=n;i++){
        s.insert(pos[i]);
        has[pos[i]]=true;
        if(has[pos[i]-1]) unite(pos[i],pos[i]-1);
        if(has[pos[i]+1]) unite(pos[i],pos[i]+1);
        int lb=l[find(pos[i])],rb=r[find(pos[i])];
        auto it=s.lower_bound(rb+1);
        int nxt;
        if(it==s.end()) nxt=n; else nxt=(*it)-1;
        //printf("%d %d %d %d %d %d\n",i,pos[i],lb,rb,rb+1,nxt);
        upd[lb].push_back(make_pair(P(rb+1,nxt),1)); upd[rb+1].push_back(make_pair(P(rb+1,nxt),-1));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&l[i],&r[i]);
        qry[l[i]].push_back(P(r[i],i));
    }
    for(int i=1;i<=n;i++){
        for(auto p:upd[i]){
            if(p.S==1) {add(p.F.F,1); add(p.F.S+1,-1);} else {add(p.F.F,-1); add(p.F.S+1,1);}
        }
        for(auto p:qry[i]){
            assert(sum(p.F)>=0);
            if(sum(p.F)) ans[p.S]=1; else ans[p.S]=0;
        }
    }
    for(int i=0;i<q;i++) if(ans[i]) printf("Yes\n"); else printf("No\n");
    return 0;
}

