#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int ans[MAXN];
vector<int> G[MAXN];
namespace IO {
    const int MX = 4e7; //1e7占用内存11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
struct state
{
    vector<int> *a;
    int cur_max;
    int sz()
    {
        return a->size();
    }
    void add(int i,int val)
    {
        (*a)[i]+=val;
        if((*a)[i]>(*a)[cur_max]) cur_max=i;
        else if((*a)[i]==(*a)[cur_max]&&i>cur_max) cur_max=i;
    }
}s[MAXN];
state pull(state z)
{
    if(z.sz()==0)
    {
        state c;
        c.a=new vector<int> (1,1);
        c.cur_max=0;
        return c;
    }
    else
    {
        state c;
        c.a=z.a;
        c.cur_max=z.cur_max;
        c.a->push_back(0);;
        c.add(c.sz()-1,1);
        return c;
    }
}
state merge(state a,state b)
{
    if(a.sz()<b.sz()) swap(a,b);
    int bs=b.sz();
    int as=a.sz();
    for(int i=0;i<bs;i++) a.add(as-i-1,(*(b.a))[bs-i-1]);
    return a;
}
void dfs(int v,int p)
{
    s[v].a=new vector<int>(0);
    s[v].cur_max=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        s[v]=merge(s[v],s[to]);
    }
    s[v]=pull(s[v]);
    ans[v]=s[v].sz()-1-s[v].cur_max;
}
int main()
{
    IO::begin();
    IO::read(n);
    //scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v; 
        //scanf("%d%d",&u,&v);
        IO::read(u); IO::read(v);
        G[u].push_back(v);G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

