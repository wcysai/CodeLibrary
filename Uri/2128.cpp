#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int u[MAXM],v[MAXM],color[MAXM];
int n,m,k;
struct LinearMatroid
{
    ll basis[62];
    void clear()
    {
        memset(basis,0,sizeof(basis));
    }
    void add(ll x)
    {
        for(int j=60;j>=0;j--)
        {
            if(!(x&(1LL<<j))) continue;
            if(!basis[j])
            {
                basis[j]=x;
                return;
            }
            else x^=basis[j];
        }
    }
    bool test(ll x)
    {
        for(int j=60;j>=0;j--)
        {
            if(!(x&(1LL<<j))) continue;
            if(!basis[j]) return true; else x^=basis[j];
        }
        return false;
    }
};
struct ColorfulMatroid
{
    int cnt[205];
    void clear()
    {
        memset(cnt,0,sizeof(cnt));
    }
    void add(int x)
    {
        cnt[x]++;
    }
    void dec(int x)
    {
        cnt[x]--;
    }
    bool test(int x)
    {
        return (cnt[x]<=0);
    }
};

struct GraphMatroid
{
    int p[MAXN],r[MAXN];
    int find(int x)
    {
        if(p[x]==x) return x;
        else return p[x]=find(p[x]);
    }
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(r[x]<r[y]) p[x]=y;
        else
        {
            p[y]=x;
            if(r[x]==r[y]) r[x]++;
        }
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
    void clear()
    {
        for(int i=1;i<=n;i++)
        {
            p[i]=i;
            r[i]=0;
        }
    }
    void add(int u,int v)
    {
        unite(u,v);
    }
    bool test(int u,int v)
    {
        return !same(u,v);
    }
};


template <typename MT1, typename MT2>
struct MatroidIntersection
{
    int n;
    MatroidIntersection(int _n):n(_n){}
    int pre[MAXM],id[MAXM];
    bool vis[MAXM],sink[MAXM],has[MAXM];
    queue<int> que;
    void clear_all()
    {
        for(int i=1;i<=n;i++) vis[i]=sink[i]=false,pre[i]=0;
        memset(pre,0,sizeof(pre));
        while(que.size()) que.pop();
    }
    vector<int> getcur()
    {
        vector<int> ret;
        for(int i=1;i<=n;i++) if(has[i]) ret.push_back(i);
        return ret;
    }
    void enqueue(int v,int p)
    {
        vis[v]=true; pre[v]=p;
        que.push(v);
    }
    vector<int> run()
    {
        MT1 mt1;  MT2 mt2;
        memset(has,false,sizeof(has));
        while(true)
        {
            vector<int> cur=getcur();
            int cnt=0;
            for(int i=1;i<=n;i++) if(has[i]) id[i]=cnt++;
            MT1 allmt1; MT2 allmt2; allmt1.clear(); allmt2.clear();
            vector<MT1> vmt1(cur.size());
            for(auto &x:vmt1) x.clear();
            clear_all();
            for(auto x:cur) allmt1.add(u[x],v[x]),allmt2.add(color[x]);
            for(int i=0;i<(int)cur.size();i++)
                for(int j=0;j<(int)cur.size();j++)
                {
                    if(i==j) continue;
                    vmt1[i].add(u[cur[j]],v[cur[j]]);
                }
            for(int i=1;i<=n;i++)
            {
                if(has[i]) continue;
                if(allmt1.test(u[i],v[i])) {que.push(i); vis[i]=true;}
            }
            for(int i=1;i<=n;i++)
            {
                if(has[i]) continue;
                if(allmt2.test(color[i])) sink[i]=true;
            }
            int last=-1;
            while(que.size())
            {
                int x=que.front(); que.pop();
                if(sink[x]) {last=x; break;}
                for(int i=1;i<=n;i++)
                {
                    if(vis[i]) continue;
                    if(has[i]==has[x]) continue;
                    if(has[x])
                    {
                        if(vmt1[id[x]].test(u[i],v[i])) enqueue(i,x);
                    }
                    else
                    {
                        allmt2.dec(color[i]);
                        if(allmt2.test(color[x])) enqueue(i,x);
                        allmt2.add(color[i]);
                    }
                }
            }
            if(last==-1) return cur;
            while(last)
            {
                has[last]^=1;
                last=pre[last];
            }
        }
    }
};
//Pick Your Own Nim
//In real cases, Linear Matroid Need Optimization to Pass
int tot=0;
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        ++tot;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&color[i]);
            if(u[i]==v[i])
            {
                m--;
                i--;
            }
        }
        printf("Instancia %d\n",tot);
        MatroidIntersection<GraphMatroid,ColorfulMatroid> matint(m);
        vector<int> res=matint.run();
        if(res.size()==n-1) puts("sim\n"); else puts("nao\n");
    }
    return 0;
}

