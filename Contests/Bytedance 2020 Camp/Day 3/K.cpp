#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2100000009
#define MOD 2000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int r[MAXN],c[MAXN],h[MAXN];
int bit1[MAXN+1],bit2[MAXN+1];
int get_max(int i)
{
    int s=-INF;
    while(i>0)
    {
        s=max(s,bit1[i]);
        i-=i&-i;
    }
    return s;
}
void add_max(int i,int x)
{
    while(i<=MAXN)
    {
        bit1[i]=max(bit1[i],x);
        i+=i&-i;
    }
}
int get_min(int i)
{
    int s=INF;
    while(i>0)
    {
        s=min(s,bit2[i]);
        i-=i&-i;
    }
    return s;
}
void add_min(int i,int x)
{
    while(i<=MAXN)
    {
        bit2[i]=min(bit2[i],x);
        i+=i&-i;
    }
}
struct node
{
    int x,y,h;
};
vector<int> disr,disc;
vector<node> v;
bool cmp1(node p,node q)
{
    return p.x<q.x;
}
bool cmp2(node p,node q)
{
    return p.x>q.x;
}
bool check(int k)
{
    v.clear();
    for(int i=1;i<=k;i++) v.push_back((node){r[i],c[i],h[i]});
    sort(v.begin(),v.end(),cmp1);
    for(int i=1;i<=MAXN;i++) bit1[i]=-INF;
    //upper left
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]-disc[y-1]-v[i].h;
        if(get_max(MAXN+1-y)>val) return false;
        add_max(MAXN+1-y,val);
    }
    for(int i=1;i<=MAXN;i++) bit1[i]=-INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]-disc[y-1]+v[i].h;
        if(get_max(MAXN+1-y)>val) return false;
        add_max(MAXN+1-y,val);
    }
    //lower left
    for(int i=1;i<=MAXN;i++) bit1[i]=-INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]+disc[y-1]-v[i].h;
        if(get_max(y)>val) return false;
        add_max(y,val);
    }
    for(int i=1;i<=MAXN;i++) bit1[i]=-INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]+disc[y-1]+v[i].h;
        if(get_max(y)>val) return false;
        add_max(y,val);
    }
    sort(v.begin(),v.end(),cmp2);
    //upper right
    for(int i=1;i<=MAXN;i++) bit2[i]=INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]+disc[y-1]-v[i].h;
        if(get_min(MAXN+1-y)<val) return false;
        add_min(MAXN+1-y,val);
    }
    for(int i=1;i<=MAXN;i++) bit2[i]=INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]+disc[y-1]+v[i].h;
        if(get_min(MAXN+1-y)<val) return false;
        add_min(MAXN+1-y,val);
    }
    //lower right
    for(int i=1;i<=MAXN;i++) bit2[i]=INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]-disc[y-1]-v[i].h;
        if(get_min(y)<val) return false;
        add_min(y,val);
    }
    for(int i=1;i<=MAXN;i++) bit2[i]=INF;
    for(int i=0;i<k;i++)
    {
        int x=v[i].x,y=v[i].y;
        int val=disr[x-1]-disc[y-1]+v[i].h;
        if(get_min(y)<val) return false;
        add_min(y,val);
    }
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&r[i],&c[i],&h[i]);
        disr.push_back(r[i]); disc.push_back(c[i]);
    }
    sort(disr.begin(),disr.end()); disr.erase(unique(disr.begin(),disr.end()),disr.end());
    sort(disc.begin(),disc.end()); disc.erase(unique(disc.begin(),disc.end()),disc.end());
    int ans=n+1;
    for(int i=2;i<=n;i++)
        if((r[i]+c[i]+h[i]+r[1]+c[1]+h[1])&1) 
            {ans=i; break;}
    for(int i=1;i<=n;i++) 
    {
        r[i]=lower_bound(disr.begin(),disr.end(),r[i])-disr.begin()+1;
        c[i]=lower_bound(disc.begin(),disc.end(),c[i])-disc.begin()+1;
    }
    int l=2,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    ans=min(ans,r);
    if(ans==n+1) puts("bravo komisijo"); else printf("%d\n",ans);
    return 0;
}