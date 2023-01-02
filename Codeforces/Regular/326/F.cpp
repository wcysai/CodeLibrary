#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 4000005
#define MAXC 26
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,all,q,tot,txt,tt,a[MAXN];
vector<int> G[MAXN];
int root[MAXN],st[MAXN],ed[MAXN];
int lson[MAXM],rson[MAXM];
int bigid[MAXN];
ll s[205][MAXN];
ll c[MAXN];
int id[MAXN];
string str[MAXN];
ll sum[MAXM];
void dfs(int v){
    st[v]=++txt;
    for(auto to:G[v]) dfs(to);
    ed[v]=txt;
}
void merge(int k){
    sum[k]=sum[lson[k]]+sum[rson[k]];
}
void insert(int &k,int last,int l,int r,int p,int v){
    k=++tot;
    sum[k]=sum[last];
    if(l==r) {sum[k]+=v; return;}
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    merge(k);
}
ll query(int &k,int l,int r,int x,int y)
{
    if(!k) return 0;
    if(l>y||r<x) return 0;
    if(l>=x&&r<=y) return sum[k];
    int mid=(l+r)/2;
    return query(lson[k],l,mid,x,y)+query(rson[k],mid+1,r,x,y);
}
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    int add(string &s) {
        int cur=0;
        for(char &c:s) {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        return cur;
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
            for(int i=0;i<MAXC;i++) {
                if(ch[u][i]>0) {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    link[v]=nxt[link[u]][i];
                    if (link[v]==v) link[v]=0;
                } 
                else nxt[u][i]=nxt[link[u]][i];
            }
        }
        for(int i=1;i<=cnt;i++) G[link[i]].push_back(i);
    }
} acs;
const int threshold=505;
void accumulate(int v){
    for(auto to:G[v]){
        accumulate(to);
        c[v]+=c[to];
    }
}
void preprocess(int x){
    for(int i=0;i<=all;i++) c[i]=0;
    int now=0;
    for(int i=0;i<(int)str[x].size();i++){
        now=acs.nxt[now][str[x][i]-'a'];
        c[now]++;
    }
    accumulate(0);
    for(int i=1;i<=n;i++) s[bigid[x]][i]=s[bigid[x]][i-1]+c[id[i]];
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {cin>>str[i]; id[i]=acs.add(str[i]); }
    acs.BFS();
    all=acs.cnt;
    dfs(0);
    for(int i=1;i<=n;i++){
        int tmp;
        if(ed[id[i]]==all+1){
            insert(root[i],root[i-1],1,all+1,st[id[i]],1);
        }
        else
        {
            insert(tmp,root[i-1],1,all+1,st[id[i]],1);
            insert(root[i],tmp,1,all+1,ed[id[i]]+1,-1);
        }
    }
    for(int i=1;i<=n;i++){
        if(str[i].size()>=threshold){
            bigid[i]=++tt;
            preprocess(i);
        }
    }
    for(int i=0;i<q;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        if(bigid[k]) 
        {
            printf("%lld\n",s[bigid[k]][r]-s[bigid[k]][l-1]);
        }
        else{
            ll res=0;
            int now=0;
            for(int j=0;j<(int)str[k].size();j++){
                now=acs.nxt[now][str[k][j]-'a'];
                res+=query(root[r],1,all+1,1,st[now]);
                res-=query(root[l-1],1,all+1,1,st[now]);
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}

