#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define for1(a,b,i) for(int i=a;i<=b;++i)
#define FOR2(a,b,i) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
char xch,xB[1<<15],*xS=xB,*xTT=xB;
#define getc() (xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xTT)?0:*xS++)
inline int read() {
    int x=0,f=1;
    char ch=getc();
    while(ch<'0'|ch>'9'){if(ch=='-')f=-1;ch=getc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
    return x*f;
}

#define M 3005
#define N 100005
int n,m,K;
int a[M][M],size[N],sum[M][M];

struct node {
    int c;
    short x,y;
}buc[M*M];

struct point {
    short l,r;
    
    inline bool operator <(const point &a) const {
        return l<a.l;
    }
};

multiset <point> cc;
multiset <point>::iterator it,i;

inline void add_(int x,int l,int r,bool t) {
    if(x>n) return;
    if(!t) cc.insert((point){l,r});
    it=cc.lower_bound((point){l,r});
    int lx,rx;
    if(it==cc.begin()) lx=0;
    else i=it,i--,lx=(*i).r;
    i=it,i++;
    rx=i==cc.end()?m+1:(*i).l;
    ++lx,--rx;
    lx=max(lx,l),rx=min(rx,r);
    if(lx<=rx) {
        int k=t?-1:1;
        sum[x][lx]+=k;
        sum[x][rx+1]-=k;
    }
    if(t) cc.erase(it);
}

void solve_(int l,int r) {
    int h1=l-1,h2=l-1;
    while (h1<r&&h2<r) {
        int t0=buc[h1+1].x;
        int t1=buc[h2+1].x+K;
        if(t0<=t1) ++h1,add_(t0,buc[h1].y,buc[h1].y+K-1,0);
        if(t1<=t0) ++h2,add_(t1,buc[h2].y,buc[h2].y+K-1,1);
    }
    for1(h2+1,r,i) add_(buc[i].x+K,buc[i].y,buc[i].y+K-1,1);
    cc.clear();
}

int main () {
//    freopen("a.in","r",stdin);
    n=read(),m=read(),K=read();
    for1(1,n,i) for1(1,m,j) {
        a[i][j]=read();
        ++size[a[i][j]];
    }
    for1(1,100000,i) size[i]+=size[i-1];
    FOR2(n,1,i) FOR2(m,1,j) buc[size[a[i][j]]--]=(node){a[i][j],i,j};
    
    int l=1,r;
    while (l<=n*m) {
        r=l;
        while (buc[r+1].c==buc[l].c) ++r;
        solve_(l,r);
        l=r+1;
    }
    for1(1,n,i) {
        for1(1,m,j) sum[i][j]+=sum[i][j-1];
        for1(1,m,j) sum[i][j]+=sum[i-1][j];
    }
    ll tot=0;
    int ans=0;
    for1(K,n,i) for1(K,m,j) tot+=sum[i][j],ans=max(ans,sum[i][j]);
    printf("%d %lld\n",ans,tot);
}
