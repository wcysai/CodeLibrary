#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define lson now<<1  
#define rson now<<1|1  
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n;
P a[MAXN];
int Lmin[MAXN],Rmin[MAXN],Lmax[MAXN],Rmax[MAXN];
int st[MAXN];
vector<int> num[61];
struct data 
{  
    int len;    
    ll sum,add,sumh,tag,addh;   
}s[2*1024*1024+5];              
void pushup(int now) 
{  
    s[now].sum=s[lson].sum+s[rson].sum;     
    s[now].sumh=s[lson].sumh+s[rson].sumh;    
}       
void mark_adh(int now,ll v,int t) 
{   
    s[now].addh+=v;    
    if(t) s[now].sumh+=v*s[now].len;     
}
void mark_add(int now,ll v) 
{        
    if(s[now].tag) 
    {    
        mark_adh(now,-v*s[now].tag,0);     
    }
    s[now].add+=v;     
    s[now].sum+=1ll*s[now].len*v;                     
}  
void mark_tag(int now,ll v) 
{  
    s[now].tag+=v;       
    s[now].sumh+=s[now].sum*v;    
}
void pushdown(int now) 
{   
    if(s[now].add) 
    {   
        mark_add(lson,s[now].add);  
        mark_add(rson,s[now].add);    
        s[now].add=0;  
    }   
    if(s[now].addh) 
    {   
        mark_adh(lson,s[now].addh,1);   
        mark_adh(rson,s[now].addh,1);  
        s[now].addh=0;  
    }   
    if(s[now].tag) 
    {    
        mark_tag(lson,s[now].tag);  
        mark_tag(rson,s[now].tag);  
        s[now].tag=0;   
    }
}
void build(int l,int r,int now) 
{  
    s[now].len=r-l+1;  s[now].tag=s[now].add=s[now].addh=s[now].sum=s[now].sumh=0;    
    if(l==r) return; 
    int mid=(l+r)>>1;  
    build(l,mid,lson); 
    build(mid+1,r,rson); 
}
void update(int l,int r,int now,int L,int R,int v) 
{  
    if(l>=L&&r<=R) 
    {  
        mark_add(now,v);   
        return;  
    }  
    pushdown(now);  
    int mid=(l+r)>>1;   
    if(L<=mid)  update(l,mid,lson,L,R,v);  
    if(R>mid)   update(mid+1,r,rson,L,R,v);    
    pushup(now);  
}
ll query(int l,int r,int now,int L,int R) 
{    
    if(l>=L&&r<=R) 
    {  
        return s[now].sumh;  
    }  
    pushdown(now);  
    int mid=(l+r)>>1;      
    ll re=0; 
    if(L<=mid) re+=query(l,mid,lson,L,R);  
    if(R>mid) re+=query(mid+1,r,rson,L,R);   
    return re;   
}
vector<pair<pair<int,int>,int> > upd[MAXN];
vector<pair<pair<int,int>,int> > qry[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%lld",&a[i].F); a[i].S=i;}
    int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		Lmin[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		Rmin[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    t=0;
    for(int i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		Lmax[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&a[st[t-1]]<=a[i]) t--;
		Rmax[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    //for(int i=1;i<=n;i++) printf("%d %d %d %d\n",Lmin[i],Rmin[i],Lmax[i],Rmax[i]);
    for(int i=1;i<=n;i++)
    {
        num[__builtin_popcountll(a[i].F)].push_back(i);
    }
    build(1,n,1);
    ll ans=0;
    for(int i=0;i<=60;i++)
    {
        //printf("i=%d\n",i);
        for(auto x:num[i])
        {
            int p=x;
            //printf("add [%d,%d] [%d,%d]\n",Lmax[p]+1,p,p,Rmax[p]-1);
            //printf("query [%d %d] [%d %d]\n",Lmin[p]+1,p,p,Rmin[p]-1);
            upd[Lmax[p]+1].push_back(make_pair(make_pair(p,Rmax[p]-1),1));
            upd[p+1].push_back(make_pair(make_pair(p,Rmax[p]-1),-1));
            qry[Lmin[p]].push_back(make_pair(make_pair(p,Rmin[p]-1),-1));
            qry[p].push_back(make_pair(make_pair(p,Rmin[p]-1),1));
        }
        for(int j=1;j<=n;j++)
        {
            for(auto ent:upd[j]) 
            {
                //printf("update %d %d %d\n",ent.F.F,ent.F.S,ent.S);
                update(1,n,1,ent.F.F,ent.F.S,ent.S);
            }
            mark_tag(1,1);
            for(auto ent:qry[j]) 
            {
                //printf("query %d %d %lld\n",ent.F.F,ent.F.S,query(1,n,1,ent.F.F,ent.F.S));
                ans+=query(1,n,1,ent.F.F,ent.F.S)*ent.S;
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(auto ent:upd[j]) 
                update(1,n,1,ent.F.F,ent.F.S,-ent.S);
            mark_tag(1,1);
        }
        for(auto x:num[i])
        {
            int p=x;
            upd[Lmax[p]+1].clear();
            upd[p+1].clear();
            qry[Lmin[p]].clear();
            qry[p].clear();
        }
        //printf("ans=%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}