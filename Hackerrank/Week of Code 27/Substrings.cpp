#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot;
string str;
bool used[MAXN];
vector<P> query[MAXN];
vector<int> G[MAXN];
int st[MAXN],ed[MAXN],up_to[MAXN];
ll ans[MAXN];
void dfs(int v)
{
    st[v]=++tot;
    for(auto to:G[v])
        dfs(to);
    ed[v]=tot;
}
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;       
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,char ch) {
        edges.push_back(map<char,int>());
        length.push_back(length[p]+1); link.push_back(0);
        int r=edges.size()-1;
        while(p>=0&&edges[p].find(ch)==edges[p].end()) {
            edges[p][ch]=r;
            p=link[p];
        }
        if(p!=-1) {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) link[r]=q;
            else {
                edges.push_back(edges[q]); 
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=edges.size()-1;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch]==q) {
                    edges[p][ch]=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    void build(string &s){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
        for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i);
    }
}sam;
struct maxtree{
    int maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r)
        {
            maxi[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg1;
struct sumtree{
    int lazy[4*MAXN],len[4*MAXN];
    ll sum[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void add(int k,int v)
    {
        lazy[k]+=v; sum[k]+=1LL*len[k]*v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg2;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    sam.build(str);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        query[r].push_back(P(l,i));
    }
    int all=(int)sam.edges.size();
    dfs(0);
    seg2.build(1,1,n);
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        cur=sam.edges[cur][str[i-1]];
        seg2.update(1,1,n,i-sam.length[cur]+1,i,1);
        int tmp=cur;
        while(!used[tmp])
        {
            used[tmp]=true;
            tmp=sam.link[tmp];
        }
        while(tmp)
        {
            int maxc=seg1.query(1,1,all,st[tmp],ed[tmp]);
            seg2.update(1,1,n,maxc-sam.length[tmp]+1,maxc-sam.length[up_to[maxc]],-1);
            swap(up_to[maxc],tmp);
        }
        seg1.update(1,1,all,st[cur],i);
        up_to[i]=0;
        for(auto p:query[i]) ans[p.S]=seg2.query(1,1,n,p.F,n);
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}

