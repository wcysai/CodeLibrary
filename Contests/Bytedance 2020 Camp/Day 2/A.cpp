#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,n,k,a[MAXN];
int cursuf,curans;
map<string,P> mp;
struct segtree
{
    int len[4*MAXN],pre[4*MAXN],suf[4*MAXN],ans[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        pre[k]=(ans[k*2]==len[k*2]?len[k*2]+pre[k*2+1]:pre[k*2]);
        suf[k]=(ans[k*2+1]==len[k*2+1]?len[k*2+1]+suf[k*2]:suf[k*2+1]);
        ans[k]=max(suf[k*2]+pre[k*2+1],max(ans[k*2],ans[k*2+1]));
    }
    void clear(int k)
    {
        lazy[k]=0;
        ans[k]=pre[k]=suf[k]=len[k];
    }
    void st(int k)
    {
        lazy[k]=1;
        ans[k]=pre[k]=suf[k]=0;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        if(lazy[k]==0) for(int i=k*2;i<=k*2+1;i++) clear(i);
        else for(int i=k*2;i<=k*2+1;i++) st(i);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        ans[k]=pre[k]=suf[k]=len[k]=r-l+1; 
        lazy[k]=-1;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            if(v==0) clear(k); else st(k);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int val)
    {
        if(l==r) 
        {
            curans=max(curans,max(cursuf+pre[k],ans[k]));
            return l;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(max(curans,max(cursuf+pre[k*2],ans[k*2]))>=val) return query(k*2,l,mid,val);
        int tmp;
        if(ans[k*2]==len[k*2]) tmp=cursuf+ans[k*2]; else tmp=suf[k*2];
        curans=max(curans,max(cursuf+pre[k*2],ans[k*2])); 
        cursuf=tmp;
        return query(k*2+1,mid+1,r,val);
    }
}seg;
string str;
int main()
{
    scanf("%d",&n);
    seg.build(1,1,100000);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int m=(int)str.size();
        bool f=false; 
        int id=-1;
        for(int j=0;j<m;j++) 
            if(str[j]=='=') 
            {
                f=true;
                id=j; 
                break;
            }
        if(f)
        {
            string t=str.substr(0,id);
            int l=-1,r=-1;
            for(int j=0;j<m;j++)
            {
                if(str[j]=='(') l=j;
                if(str[j]==')') r=j;
            }
            string q=str.substr(l+1,r-l-1);
            int val=atoi(q.c_str());
            curans=cursuf=0;
            int res=seg.query(1,1,100000,val);
            if(curans<val) mp[t]=P(0,0); 
            else 
            {
                mp[t]=P(res-val+1,val);
                seg.update(1,1,100000,res-val+1,res,1);
            }
        } 
        else if(str[0]=='f')
        {
            int l=-1,r=-1;
            for(int j=0;j<m;j++)
            {
                if(str[j]=='(') l=j;
                if(str[j]==')') r=j;
            }
            string q=str.substr(l+1,r-l-1);
            P p=mp[q];
            if(!p.F) continue; else seg.update(1,1,100000,p.F,p.F+p.S-1,0);
            mp[q]=P(0,0);
        }
        else
        {
            int l=-1,r=-1;
            for(int j=0;j<m;j++)
            {
                if(str[j]=='(') l=j;
                if(str[j]==')') r=j;
            }
            string q=str.substr(l+1,r-l-1);
            printf("%d\n",mp[q].F);
        }
    }
    return 0;
}