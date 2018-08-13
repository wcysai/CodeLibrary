/*************************************************************************
    > File Name: 5737.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 19:33:27
 ************************************************************************/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,a[MAXN],b[MAXN];
int pool[MAXM],pl[MAXM],pr[MAXM];
int tot=0;
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
struct segtree
{
    int lazy[4*MAXN],cnt[4*MAXN],st[4*MAXN],ed[4*MAXN];
    void Lazy(int k)
    {
        if(lazy[k]==-1) return;
        int pos=lazy[k];
        lazy[k*2]=pl[pos];lazy[k*2+1]=pr[pos];
        cnt[k*2]=pl[pos]?pl[pos]-st[k*2]+1:0;
        cnt[k*2+1]=pr[pos]?pr[pos]-st[k*2+1]+1:0;
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        if(l==r) 
        {
            st[k]=++tot;ed[k]=tot;
            pool[tot]=b[l];
            if(a[l]>=b[l]) cnt[k]=1; else cnt[k]=0;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        cnt[k]=cnt[k*2]+cnt[k*2+1];
        int l1=st[k*2],r1=ed[k*2],l2=st[k*2+1],r2=ed[k*2+1];
        st[k]=tot+1;
        while(l1<=r1&&l2<=r2)
            pool[++tot]=pool[l1]<=pool[l2]?pool[l1++]:pool[l2++];
        while(l1<=r1) pool[++tot]=pool[l1++];
        while(l2<=r2) pool[++tot]=pool[l2++];
        ed[k]=tot;
        l1=st[k*2],l2=st[k*2+1];
        for(int i=st[k];i<=ed[k];i++)
        {
            while(l1<=r1&&pool[l1]<=pool[i]) l1++;
            while(l2<=r2&&pool[l2]<=pool[i]) l2++;
            pl[i]=l1-1,pr[i]=l2-1;
            if(pl[i]<st[k*2]) pl[i]=0;
            if(pr[i]<st[k*2+1]) pr[i]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int pos)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            cnt[k]=pos?pos-st[k]+1:0;
            lazy[k]=pos;
            return;
        }
        Lazy(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,pl[pos]);update(k*2+1,mid+1,r,x,y,pr[pos]);
        cnt[k]=cnt[k*2]+cnt[k*2+1];
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return cnt[k];
        Lazy(k);
        int mid=(l+r)/2;
        return query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y);
    }
    int find_pos(int x)
    {
        if(pool[st[1]]>x) return 0;
        int l=st[1],r=ed[1]+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(pool[mid]<=x) l=mid; else r=mid;
        }
        return l;
    }
    void debug(int k,int l,int r)
    {
        printf("%d %d %d %d\n",l,r,lazy[k],cnt[k]);
        if(l==r) return;
        Lazy(k);
        int mid=(l+r)/2;
        debug(k*2,l,mid);debug(k*2+1,mid+1,r);
    }
}seg;
int A,B,C=~(1<<31),M=(1<<16)-1;
int rnd(int last)
{
    A=(36969+(last>>3))*(A&M)+(A>>16);
    B=(18000+(last>>3))*(B&M)+(B>>16);
    return (C&((A<<16)+B))%1000000000;
}
int main()
{
    in(T);
    while(T--)
    {
        tot=0;
        int lastans=0,ret=0;
        in(n);in(m);in(A);in(B);
        for(int i=1;i<=n;i++) in(a[i]);
        for(int i=1;i<=n;i++) in(b[i]);
        seg.build(1,1,n);
        for(int i=1;i<=m;i++)
        {
            int l=rnd(lastans)%n+1,r=rnd(lastans)%n+1,x=rnd(lastans)+1;
            assert(l>=1&&l<=n);assert(r>=1&&r<=n);
            if(l>r) swap(l,r);
            //printf("%d %d %d\n",l,r,x);
            if((l+r+x)&1) seg.update(1,1,n,l,r,seg.find_pos(x));
            else
            {
                lastans=seg.query(1,1,n,l,r);
                //printf("ans=%d\n",lastans);
                ret=(1LL*i*lastans+ret)%MOD;
            }
            //seg.debug(1,1,n);
        }
        printf("%d\n",ret);
    }
    return 0;
}

