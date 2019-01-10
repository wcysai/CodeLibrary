#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N;
vector<int> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],deep[MAXN],fact[MAXN],invf[MAXN];
int cnt[MAXN];
vector<int> save[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
        for(int i=0;i<(1<<nbase);i++)
            rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
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

    vector<int> multiply_mod(vector<int> &a,vector<int> &b,int m,int eq=0)
    {
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<(int)a.size();i++)
        {
            int x=(a[i]%m+m)%m;
            fa[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
        fft(fa,sz);
        if(sz>(int)fb.size()) fb.resize(sz);
        if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
        else
        {
            for(int i=0;i<(int)b.size();i++)
            {
                int x=(b[i]%m+m)%m;
                fb[i]=num(x&((1<<15)-1),x>>15);
            }
            fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
            fft(fb,sz);
        }
        double ratio=0.25/sz;
        num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
        for(int i=0;i<=(sz>>1);i++)
        {
            int j=(sz-i)&(sz-1);
            num a1=(fa[i]+conj(fa[j]));
            num a2=(fa[i]-conj(fa[j]))*r2;
            num b1=(fb[i]+conj(fb[j]))*r3;
            num b2=(fb[i]-conj(fb[j]))*r4;
            if(i!=j)
            {
                num c1=(fa[j]+conj(fa[i]));
                num c2=(fa[j]-conj(fa[i]))*r2;
                num d1=(fb[j]+conj(fb[i]))*r3;
                num d2=(fb[j]-conj(fb[i]))*r4;
                fa[i]=c1*d1+c2*d2*r5;
                fb[i]=c1*d2+c2*d1;
            }
            fa[j]=a1*b1+a2*b2*r5;
            fb[j]=a1*b2+a2*b1;
        }
        fft(fa,sz);fft(fb,sz);
        vector<int> res(need);
        for(int i=0;i<need;i++)
        {
            ll aa=fa[i].x+0.5;
            ll bb=fb[i].x+0.5;
            ll cc=fa[i].y+0.5;
            res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
        }
        return res;
    }
    vector<int> square_mod(vector<int> &a,int m)
    {
        return multiply_mod(a,a,m,1);
    }
};
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
P getroot(int v,int p,int t)//search_centroid
{
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
void getdeep(int v,int p,int rt,int d)//enumerate path
{
    if((int)save[rt].size()<=d) save[rt].resize(d+1);
    save[rt][d]++;
    for(auto to:G[v])
    {
        if(to==p||centroid[to]) continue;
        getdeep(to,v,rt,d+1);
    }
}
void solve(int v)
{
    //printf("%d\n",v);
    centroid[v]=true;
    int SZ=0;
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        save[to].clear();getdeep(to,v,to,1);SZ=max(SZ,(int)save[to].size());
    }
    if(SZ==0) return;
    vector<int> ans; ans.clear(); ans.resize(SZ);
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        for(int i=0;i<(int)save[to].size();i++) {add(cnt[i],2LL*save[to][i]%MOD); add(ans[i],save[to][i]);}
    }
    ans=fft::square_mod(ans,MOD);
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        vector<int> tmp=fft::square_mod(save[to],MOD);
        for(int i=0;i<(int)tmp.size();i++) dec(ans[i],tmp[i]);
    }
    for(int i=0;i<(int)ans.size();i++) add(cnt[i],ans[i]);
    // for(int i=0;i<(int)ans.size();i++) printf("%d ",cnt[i]);
    // puts("");
    for(auto to:G[v])
    {
        if(centroid[to]) continue;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void ac()
{
    memset(centroid,false,sizeof(centroid));
    memset(cnt,0,sizeof(cnt));
    int rt=getroot(1,0,N).S;
    solve(rt);
    cnt[0]=N;
    //for(int i=0;i<N;i++) printf("%d ",cnt[i]);
    //puts("");
    vector<int> A(N),B(N),ans;
    for(int i=0;i<N;i++) A[i]=1LL*cnt[i]*fact[N-1-i]%MOD;
    for(int i=0;i<N;i++) B[i]=invf[i];
    ans=fft::multiply_mod(A,B,MOD);
    for(int i=0;i<=N-1;i++) printf("%lld ",1LL*ans[N-1-i]*fact[N-1-i]%MOD*invf[N-1]%MOD);
    puts("");
}
int main()
{
    scanf("%d",&N);
    fact[0]=invf[0]=1;
    for(int i=1;i<=N;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[N]=pow_mod(fact[N],MOD-2);
    for(int i=N-1;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);add_edge(u,v);
    }
    ac();
    return 0;
}
