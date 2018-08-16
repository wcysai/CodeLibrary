/*************************************************************************
    > File Name: 3685.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-16 19:51:52
 ************************************************************************/

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
int n,m,save[MAXN],L[4*MAXN],R[4*MAXN];
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
struct segtree
{
    int val[4*MAXN];
    void build(int k,int l,int r)
    {
        L[k]=l; R[k]=r;
        if(l==r) {save[l]=k; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void merge(int k)
    {
        val[k]=val[k*2]+val[k*2+1];
    }
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r) 
        {
            val[k]+=v; 
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v);
        else update(k*2+1,mid+1,r,p,v);
        merge(k);
    }
    int getmin(int k,int l,int r)
    {
        if(l==r) return l; 
        int mid=(l+r)/2;
        if(val[k*2]) return getmin(k*2,l,mid); else return getmin(k*2+1,mid+1,r);
    }
    int getmax(int k,int l,int r)
    {
        if(l==r) return l; 
        int mid=(l+r)/2;
        if(!val[k*2+1]) return getmax(k*2,l,mid); else return getmax(k*2+1,mid+1,r);
    }
    int find(int x)
    {
       if(val[save[x]]) return 1; else return -1; 
    }
    void insert(int x)
    {
        if(find(x)==1) return;
        update(1,1,n,x,1);
    }
    void del(int x)
    {
        if(find(x)==-1) return;
        update(1,1,n,x,-1);
    }
    int Min()
    {
        if(val[1]==0) return -1;
        return getmin(1,1,n)-1;
    }
    int Max()
    {
        if(val[1]==0) return -1;
        return getmax(1,1,n)-1;
    }
    int getnext(int x)
    {
        int k=save[x];
        while(k>1)
        {
            if(k&1) {k=k/2; continue;}
            k=k/2;
            if(val[k*2+1]) return getmin(k*2+1,L[k*2+1],R[k*2+1])-1;
        }
        return -1;
    }
    int getprev(int x)
    {
        int k=save[x];
        while(k>1)
        {
            if(!(k&1)) {k=k/2; continue;}
            k=k/2;
            if(val[k*2]) return getmax(k*2,L[k*2],R[k*2])-1;
        }
        return -1;
    }
}seg;
int main()
{
    in(n);in(m);
    seg.build(1,1,n);
    int type,x;
    for(int i=0;i<m;i++)
    {
        in(type);
        if(type==3) {out_int(seg.Min()); out_char('\n');}
        else if(type==4) {out_int(seg.Max()); out_char('\n');}
        else
        {
            in(x); x++;
            if(type==1) seg.insert(x);
            else if(type==2) seg.del(x);
            else if(type==5) {out_int(seg.getprev(x)); out_char('\n');}
            else if(type==6) {out_int(seg.getnext(x)); out_char('\n');}
            else {out_int(seg.find(x)); out_char('\n');}
        }
        write();
    }
    return 0;
}

