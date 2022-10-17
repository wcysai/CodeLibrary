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
int n,p,q,a[MAXN];
vector<int> dis;
set<int> sx,sy;
vector<int> G[MAXN];
int d[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
struct SAM{
    vector<map<int,int>> edges; 
    vector<int> link;            
    vector<int> length;       
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<int,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,int ch) {
        edges.push_back(map<int,int>());
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
    void build(vector<int> &s){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
    }
}sam;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    int sz=(int)dis.size();
    for(int i=0;i<n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
    vector<int> x,y;
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        int z; scanf("%d",&z);
        z=lower_bound(dis.begin(),dis.end(),z)-dis.begin()+1;
        x.push_back(z);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int z; scanf("%d",&z);
        z=lower_bound(dis.begin(),dis.end(),z)-dis.begin()+1;
        y.push_back(z);
    }
    int ans=0;
    sam.build(x);
    int l=0,now=0;
    for(int i=0;i<q;i++)
    {
        while(now>0&&!sam.edges[now][y[i]])
        {
            now=sam.link[now];
            l=sam.length[now];
        }
        if(sam.edges[now][y[i]])
        {
            now=sam.edges[now][y[i]];
            l++;
        }
        ans=max(ans,l);
    }
    if(ans)
    {
        printf("%d\n",p+q-2*ans);
        return 0;
    }
    for(int i=0;i<n-1;i++)
        add_edge(a[i],a[i+1]);
    for(int i=1;i<=sz;i++) d[i]=INF;
    queue<int> que;
    for(int i=0;i<p;i++) if(d[x[i]]==INF) {d[x[i]]=0; que.push(x[i]);}
    while(que.size())
    {
        int v=que.front(); que.pop();
        for(auto to:G[v])
        {
            if(d[to]==INF) 
            {
                d[to]=d[v]+1;
                que.push(to);
            }
        }
    }
    ans=INF;
    for(int i=0;i<q;i++) ans=min(ans,p+q-2+2*d[y[i]]);
    printf("%d\n",ans);
    return 0;
}

