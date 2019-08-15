#pragma GCC optimize(3)
#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
bool centroid[MAXN],leaf[MAXN];
int sz[MAXN],deep[MAXN],d[MAXN];
bool own[MAXN];
vector<int> save[MAXN];
const double PI=acos(-1.0);
namespace fft
{
    struct num
    {
        double x,y;
        num() {x=y=0;}
        num(double x,double y):x(x),y(y){}
    };
    inline num operator+(num a,num b) {return num(a.x+b.x,a.y+b.y);}
    inline num operator-(num a,num b) {return num(a.x-b.x,a.y-b.y);}
    inline num operator*(num a,num b) {return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
    inline num conj(num a) {return num(a.x,-a.y);}
    int base=1;
    vector<num> roots={{0,0},{1,0}};
    vector<int> rev={0,1};
    const double PI=acosl(-1.0);
    void ensure_base(int nbase)
    {
        if(nbase<=base) return;
        rev.resize(1<<nbase);
        for(int i=0;i<(1<<nbase);i++) rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
        roots.resize(1<<nbase);
        while(base<nbase)
        {
            double angle=2*PI/(1<<(base+1));
            for(int i=1<<(base-1);i<(1<<base);i++)
            {
                roots[i<<1]=roots[i];
                double angle_i=angle*(2*i+1-(1<<base));
                roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
            }
            base++;
        }
    }
    void fft(vector<num> &a,int n=-1)
    {
        if(n==-1) n=a.size();
        assert((n&(n-1))==0);
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for(int i=0;i<n;i++)
            if(i<(rev[i]>>shift))
                swap(a[i],a[rev[i]>>shift]);
        for(int k=1;k<n;k<<=1)
        {
            for(int i=0;i<n;i+=2*k)
            {
                for(int j=0;j<k;j++)
                {
                    num z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }

    vector<num> fa,fb;

    vector<int> multiply(vector<int> &a, vector<int> &b)
    {
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<sz;i++)
        {
            int x=(i<(int)a.size()?a[i]:0);
            int y=(i<(int)b.size()?b[i]:0);
            fa[i]=num(x,y);
        }
        fft(fa,sz);
        num r(0,-0.25/sz);
        for(int i=0;i<=(sz>>1);i++)
        {
            int j=(sz-i)&(sz-1);
            num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
            if(i!=j) fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
            fa[i]=z;
        }
        fft(fa,sz);
        vector<int> res(need);
        for(int i=0;i<need;i++) res[i]=fa[i].x+0.5;
        return res;
    }
};
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
P getroot(int v,int p,int t)
{
    //printf("getroot %d\n",v);
    P res=P(INT_MAX,-1);
    int m=0;
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p,int rt,int d)
{
    if(leaf[v])
    {
        if((int)save[rt].size()<=d) save[rt].resize(d+1);
        save[rt][d]=1;
    }
    for(auto to:G[v])
    {
        if(to==p||centroid[to]) continue;
        getdeep(to,v,rt,d+1);
    }
}
void solve(int v)
{
    centroid[v]=true;
    int SZ=0;
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        save[to].clear(); save[to].resize(1); getdeep(to,v,to,1); SZ=max(SZ,(int)save[to].size());
    }
    if(SZ==0) return;
    vector<int> ans; ans.clear(); ans.resize(SZ);
    int tot=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(centroid[to]) continue;
        if(leaf[v])
        {
            for(int i=0;i<(int)save[to].size();i++) if(save[to][i]) own[i]=true;
        }
        tot++;
        if(tot>=2)
        {
            vector<int> tmp=fft::multiply(save[to],ans);
            for(int i=0;i<(int)tmp.size();i++) if(tmp[i]) own[i]=true;
        }
        for(int i=0;i<(int)save[to].size();i++) if(save[to][i]) ans[i]=1;
    }
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void run()
{
    memset(own,false,sizeof(own));
    memset(centroid,false,sizeof(centroid));
    memset(leaf,false,sizeof(leaf));
    for(int i=1;i<=n;i++) if((int)G[i].size()==1) leaf[i]=true;
    int rt=getroot(1,0,n).S;
    solve(rt);
    ll ans=0;
    vector<int> has; has.clear();
    for(int i=1;i<=n;i++) if(own[i]) has.push_back(i);
    printf("%d\n",(int)has.size());
    for(auto x:has) printf("%d\n",x);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    run();
    return 0;
}
