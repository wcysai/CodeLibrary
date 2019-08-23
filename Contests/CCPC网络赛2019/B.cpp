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
int T,n,m,a[MAXN];
int val[MAXN],leaf[MAXN];
struct segtree
{
    int maxpos[4*MAXN],lb[4*MAXN],rb[4*MAXN];
    void pushup(int k)
    {
        maxpos[k]=max(maxpos[k*2],maxpos[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        lb[k]=l; rb[k]=r;
        if(l==r)
        {
            leaf[l]=k;
            maxpos[k]=val[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p)
    {
        if(l==r)
        {
            maxpos[k]=INF;
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p); else update(k*2+1,mid+1,r,p);
        pushup(k);
    }
    int query(int pos,int val)
    {
        int k=leaf[val];
        if(maxpos[k]>pos) return val;
        do
        {
            if(k%2==0&&maxpos[k+1]>pos)
            {
                k++;
                int l=lb[k],r=rb[k];
                while(l<r)
                {
                    int mid=(l+r)/2;
                    if(maxpos[k*2]>pos) {r=mid; k=k*2;} else {l=mid+1; k=k*2+1;}
                }
                return l;
            }
            k=k/2;
        }while(k);
        assert(0);//should not reach here
    }
}seg;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n+1;i++) val[i]=INF;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) val[a[i]]=i;
        seg.build(1,1,n+1);
        int lastans=0;
        for(int i=0;i<m;i++)
        {
            int type,x,y;
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d",&x);
                x=x^lastans;
                seg.update(1,1,n+1,a[x]);
            }
            else
            {
                scanf("%d%d",&x,&y);
                x^=lastans; y^=lastans;
                lastans=seg.query(x,y);
                printf("%d\n",lastans);
            }
        }
    }
    return 0;
}
