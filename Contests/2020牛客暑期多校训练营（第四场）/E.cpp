#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
P solve(P p,P q)
{
    return P(p.F+q.F,q.S);
}
struct node
{
    P ans[3];
    bool operator==(const node b) const
	{
		return (this->ans[0]==b.ans[0])&&(this->ans[1]==b.ans[1])&&(this->ans[2]==b.ans[2]);
    }
    void init_same()
    {
        ans[0]=P(0,1);
        ans[1]=P(0,2);
        ans[2]=P(1,1);
    }
    void init_diff()
    {
        ans[0]=P(0,0);
        ans[1]=P(0,0);
        ans[2]=P(0,1);
    }  
};
node id;
node merge(node p,node q)
{
    if(p==id) return q;
    if(q==id) return p;
    node ret;
    P x=solve(P(0,0),p.ans[0]); ret.ans[0]=solve(x,q.ans[x.S]);
    x=solve(P(0,1),p.ans[1]); ret.ans[1]=solve(x,q.ans[x.S]);
    x=solve(P(0,2),p.ans[2]); ret.ans[2]=solve(x,q.ans[x.S]);
    return ret;
}
node ans0[4*MAXN],ans1[4*MAXN];
void pushup(int k)
{
    ans0[k]=merge(ans0[k*2],ans0[k*2+1]);
    ans1[k]=merge(ans1[k*2],ans1[k*2+1]);
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        ans0[k].init_same();
        ans1[k].init_diff();
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid); build(k*2+1,mid+1,r);
    pushup(k);
}
void update(int k,int l,int r,int pos)
{
    if(l==r)
    {
        ans0[k].init_diff();
        ans1[k].init_same();
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(k*2,l,mid,pos); else update(k*2+1,mid+1,r,pos);
    pushup(k);
}
node query0(int k,int l,int r,int x,int y)
{
    if(l>y||x>r) return id;
    if(l>=x&&r<=y) return ans0[k];
    int mid=(l+r)/2;
    return  merge(query0(k*2,l,mid,x,y),query0(k*2+1,mid+1,r,x,y));
}
node query1(int k,int l,int r,int x,int y)
{
    if(l>y||x>r) return id;
    if(l>=x&&r<=y) return ans1[k];
    int mid=(l+r)/2;
    return merge(query1(k*2,l,mid,x,y),query1(k*2+1,mid+1,r,x,y));
}
int T,n,a[MAXN],pos[MAXN],ans[MAXN];
int main()
{
    id.ans[0]=id.ans[1]=id.ans[2]=P(-1,-1);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int dif=max(i-(n+1)/2,(n+1)/2-i);
            if(i<=(n+1)/2)
            {
                node p=query0(1,1,n,1,pos[i]-1);
                node q=query0(1,1,n,pos[i]+1,n);
                P res;
                if(p==id) res=q.ans[0]; else if(q==id) res=p.ans[0];
                else res=P(p.ans[0].F+q.ans[0].F,0);
                if(res.F>=dif) ans[pos[i]]=1; else ans[pos[i]]=0;
            }
            else
            {
                node p=query1(1,1,n,1,pos[i]-1);
                node q=query1(1,1,n,pos[i]+1,n);
                P res;
                if(p==id) res=q.ans[0]; else if(q==id) res=p.ans[0];
                else res=P(p.ans[0].F+q.ans[0].F,0);
                if(res.F>=dif) ans[pos[i]]=1; else ans[pos[i]]=0;
            }
            update(1,1,n,pos[i]);
        }
        for(int i=1;i<=n;i++) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}