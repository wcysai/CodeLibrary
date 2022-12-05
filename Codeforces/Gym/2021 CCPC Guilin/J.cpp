#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int q;
ll sum[2*MAXN];
int id[2*MAXN];
vector<P> query[MAXN];
vector<P> upd[MAXN];
P ans[MAXN];
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;       
    vector<pair<char,int> > G[2*MAXN];
    int tot;
    vector<int> ord,buc,fst,pre;
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
    void dfs(int v)
    {
        for(auto p:G[v])
        {
            int to=p.S;
            tot++;
            id[tot]=to; 
            int st=length[v]+1,ed=length[to]; 
            //printf("tot=%d st=%d ed=%d num=%d\n",tot,st,ed,to);
            sum[st]++; sum[ed+1]--;
            upd[st].push_back(P(tot,1));
            upd[ed+1].push_back(P(tot,-1));
            dfs(to);
        }
    }
    void build(string &s){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) 
        {
            cur=add(cur,s[i]);
            pre.push_back(cur);
        }
        int sz=(int)edges.size();
        ord.resize(sz); buc.resize(sz); fst.resize(sz);
        for(int i=0;i<sz;i++) fst[i]=-INF;
        for(int i=0;i<(int)pre.size();i++) fst[pre[i]]=i; 
        for(int i=1;i<sz;i++) buc[length[i]]++;
        for(int i=1;i<sz;i++) buc[i]+=buc[i-1];
        for(int i=1;i<sz;i++) ord[buc[length[i]]--]=i;
        for(int i=sz-1;i>=1;i--) fst[link[ord[i]]]=max(fst[link[ord[i]]],fst[ord[i]]);
        for(int i=1;i<sz;i++)
        {
            assert(fst[i]!=-INF);
            char ch=s[fst[i]-length[link[i]]];
            G[link[i]].push_back(P(ch,i));
        }
        for(int i=0;i<sz;i++) sort(G[i].begin(),G[i].end());
        dfs(0);
    }
}sam;
struct segtree{
    int sum[8*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void update(int k,int l,int r,int pos,int v)
    {
        //if(k==1) printf("pos=%d v=%d\n",pos,v);
        if(l==r) {sum[k]+=v; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(sum[k*2]>=x) return query(k*2,l,mid,x); else return query(k*2+1,mid+1,r,x-sum[k*2]);
    }
}seg;
int main()
{
    cin>>str;
    int n=(int)str.size();
    reverse(str.begin(),str.end());
    sam.build(str);
    for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        ll k;
        scanf("%lld",&k);
        if(k>sum[n]) ans[i]=P(-1,-1);
        else
        {
            int pos=lower_bound(sum+1,sum+n+1,k)-sum;
            query[pos].push_back(P(k-sum[pos-1],i));
        }
    }
    int sz=sam.edges.size();
    for(int i=1;i<=n;i++)
    {
        for(auto p:upd[i]) seg.update(1,1,sz,p.F,p.S);
        for(auto p:query[i]) 
        {
            int num=seg.query(1,1,sz,p.F);
            int pos=sam.fst[id[num]];
            //printf("j=%d num=%d pos=%d\n",p.F,id[num],pos);
            P q=P(pos-i+1,pos);
            ans[p.S]=P(n-q.S,n-q.F);
        }
    }
    for(int i=0;i<q;i++) printf("%d %d\n",ans[i].F,ans[i].S);
    return 0;
}
