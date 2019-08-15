#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
struct segtree
{
    int suma[4*MAXN],sumb[4*MAXN],adda[4*MAXN],addb[4*MAXN],sum[4*MAXN];
    void pushup(int k)
    {
        suma[k]=suma[k*2]; add(suma[k],suma[k*2+1]);
        sumb[k]=sumb[k*2]; add(sumb[k],sumb[k*2+1]);
        sum[k]=sum[k*2]; add(sum[k],sum[k*2+1]);
    }
    void pushdown(int k,int l,int r)
    {
        int mid=(l+r)/2;
        if(adda[k])
        {
            int addl=1LL*(mid-l+1)*adda[k]%MOD,addr=1LL*(r-mid)*adda[k]%MOD;
            for(int i=k*2;i<=k*2+1;i++)
            {
                add(adda[i],adda[k]);
                add(sum[i],1LL*sumb[i]*adda[k]%MOD);
            }
            add(suma[k*2],addl); add(suma[k*2+1],addr);
            adda[k]=0;
        }
        if(addb[k])
        {
            int addl=1LL*(mid-l+1)*addb[k]%MOD,addr=1LL*(r-mid)*addb[k]%MOD;
            for(int i=k*2;i<=k*2+1;i++)
            {
                add(addb[i],addb[k]);
                add(sum[i],1LL*suma[i]*addb[k]%MOD);
            }
            add(sumb[k*2],addl); add(sumb[k*2+1],addr);
            addb[k]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int type,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            if(!type) {add(adda[k],v); add(suma[k],1LL*(r-l+1)*v%MOD); add(sum[k],1LL*v*sumb[k]%MOD);}
            else {add(addb[k],v); add(sumb[k],1LL*(r-l+1)*v%MOD); add(sum[k],1LL*v*suma[k]%MOD);}
            return;
        }
        pushdown(k,l,r);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,type,v); update(k*2+1,mid+1,r,x,y,type,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        pushdown(k,l,r);
        int mid=(l+r)/2;
        int res=query(k*2,l,mid,x,y);
        add(res,query(k*2+1,mid+1,r,x,y));
        return res;
    }
}seg;
int n,m;
char ch[5];
int main()
{
    scanf("%d%d",&n,&m);
    int l,r,x;
    for(int i=0;i<m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='*') {scanf("%d%d%d",&l,&r,&x); seg.update(1,1,n,l,r,0,x);}
        else if(ch[0]=='.') {scanf("%d%d%d",&l,&r,&x); seg.update(1,1,n,l,r,1,x);}
        else
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",seg.query(1,1,n,l,r));
        }
    }
    return 0;
}
