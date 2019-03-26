#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 40000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s,q,tot,cnt,a[MAXN],root[MAXN];
int lson[MAXM],rson[MAXM],minx[MAXM];
int last[MAXN];
void pushup(int k)
{
    if(lson[k]) minx[k]=min(minx[k],minx[lson[k]]);
    if(rson[k]) minx[k]=min(minx[k],minx[rson[k]]);
}
void insert(int &k,int last,int l,int r,int p,int v)
{
    k=++tot;
    minx[k]=minx[last];
    if(minx[k]==0) minx[k]=INF;
    if(l==r) 
    {
        minx[k]=min(minx[k],v); 
        return;
    }
    lson[k]=lson[last];rson[k]=rson[last];
    int mid=(l+r)/2;
    if(p<=mid) insert(lson[k],lson[last],l,mid,p,v);
    else insert(rson[k],rson[last],mid+1,r,p,v);
    pushup(k);
}
int query(int &k,int l,int r,int x,int y)
{
    if(!k) return INF;
    if(x>r||l>y) return INF;
    if(l>=x&&r<=y) return minx[k];
    int mid=(l+r)/2;
    return min(query(lson[k],l,mid,x,y),query(rson[k],mid+1,r,x,y));
}
struct seg
{
    int num,l,r;
};
bool cmp1(seg p,seg q)
{
    return p.l<q.l;
}
bool cmp2(seg p,seg q)
{
    if(p.num!=q.num) return p.num<q.num;
    return p.l<q.l;
}
vector<seg> v,vv;
vector<int> lpos;
int main()
{
    scanf("%d%d%d",&n,&s,&m);
    for(int i=1;i<=m;i++)
    {
        int c,a,b;
        scanf("%d%d%d",&c,&a,&b);
        v.push_back({c,a,b});
    }
    v.push_back({s+1,n,n});
    sort(v.begin(),v.end(),cmp2);
    int lastnum=1,lastpos=1;
    for(auto p:v)
    {
        if(p.num==lastnum)
        {
            if(lastpos<p.l) vv.push_back({p.num,lastpos,p.l-1});
        }
        else 
        {
            if(lastpos<n) vv.push_back({lastnum,lastpos,n-1});
            for(int j=lastnum+1;j<p.num;j++) vv.push_back({j,1,n-1});
            if(p.l>1) vv.push_back({p.num,1,p.l-1});
        }
        lastnum=p.num; lastpos=p.r;
    }
    sort(vv.begin(),vv.end(),cmp1);
    for(auto p:vv) if(lpos.size()==0||p.l!=lpos.back()) lpos.push_back(p.l);
    int pt=0;
    for(int i=0;i<(int)lpos.size();i++)
    {
        int x=lpos[i];
        root[i+1]=root[i];
        while(pt<(int)vv.size()&&vv[pt].l==x)
        {
            insert(root[i+1],root[i+1],1,n-1,vv[pt].r,vv[pt].num);
            pt++;
        }
    }
    int p=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        x+=p; y+=p; y--;
        int pos=upper_bound(lpos.begin(),lpos.end(),x)-lpos.begin()-1;
        p=query(root[pos+1],1,n-1,y,n-1);
        if(p==s+1) p=0;
        printf("%d\n",p);
    }
    return 0;
}


