/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 16:44:25
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MODO 1000000007
#define MAXN 100005
#define INF 1000000000
#define BASE 19260817
#define hash jsadoskdos
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
ll n,t,tot;
multiset<ll> a;
map<ll,int> mp;
multiset<ll> cyc[MAXN];
ll find_hash(multiset<ll> v)
{
    ll cur=0;
    for(auto it:v) cur=(1LL*cur*BASE+it)%MODO;
    return cur;
}
void hash()
{
    ll cur=find_hash(a);
    mp[cur]=++tot;
    for(auto it:a) cyc[tot].insert(it);
}
void dfs(ll n,ll last)
{
    if(n==0) {hash(); return;}
    for(ll i=last;i<=n;i++)
    {
        a.insert(i);
        dfs(n-i,i);
        a.erase(a.find(i));
    }
}
int prime[6]={2,3,5,7,11,13};
//we only need to deal with 2,3,5,7,11,13
class BigNum {
public:
    static const int MOD = 100000000;
    static const int BIT = 8, SIZE = 105;
    mutable int n,o;
    long long u[SIZE];
    BigNum(){}
    BigNum(const string& s){
        memset(this,0,sizeof(BigNum));
        int num=0,cnt=1;
        for(int i=s.size()-1;~i;i--){
            if(s[i]=='-') o^=1;
            if(s[i]>='0' && s[i]<='9'){
                num+=(s[i]-'0')*cnt;
                cnt*=10;
                if(cnt==MOD) u[n++]=num,num=0,cnt=1;
            }
        }
        if(!n || cnt>=10) u[n++]=num;
        if(!u[0] && n==1) o=0;
    }
    BigNum(long long x){
        memset(this,0,sizeof(BigNum));
        if(x<0) o=1,x=-x;
        do u[n++]=x%MOD; while(x/=MOD);
    }
    operator string() const {
        static char s[SIZE*BIT+10];
        char* c=s+sprintf(s,"%s%d",o?"-":"",int(u[n-1]));
        for(int i=n-2;~i;i--) c+=sprintf(c,"%0*d",BIT,int(u[i]));
        return s;
    }
    int operator [](int pos) const {
        static int e[BIT]={1};
        for(static int i=1;i<BIT;i++) e[i]=e[i-1]*10;
        return u[pos/BIT]/e[pos%BIT]%10;
    }
    int length() const {
        int ret=(n-1)*BIT+1;
        for(int x=u[n-1]/10;x;x/=10) ret++;
        return ret;
    }
    friend int cmp(const BigNum& l, const BigNum& r){
        if(l.o!=r.o) return (l.o?-1:1);
        if(l.n!=r.n) return (l.o?-1:1)*(l.n-r.n);
        for(int i=l.n-1;~i;i--) if(l.u[i]-r.u[i])
                return (l.o?-1:1)*(l.u[i]-r.u[i]);
        return 0;
    }
    bool operator < (const BigNum& r) const {return cmp(*this,r)<0;}
    bool operator > (const BigNum& r) const {return cmp(*this,r)>0;}
    bool operator <=(const BigNum& r) const {return cmp(*this,r)<=0;}
    bool operator >=(const BigNum& r) const {return cmp(*this,r)>=0;}
    bool operator ==(const BigNum& r) const {return cmp(*this,r)==0;}
    bool operator !=(const BigNum& r) const {return cmp(*this,r)!=0;}
    BigNum operator +(const BigNum& r) const {return BigNum(*this)+=r;}
    BigNum operator -(const BigNum& r) const {return BigNum(*this)-=r;}
    BigNum operator *(int x) const {return BigNum(*this)*=x;}
    BigNum operator /(int x) const {return BigNum(*this)/=x;}
    BigNum& operator *=(const BigNum& r){return *this=*this*r;}
    BigNum& operator /=(const BigNum& r){return *this=*this/r;}
    BigNum& operator %=(const BigNum& r){return *this=*this%r;}
    BigNum& operator %=(int x){return *this=*this%x;}
    BigNum operator -() const {
        BigNum s=*this;
        if(s.u[0] || s.n>=2) s.o^=1;
        return s;
    }
    BigNum& operator +=(const BigNum& r){
        if(r.n==1 && !r.u[0]) return *this;
        if(r.o^o) return r.o^=1,*this-=r,r.o^=1,*this;
        if(r.n>n) n=r.n;
        for(int i=0;i<r.n;i++) u[i]+=r.u[i];
        for(int i=0;i<n;i++) if(u[i]>=MOD) u[i+1]++,u[i]-=MOD;
        if(u[n]) n++;
        return *this;
    }
    BigNum& operator -=(const BigNum& r){
        if(r.n==1 && !r.u[0]) return *this;
        if(r.o^o) return r.o^=1,*this+=r,r.o^=1,*this;
        if(cmp(*this,r)*(r.o?-1:1)<0){
            o^=1,n=r.n;
            for(int i=0;i<r.n;i++) u[i]=r.u[i]-u[i];
        }else{
            for(int i=0;i<r.n;i++) u[i]=u[i]-r.u[i];
        }
        for(int i=0;i<n;i++) if(u[i]<0) u[i+1]--,u[i]+=MOD;
        while(!u[n-1] && n>=2) --n;
        if(!u[0] && n==1) o=0;
        return *this;
    }
    BigNum operator *(const BigNum& r) const {
        BigNum s=0;
        if(!u[n-1] || !r.u[r.n-1]) return s;
        s.n=r.n+n-1;
        s.o=r.o^o;
        for(int i=0;i<n;i++) for(int j=0;j<r.n;j++)
            s.u[i+j]+=u[i]*r.u[j];
        for(int i=0;i<s.n;i++) if(s.u[i]>=MOD){
            s.u[i+1]+=s.u[i]/MOD;
            s.u[i]%=MOD;
            if(i==s.n-1) s.n++;
        }
        return s;
    }
    BigNum operator /(const BigNum& r) const {
        BigNum e[35],s=0,c=0;
        int m=0,ro=r.o,lo=o;
        r.o^=ro,o^=lo;
        for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
        for(int i=n-1;~i;i--){
            int tag=0;
            (s*=MOD)+=u[i];
            for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x],tag|=1<<x;
            (c*=MOD)+=tag;
        }
        r.o^=ro,o^=lo;
        if(c.u[0] || c.n>=2) c.o=r.o^o;
        return c;
    }
    BigNum operator %(const BigNum& r) const {
        BigNum e[35],s=0;
        int m=0,ro=r.o,lo=o;
        r.o^=ro,o^=lo;
        for(e[m]=r;MOD>>++m;e[m]=e[m-1]+e[m-1]);
        for(int i=n-1;~i;i--){
            (s*=MOD)+=u[i];
            for(int x=m-1;~x;x--) if(s>=e[x]) s-=e[x];
        }
        r.o^=ro,o^=lo;
        if(s.u[0] || s.n>=2) s.o=o;
        return s;
    }
    BigNum& operator *=(int x){
        if(!x) return *this=0;
        if(x<0) o^=1,x=-x;
        for(int i=0;i<n;i++) u[i]*=x;
        for(int i=0;i<n;i++) if(u[i]>=MOD){
            u[i+1]+=u[i]/MOD;
            u[i]%=MOD;
            if(i==n-1) n++;
        }
        if(!u[0] && n==1) o=0;
        return *this;
    }
    BigNum& operator /=(int x){
        if(x<0) o^=1,x=-x;
        for(int i=n-1;i;u[i--]/=x) u[i-1]+=u[i]%x*MOD;
        for(u[0]/=x;n>=2;n--) if(u[n-1]) break;
        if(!u[0] && n==1) o=0;
        return *this;
    }
    int operator %(int x) const {
        long long c=0;
        for(int i=n-1;~i;i--) c=(c*MOD+u[i])%x;
        return (1-o-o)*int(c);
    }
    void print()
    {
        int len=length();
        bool zero=true;
        for(int i=len-1;i>=0;i--)
        {
            if(u[i]!=0) zero=false;
            if(!zero) printf("%lld",u[i]);
        }
    }
};
struct frac
{
    bool iszero;
    int p[6],q[6];
    void clear() {iszero=true; }
    frac(){}
    frac(int _p,int _q)
    {
        assert(_q!=0);
        if(_p==0) {iszero=true;}
        else
        {
            memset(p,0,sizeof(p));memset(q,0,sizeof(q));
            iszero=false;
            for(int i=0;i<6;i++)
                while(_p%prime[i]==0) {_p=_p/prime[i]; p[i]++;}
            for(int i=0;i<6;i++)
                while(_q%prime[i]==0) {_q=_q/prime[i]; q[i]++;}
        }
    }
    void norm()
    {
        if(!iszero)
        {
            for(int i=0;i<6;i++)
            {
                int x=min(p[i],q[i]);
                p[i]-=x;q[i]-=x;
            }
        }
    }
    frac operator+(frac y) 
    {
        frac tmp;
        if(iszero) {tmp=y; return tmp;}
        else if(y.iszero) return *this;
        tmp.iszero=false;
        BigNum l=1,r=1;
        for(int i=0;i<6;i++)
        {
            int need=max(q[i],y.q[i]);
            p[i]+=need-q[i];y.p[i]+=need-y.q[i];
            tmp.q[i]=need;
        }
        for(int i=0;i<6;i++)
        {
            int x=min(p[i],y.p[i]);
            for(int j=0;j<p[i]-x;j++)
                l=l*prime[i];
            for(int j=0;j<y.p[i]-x;j++)
                r=r*prime[i];
            tmp.p[i]=x;
        }
        l=l+r;
        //l.print();printf("\n");
        for(int i=0;i<6;i++)
            while(l%prime[i]==0) l=l/prime[i],tmp.p[i]++;
        return tmp;
    }
    frac operator*(frac y) 
    {
        frac tmp;
        if(iszero||y.iszero) {tmp.iszero=true; return tmp;}
        tmp.iszero=false;
        for(int i=0;i<6;i++)
        {
            tmp.p[i]=p[i]+y.p[i];
            tmp.q[i]=q[i]+y.q[i];
        }
        return tmp;
    }
    void print()
    {
        if(iszero) {printf("0/1"); return;}
        BigNum l=1,r=1;
        for(int i=0;i<6;i++)
            for(int j=0;j<p[i];j++) 
                l=l*prime[i];
        l.print();
        printf("/");
        for(int i=0;i<6;i++)
            for(int j=0;j<q[i];j++)
                r=r*prime[i];
        r.print();
    }
}dp[305][140];
frac trans[140][140];
int main()
{
    while(scanf("%lld%lld",&n,&t)==2)
    {
        if(!n&&!t) break;
        mp.clear();a.clear();
        tot=0;
        dfs(n,1);
        for(ll i=0;i<=t;i++) 
            for(ll j=1;j<=tot;j++) 
                dp[i][j].clear();
        for(ll i=1;i<=tot;i++)
            for(ll j=1;j<=tot;j++)
                trans[i][j].clear();
        for(ll i=1;i<=tot;i++)
        {
            for(auto j=cyc[i].begin();j!=cyc[i].end();j++)
            {
                auto k=j;k++;
                for(;k!=cyc[i].end();k++)
                {
                    multiset<ll> dummy(cyc[i]);
                    frac coef((*j)*(*k)*2,n*n);coef.norm();
                    dummy.erase(dummy.find(*j));dummy.erase(dummy.find(*k));
                    dummy.insert((*j)+(*k));
                    ll num=mp[find_hash(dummy)];
                    trans[i][num]=(trans[i][num]+coef);trans[i][num].norm();
                }
            }
            for(auto j=cyc[i].begin();j!=cyc[i].end();j++)
            {
                for(ll k=1;k*2<(*j);k++)
                {
                    multiset<ll> dummy(cyc[i]);
                    frac coef((*j)*2,n*n);coef.norm();
                    dummy.erase(dummy.find(*j));
                    dummy.insert(k);dummy.insert((*j)-k);ll num=mp[find_hash(dummy)];
                    trans[i][num]=(trans[i][num]+coef);
                }
                if((*j)%2==0)
                {
                    multiset<ll> dummy(cyc[i]);
                    frac coef((*j),n*n);coef.norm();
                    dummy.erase(dummy.find(*j));dummy.insert((*j)/2);dummy.insert((*j)/2);
                    ll num=mp[find_hash(dummy)];
                    trans[i][num]=(trans[i][num]+coef);
                }
            }
            trans[i][i]=frac(1,n);
        }
        for(int i=1;i<=tot;i++)
        {
            for(int j=1;j<=tot;j++)
            {
                trans[i][j].print();
                printf(" ");
            }
            printf("\n");
        }
        dp[0][1]=frac(1,1);
        puts("");
        for(int i=0;i<=t;i++)
        {
            for(int j=1;j<=tot;j++)
            {
                dp[i][j].print();
                printf(" ");
            }
            printf("\n");
        }
        for(ll i=0;i<t;i++)
        {
            for(ll j=1;j<=tot;j++)
            {
                if(dp[i][j].iszero) continue;
                for(ll k=1;k<=tot;k++)
                {
                    frac tmp=dp[i][j];tmp=tmp*trans[j][k];tmp.norm();
                    //tmp.print();printf(" ");dp[i+1][k].print();printf(" ");
                    dp[i+1][k]=dp[i+1][k]+tmp;dp[i+1][k].norm();
                    //dp[i+1][k].print();printf("\n");
                }
            }
        }
        puts("");
        for(int i=0;i<=t;i++)
        {
            for(int j=1;j<=tot;j++)
            {
                dp[i][j].print();
                printf(" ");
            }
            printf("\n");
        }
        for(ll i=1;i<=n;i++) printf("%lld%c",i,i==n?'\n':' ');
        dp[t][1].norm();
        dp[t][1].print();
        for(ll i=1;i<=tot;i++) cyc[i].clear();
    }
    return 0;
}

