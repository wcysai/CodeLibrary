/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 16:12:26
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p;
char str[MAXN];
char ch[5];
int pre[MAXN],suf[MAXN];
char c;
struct segtree
{
    int mpre[4*MAXN],msuf[4*MAXN],lazyp[4*MAXN],lazys[4*MAXN];
    void pushdown(int k)
    {
        if(!lazyp[k]&&!lazys[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            lazyp[i]+=lazyp[k];lazys[i]+=lazys[k];
            mpre[i]+=lazyp[k];msuf[i]+=lazys[k];
        }
        lazyp[k]=lazys[k]=0;
    }
    void pushup(int k)
    {
        mpre[k]=max(mpre[k*2],mpre[k*2+1]);
        msuf[k]=max(msuf[k*2],msuf[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        lazys[k]=lazyp[k]=0;
        if(l==r) {mpre[k]=pre[l]; msuf[k]=suf[l]; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void updp(int k,int l,int r,int x,int y,int v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y) 
        {
            mpre[k]+=v;
            lazyp[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        updp(k*2,l,mid,x,y,v); updp(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void upd1(int k,int l,int r,int x,int y,int v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y) 
        {
            msuf[k]+=v;
            lazys[k]+=v;
            return;
        }
        int mid=(l+r)/2;
        upd1(k*2,l,mid,x,y,v); upd1(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int qp(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return mpre[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(qp(k*2,l,mid,x,y),qp(k*2+1,mid+1,r,x,y));
    }
    int qs(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return 0;
        if(l>=x&&r<=y) return msuf[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(qs(k*2,l,mid,x,y),qs(k*2+1,mid+1,r,x,y));
    }
}seg;
int calc_ans()
{
    int ans=1;
    if(p<n&&c!=str[p+1]) ans=2;
    if(p>1&&c!=str[p-1]) ans=2;
    ans=max(ans,seg.qp(1,1,n,1,p-1));ans=max(ans,seg.qs(1,1,n,1,p+1));
    if(p<n-1&&c!=str[p+1]&&c!=str[p+2]) ans=max(ans,suf[p+1]+1);
    if(p>2&&c!=str[p-1]&&c!=str[p-2]) ans=max(ans,pre[p-1]+1);
    if(p>1&&p<n&&str[p-1]!=str[p+1]&&c!=str[p-1]&&c!=str[p+1])
    {
        int l=(p>2&&c!=str[p-2])?pre[p-1]:1,r=(p<n-1&&c!=str[p+2])?suf[p+1]:1;
        ans=max(ans,l+r+1);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=1;
        if(i>1&&str[i]!=str[i-1]) pre[i]=2;
        if(i>2&&str[i]!=str[i-1]&&str[i]!=str[i-2]) pre[i]=max(pre[i],pre[i-1]+1);
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=1;
        if(i<n&&str[i]!=str[i+1]) suf[i]=2;
        if(i<n-1&&str[i]!=str[i+1]&&str[i]!=str[i+2]) suf[i]=max(suf[i],suf[i+1]+1);
    }
    seg.build(1,1,n);
    int ans=0;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&p);scanf("%s",ch);
        char c=ch[0];
        printf("%d\n",calc_ans());
        str[p]=c;
        if(p<n&&str[p]==str[p+1])
        {

        }
        for(int i=p;i>=max(1,p-2);i--)
        {
            suf[i]=1;
            if(i<n&&str[i]!=str[i+1]) suf[i]=2;
            if(i<n-1&&str[i]!=str[i+1]&&str[i]!=str[i+2]) suf[i]=max(suf[i],suf[i+1]+1);
        }
        for(int i=max(1,p-2);i<=max(n,p+2);i++) seg.update(1,1,n,i);
        printf("%d\n",ans);
    }
    return 0;
}


