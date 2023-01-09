#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define MAXN 1000005
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double PI=acos(-1.0);
int n;
int fact[MAXN],invf[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
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
vector<int> hori(vector<int> x,int h){
    int w=(int)x.size()-1; 
    vector<int> y(w+1);
    for(int i=0;i<=w;i++) y[i]=comb(i+h,h);
    vector<int> z=fft::multiply_mod(x,y,MOD); z.resize(w+1);
    return z;
}
vector<int> vert(vector<int> x,int h){
    int w=(int)x.size()-1; 
    for(int i=0;i<=w;i++) x[i]=1LL*x[i]*invf[w-i]%MOD;
    vector<int> y(fact,fact+(w+h+1));
    vector<int> z=fft::multiply_mod(x,y,MOD); 
    vector<int> res(h+1);
    for(int i=0;i<=h;i++) res[i]=1LL*z[w+i]*invf[i]%MOD;
    return res;
}
vector<int> solve(vector<int> a,int h,vector<int> ways){
    int cnt=0;
    for(int i=0;i<(int)a.size();i++) if(a[i]<0) cnt++; else break;
    a.erase(a.begin(),a.begin()+cnt); ways.erase(ways.begin(),ways.begin()+cnt);
    int n=(int)a.size(); assert((int)ways.size()==n+1);
    if(n<=150||h<=150){
        vector<int> res(h+1);
        for(int i=0;i<=h;i++){
            for(int j=0;j<n;j++)
                if(a[j]>=i) add(ways[j+1],ways[j]);
            res[i]=ways[n];
        }
        return res;
    }
    int t=(n+h)/2,x=0,y=0;
    while(x+y<t) {
        if(x==n||y<a[x]) y++; else x++;
    }
    vector<int> res(h+1),nx(n-x+1);
    auto ue=hori(vector<int>(ways.begin()+x,ways.end()),y);
    for(int i=0;i<=n-x;i++) nx[i]=ue[i];
    auto migi=vert(vector<int>(ways.begin()+x,ways.end()),y);
    for(int i=0;i<=y;i++) add(res[i],migi[i]);
    if(x){
        auto hidari=solve(vector<int>(a.begin(),a.begin()+x-1),a[x-1],vector<int>(ways.begin(),ways.begin()+x));
        hidari.resize(y+1);
        auto ue=vert(hidari,n-x);
        for(int i=0;i<=n-x;i++) add(nx[i],ue[i]);
        auto migi=hori(hidari,n-x);
        for(int i=0;i<=y;i++) add(res[i],migi[i]);
    }
    if(y<h){
        vector<int> b(a.begin()+x,a.end());
        for(auto &v:b) v-=y+1;
        auto migi=solve(b,h-y-1,nx);
        for(int i=0;i<h-y;i++) res[y+1+i]=migi[i];
    }
    return res;
}
char str[MAXN];
int s[MAXN];
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%s",str+1);
    n=strlen(str+1);
    int id=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='(') s[i]=s[i-1]+1; else s[i]=s[i-1]-1;
        if(s[i]<s[id]) id=i;
    }
    int x=-s[id],y=s[n]-s[id];
    int ans=1;
    if(x){
        int cnt=0;
        for(int i=1;i<=id;i++) if(str[i]==')') cnt++;
        vector<int> a(x);
        for(int i=0;i<x;i++) a[i]=cnt-1;
        int c=0;
        for(int i=1;i<=id;i++){
            if(str[i]==')') c++;    
            if(str[i]==')'&&s[i]<0) a[-s[i]-1]=min(a[-s[i]-1],c+s[i]);  
        }
        vector<int> b(x+1); b[0]=1;
        vector<int> ret=solve(a,a[x-1],b);
        ans=ret[a[x-1]];
    }
    if(y){
        int cnt=0;
        for(int i=id+1;i<=n;i++) if(str[i]=='(') cnt++;
        vector<int> a(y);
        for(int i=0;i<y;i++) a[i]=cnt-1;
        int c=0;
        int ss=0;
        for(int i=n;i>=id-1;i--){
            if(str[i]=='(') {c++; ss--;} else ss++;    
            if(str[i]=='('&&ss<0) a[-ss-1]=min(a[-ss-1],c+ss);  
        }
        vector<int> b(y+1); b[0]=1;
        vector<int> ret=solve(a,a[y-1],b);
        ans=1LL*ans*ret[a[y-1]]%MOD;
    }
    printf("%d\n",ans);
    return 0;
}


