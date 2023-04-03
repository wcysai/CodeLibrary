#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 18
#define MAXN 100005
#define MAXM 100005
using namespace std;
int n,m,q,ans,block;
struct query
{
    int l,r,id;
}save[MAXM];
int tot,st[MAXN],ed[MAXN],out[MAXM],c[MAXN];
int spt[MAXLOGN+1][2*MAXN];
vector<int> G[MAXN];
int vs[MAXN*2-1];
int depth[MAXN*2-1];
int id[MAXN];
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    st[v]=++tot;
    for(int i=0;i<(int)G[v].size();i++){
        if(G[v][i]!=p){
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
    ed[v]=tot;
}
int getMin(int x, int y){
    return depth[x]<depth[y]?x:y;
}

void rmq_init(int n){
    for(int i=1;i<=n;++i) spt[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            spt[i][j]=getMin(spt[i-1][j],spt[i-1][j+(1<<(i-1))]);
}
void init(int V){
    int k=0;
    dfs(1,0,0,k);
    rmq_init(V*2-1);
}
int qry(int l, int r){
    int k=31-__builtin_clz(r-l+1);
    return getMin(spt[k][l],spt[k][r-(1<<k)+1]);
}
int lca(int u,int v){
    if(u==v) return u;
    return vs[qry(min(id[u],id[v]),max(id[u],id[v]))];
}
int dis(int u,int v){
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
bool cmp(query &x,query &y){
    if(x.l/block!=y.l/block) return x.l/block<y.l/block;
    if(x.l/block&1) return x.r>y.r; else return x.r<y.r;
}
struct node{
    int val;
    bool operator<(const node y)const{
        return st[val]<st[y.val];
    }
};
multiset<node> ms;
void add(int pos){
    //printf("add %d\n",c[pos]);
    ms.insert((node){c[pos]});
    auto it=ms.lower_bound((node){c[pos]});
    if(ms.size()>=2){
        int pre,suf;
        if(it!=ms.begin()){
            --it;
            pre=it->val; ++it; 
        }
        else{
            pre=(--ms.end())->val;
        }
        it++;
        if(it!=ms.end()){
            suf=it->val;
        }
        else suf=(ms.begin())->val;
        ans-=dis(pre,suf);
        ans+=dis(pre,c[pos]); ans+=dis(suf,c[pos]);
    }
    //printf("ans=%d\n",ans);
}
void del(int pos){
    //printf("del %d\n",c[pos]);
    auto it=ms.lower_bound((node){c[pos]});
    if(ms.size()>=2){
        int pre,suf;
        if(it!=ms.begin()){
            --it;
            pre=it->val; ++it; 
        }
        else{
            pre=(--ms.end())->val;
        }
        it++;
        if(it!=ms.end()){
            suf=it->val;
        }
        else suf=(ms.begin())->val;
        ans+=dis(pre,suf);
        ans-=dis(pre,c[pos]); ans-=dis(suf,c[pos]);
    }
    ms.erase(ms.find((node){c[pos]}));
    //printf("ans=%d\n",ans);
}
void update(int cl,int cr,int l,int r){
    while(cr<r) add(++cr);
    while(cl>l) add(--cl);
    while(cl<l) del(cl++);
    while(cr>r) del(cr--);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    init(n);
    for(int i=0;i<q;i++){
        save[i].id=i;
        scanf("%d%d",&save[i].l,&save[i].r);
    }
    block=(int)sqrt(m);
    ans=0;
    int cl=1,cr=0;
    for(int i=0;i<q;i++)
    {
        update(cl,cr,save[i].l,save[i].r);
        //printf("ans=%d\n",ans);
        out[save[i].id]=ans/2+1;
        cl=save[i].l;
        cr=save[i].r;
    }
    for(int i=0;i<q;i++)
        printf("%d\n",out[i]);
    return 0;
}


