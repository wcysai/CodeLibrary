#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<int> cards[MAXN];
vector<P> v;
struct segtree
{
    P mini[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r) 
        {
            mini[k]=make_pair(cards[l].size()>0?cards[l].back():INF,l);
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
            mini[k]=make_pair(cards[l].size()>0?cards[l].back():INF,l);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos); else update(k*2+1,mid+1,r,pos);
        pushup(k);
        return;
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(INF,0);
        if(l>=x&&r<=y) return mini[k];
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            int x;
            scanf("%d",&x);
            cards[i].push_back(x);
            v.push_back(P(x,i));
        }
        sort(cards[i].begin(),cards[i].end(),greater<int>());
    }
    sort(v.begin(),v.end(),greater<P>());
    seg.build(1,1,n);
    int ans=0,curpos=1,curval=-1;
    while(true)
    {
        if(!v.size()) break;
        while(v.size()&&v.back().F<=curval)
        {
            int pos=v.back().S;
            while(cards[pos].size()>0&&cards[pos].back()<=curval) cards[pos].pop_back();
            seg.update(1,1,n,pos);
            v.pop_back(); 
        }
        int l=curpos,r=curpos+k;
        P p;
        if(r>n)
        {
            r-=n;
            p=min(seg.query(1,1,n,1,r),seg.query(1,1,n,l,n));
        }
        else p=seg.query(1,1,n,l,r);
        if(p.F==INF) break;
        else
        {
            ans++;
            curpos=p.F;
            curval=p.S;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}