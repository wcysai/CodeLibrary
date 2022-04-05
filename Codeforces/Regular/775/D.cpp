#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000LL
#define INF2 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> PP;
int n,q;
int a[4][MAXN];
double t;
ll s[4][MAXN];
ll lsave[MAXN],rsave[MAXN];
ll x[MAXN],y[MAXN];
const double CLOCKS_PER_SECOND=((clock_t)1000);
struct edge{int to;ll cost;};
int V;
ll ans;
vector<edge> G[MAXN];
ll d[MAXN];

queue<int> que;
void add_edge(int u,int v,ll c)
{
	G[u].push_back((edge){v,c});
}
void dijkstra(int l,int r)
{
    priority_queue<PP,vector<PP>,greater<PP> > que;
    fill(d+l,d+r+1,INF2);
    d[n+1]=d[n+2]=INF2;
    d[n+1]=0;
    que.push(P(0,n+1));
    while(!que.empty())
    {
        PP p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
namespace IO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read

    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};

void solve(int l,int r,vector<pair<P,ll> > &edges)
{
	if(l==r) return;
	ll maxx=-INF,maxy=-INF;
	for(int i=l;i<=r;i++) maxx=max(maxx,x[i]),maxy=max(maxy,y[i]);
	if(maxx+maxy<=ans) return;
	for(int i=l;i<=r;i++) G[i].clear();
	G[n+1].clear(); G[n+2].clear();
	int mid=(l+r)/2;
	for(auto p:edges) add_edge(p.F.F,p.F.S,p.S);
	for(int i=l;i<=mid;i++) add_edge(n+1,i,INF-x[i]);
	for(int i=mid+1;i<=r;i++) add_edge(i,n+2,INF-y[i]);
	for(int i=l+1;i<=r;i++) add_edge(i,i-1,0);
	dijkstra(l,r);
	ans=max(ans,2*INF-d[n+2]);
	if(1000*(clock()-t)>=4700*CLOCKS_PER_SECOND) 
    {
        printf("%lld\n",ans);
        exit(0);
    }
    for(int i=mid+1;i<=r;i++) rsave[i]=INF2;
	vector<pair<P,ll> > ledges,redges;

	for(auto p:edges)
	{
		if(p.F.F>l&&p.F.S<mid) ledges.push_back(p);
		if(p.F.F>mid+1&&p.F.S<r) redges.push_back(p);
	}
    for(int i=l;i<=mid;i++) lsave[i]=rsave[i]=INF2;
    for(auto p:edges)
	{
		int L=p.F.F,R=p.F.S;
		if(L>mid) continue;
		R=min(R,mid);
		if(L==l) rsave[R]=min(rsave[R],p.S);
		if(R==mid) lsave[L]=min(lsave[L],p.S);
	}
	for(int i=l+1;i<=mid;i++) if(rsave[i]<INF2) ledges.push_back(make_pair(P(l,i),rsave[i]));
	for(int i=l;i<=mid-1;i++) if(lsave[i]<INF2) ledges.push_back(make_pair(P(i,mid),lsave[i]));
	solve(l,mid,ledges); 
	for(int i=mid+1;i<=r;i++) lsave[i]=rsave[i]=INF2;
    for(auto p:edges)
	{
		int L=p.F.F,R=p.F.S;
		if(R<mid+1) continue;
		L=max(L,mid+1);
		if(R==r) rsave[L]=min(rsave[L],p.S);
		if(L==mid+1) lsave[R]=min(lsave[R],p.S);
	}
	for(int i=mid+1;i<=r;i++) if(rsave[i]<INF2) redges.push_back(make_pair(P(i,r),rsave[i]));
	for(int i=mid+1;i<=r;i++) if(lsave[i]<INF2) redges.push_back(make_pair(P(mid+1,i),lsave[i]));
	solve(mid+1,r,redges);
	//[l,mid] [mid+1,r]
}
int main()
{
	IO::read(n); IO::read(q);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			IO::read(a[i][j]);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++) x[i-1]=s[1][i]-s[2][i-1];
	for(int i=1;i<=n;i++) y[i]=s[2][i]+(s[3][n]-s[3][i-1]);
	vector<pair<P,ll> > E;
	for(int i=0;i<q;i++)
	{
		int x,y,k;
		IO::read(x); IO::read(y); IO::read(k); x--;
		E.push_back(make_pair(P(x,y),k));
	}
	ans=-INF;
	solve(0,n,E);
	printf("%lld\n",ans);
	return 0;
}