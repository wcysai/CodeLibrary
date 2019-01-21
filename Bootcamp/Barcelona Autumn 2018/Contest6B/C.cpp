/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 02:40:55
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 786433
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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

    ll base=1;
    vector<num> roots={{0,0},{1,0}};
    vector<ll> rev={0,1};
    const double PI=acosl(-1.0);

    void ensure_base(ll nbase)
    {
        if(nbase<=base) return;
        rev.resize(1<<nbase);
        for(ll i=0;i<(1<<nbase);i++)
            rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
        roots.resize(1<<nbase);
        while(base<nbase)
        {
            double angle=2*PI/(1<<(base+1));
            for(ll i=1<<(base-1);i<(1<<base);i++)
            {
                roots[i<<1]=roots[i];
                double angle_i=angle*(2*i+1-(1<<base));
                roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<num> &a,ll n=-1)
    {
        if(n==-1) n=a.size();
        assert((n&(n-1))==0);
        ll zeros=__builtin_ctz(n);
        ensure_base(zeros);
        ll shift=base-zeros;
        for(ll i=0;i<n;i++)
            if(i<(rev[i]>>shift))
                swap(a[i],a[rev[i]>>shift]);
        for(ll k=1;k<n;k<<=1)
        {
            for(ll i=0;i<n;i+=2*k)
            {
                for(ll j=0;j<k;j++)
                {
                    num z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }

    vector<num> fa,fb;
    
    vector<ll> multiply(vector<ll> &a, vector<ll> &b)
    {
        ll need=a.size()+b.size()-1;
        ll nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        ll sz=1<<nbase;
        if(sz>(ll)fa.size()) fa.resize(sz);
        for(ll i=0;i<sz;i++)
        {
            ll x=(i<(ll)a.size()?a[i]:0);
            ll y=(i<(ll)b.size()?b[i]:0);
            fa[i]=num(x,y);
        }
        fft(fa,sz);
        num r(0,-0.25/sz);
        for(ll i=0;i<=(sz>>1);i++)
        {
            ll j=(sz-i)&(sz-1);
            num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
            if(i!=j) fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
            fa[i]=z;
        }
        fft(fa,sz);
        vector<ll> res(need);
        for(ll i=0;i<need;i++) res[i]=fa[i].x+0.5;
        return res;
    }

    vector<ll> multiply_mod(vector<ll> &a,vector<ll> &b,ll m,ll eq=0)
    {
        ll need=a.size()+b.size()-1;
        ll nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        ll sz=1<<nbase;
        if(sz>(ll)fa.size()) fa.resize(sz);
        for(ll i=0;i<(ll)a.size();i++)
        {
            ll x=(a[i]%m+m)%m;
            fa[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
        fft(fa,sz);
        if(sz>(ll)fb.size()) fb.resize(sz);
        if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
        else
        {
            for(ll i=0;i<(ll)b.size();i++)
            {
                ll x=(b[i]%m+m)%m;
                fb[i]=num(x&((1<<15)-1),x>>15);
            }
            fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
            fft(fb,sz);
        }
        double ratio=0.25/sz;
        num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
        for(ll i=0;i<=(sz>>1);i++)
        {
            ll j=(sz-i)&(sz-1);
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
        vector<ll> res(need);
        for(ll i=0;i<need;i++)
        {
            ll aa=fa[i].x+0.5;
            ll bb=fb[i].x+0.5;
            ll cc=fa[i].y+0.5;
            res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
        }
        return res;
    }
    vector<ll> square_mod(vector<ll> &a,ll m)
    {
        return multiply_mod(a,a,m,1);
    }
};
vector<ll> avl[20];
ll n,h;
int main()
{
    scanf("%lld%lld",&n,&h);
    if(n==1) {if(h==0) puts("1"); else puts("0");}
    else if(n==2) {if(h==1) puts("2"); else puts("0");}
    else
    {
        avl[0].resize(n+1);avl[0][1]=1;
        avl[1].resize(n+1);avl[1][2]=2;avl[1][3]=1;
        for(ll i=2;i<=h;i++)
        {
            vector<ll> a;
            a=fft::multiply_mod(avl[i-1],avl[i-2],MOD);
            avl[i].resize(n+1);
            for(ll j=0;j<n;j++) avl[i][j+1]=2LL*a[j]%MOD;
            a=fft::multiply_mod(avl[i-1],avl[i-1],MOD);
            for(ll j=0;j<n;j++) avl[i][j+1]=(avl[i][j+1]+a[j])%MOD;
        }
        printf("%lld\n",avl[h][n]%MOD);
    }
    return 0;
}

