#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 4000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,tot;
int a[MAXN][4];
int best[MAXM],lson[MAXM],rson[MAXM];
int save[355];
ll f(int id,int x)
{
    ll res=1,ret=0;
    for(int i=0;i<=3;i++){
        ret+=res*a[id][i];
        if(i!=3) res*=x;
    }
    return ret;
}
void insert(int &k,int l,int r,int x,int y,int id)
{
    if(l>y||x>r) return;
    if(!k) k=++tot;
    if(l>=x&&r<=y)
    {
        if(best[k]==-1)
        {
            best[k]=id;
            return;
        }
        ll trl=f(best[k],l),trr=f(best[k],r);
        ll vl=f(id,l),vr=f(id,r);
        if(trl<=vl&&trr<=vr) return;
        if(trl>=vl&&trr>=vr) {best[k]=id; return;}
        int mid=(l+r)/2;
        if(trl>=vl) swap(best[k],id);
        if(f(best[k],mid)<=f(id,mid)) insert(rson[k],mid+1,r,x,y,id);
        else swap(best[k],id),insert(lson[k],l,mid,x,y,id);
        return;
    }
    int mid=(l+r)/2;
    insert(lson[k],l,mid,x,y,id); insert(rson[k],mid+1,r,x,y,id);
}
ll query(int &k,int l,int r,int x)
{
    if(!k) return INF;
    ll res=(best[k]==-1?INF:f(best[k],x));
    if(l==r) return res;
    int mid=(l+r)/2;
    if(x<=mid) return min(res,query(lson[k],l,mid,x));
    else return min(res,query(rson[k],mid+1,r,x));
}
void clear(){
    for(int i=1;i<=tot;i++){
        lson[i]=rson[i]=0;
        best[i]=-1;
    }
    tot=0;
}
int main()
{
    memset(best,-1,sizeof(best));
    scanf("%d",&T);
    while(T--){
        clear();
        scanf("%d",&n);
        for(int i=1;i<=350;i++) save[i]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<4;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=350;i++)
            for(int j=2;j<=n;j++)
                if(f(save[i],i)>f(j,i)) save[i]=j;
        int root=0;
        for(int i=1;i<=n;i++)
            insert(root,351,100000,351,100000,i);
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int x; scanf("%d",&x);
            if(x<=350) printf("%lld\n",f(save[x],x));
            else printf("%lld\n",query(root,351,100000,x));
        }
    }
    return 0;
}

