/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 04:53:43
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
int n,q,a[MAXN];
char ch[5];
int _mod(int x) {return x>=MOD?x-MOD:x;}
struct segtree
{
    int sumA[4*MAXN],sumB[4*MAXN],lazyA[4*MAXN],lazyB[4*MAXN],ans[4*MAXN];
    void pushup(int k)
    {
        sumA[k]=_mod(sumA[k*2]+sumA[k*2+1]);
        sumB[k]=_mod(sumB[k*2]+sumB[k*2+1]);
        ans[k]=_mod(ans[k*2]+ans[k*2+1]);
    }
    void pushdown(int k,int l,int r)
    {
        if(!lazyA[k]&&!lazyB[k]) return;
        int mid=(l+r)/2;
        for(int i=k*2;i<=k*2+1;i++)
        {
            int len=(i==k*2)?mid-l+1:r-mid;
            ans[i]=((ans[i]+1LL*lazyA[k]*sumB[i]+1LL*lazyB[k]*sumA[i])%MOD+1LL*lazyA[k]*lazyB[k]%MOD*len)%MOD;
            sumA[i]=(sumA[i]+1LL*lazyA[k]*len)%MOD;
            sumB[i]=(sumB[i]+1LL*lazyB[k]*len)%MOD;
            lazyA[i]=_mod(lazyA[i]+lazyA[k]);
            lazyB[i]=_mod(lazyB[i]+lazyB[k]);
        }
        lazyA[k]=lazyB[k]=0;
    }
    void update(int k,int l,int r,int x,int y,int type,int v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            if(type==0)
            {
                lazyA[k]=_mod(lazyA[k]+v);ans[k]=(ans[k]+1LL*v*sumB[k])%MOD;sumA[k]=(sumA[k]+1LL*v*(r-l+1))%MOD;
                return;
            }
            else
            {
                lazyB[k]=_mod(lazyB[k]+v);ans[k]=(ans[k]+1LL*v*sumA[k])%MOD;sumB[k]=(sumB[k]+1LL*v*(r-l+1))%MOD;
                return;
            }
        }
        pushdown(k,l,r);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,type,v);update(k*2+1,mid+1,r,x,y,type,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;;
        if(l>=x&&r<=y) return ans[k];
        pushdown(k,l,r);
        int mid=(l+r)/2;
        return _mod(query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;i++)
    {
        scanf("%s",ch);
        int l,r;scanf("%d%d",&l,&r);
        if(ch[0]=='?') printf("%d\n",seg.query(1,1,n,l,r));
        else 
        {
            int x;scanf("%d",&x);
            if(ch[0]=='*') seg.update(1,1,n,l,r,0,x); else seg.update(1,1,n,l,r,1,x);
        }
    }
    return 0;
}

