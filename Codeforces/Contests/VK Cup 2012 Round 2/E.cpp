#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXC 26
using namespace std;
typedef long long ll;
int n,k,tot;
string str[MAXN];
int id[MAXN];
vector<int> G[MAXN];
bool ins[MAXN];
int st[MAXN],ed[MAXN];
struct aho_corasick {
    int cnt=0,link[MAXN],nxt[MAXN][MAXC];
    int add(string &s) {
        int cur=0;
        for(char &c:s) {
            if(nxt[cur][c-'a']==0) nxt[cur][c-'a']=++cnt;
            cur=nxt[cur][c-'a'];
        }
        return cur;
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
            for(int i=0;i<MAXC;i++) {
                if(nxt[u][i]>0) {
                    int v=nxt[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    link[v]=nxt[link[u]][i];
                    if (link[v]==v) link[v]=0;
                } 
                else nxt[u][i]=nxt[link[u]][i];
            }
        }
    }
    void build()
    {
        BFS();
        for(int i=1;i<=cnt;i++) G[link[i]].push_back(i);
    }
} acs;
struct segtree{
    int sum[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r) {sum[k]+=v; return;}
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
}seg;
void dfs(int v)
{
    st[v]=++tot;
    for(auto to:G[v]) dfs(to);
    ed[v]=tot;
}
void init()
{
    acs.build();
    dfs(0);
    for(int i=0;i<k;i++) 
    {
        seg.update(1,1,tot+1,st[id[i]],1);
        seg.update(1,1,tot+1,ed[id[i]]+1,-1);
    }
    for(int i=0;i<k;i++) ins[i]=true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>str[i];
        id[i]=acs.add(str[i]);
    }
    init();
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        if(t[0]=='?')
        {
            ll res=0;
            int cur=0;
            for(int j=1;j<(int)t.size();j++)
            {
                cur=acs.nxt[cur][t[j]-'a'];
                res+=seg.query(1,1,tot+1,1,st[cur]);
            }
            cout<<res<<endl;
        }
        else 
        {
            int x=0;
            for(int j=1;j<(int)t.size();j++) x=x*10+(t[j]-'0');
            x--;
            if(t[0]=='-'&&!ins[x]) continue;
            if(t[0]=='+'&&ins[x]) continue;
            seg.update(1,1,tot+1,st[id[x]],t[0]=='+'?1:-1);
            seg.update(1,1,tot+1,ed[id[x]]+1,t[0]=='+'?-1:1);
            if(t[0]=='-') ins[x]=false; else ins[x]=true;
        }
    }
    return 0;
}
