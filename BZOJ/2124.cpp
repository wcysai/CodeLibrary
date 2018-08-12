/*************************************************************************
    > File Name: 2124.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-10 18:12:35
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,a[MAXN],p[MAXN];
int add(int x,int y) {x+=y; return x>=MOD?x-MOD:x;}
int read() 
{
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
struct segtree
{
    int hash1[4*MAXN],hash2[4*MAXN];
    void build(int k,int l,int r)
    {
        hash1[k]=hash2[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void merge(int k,int l,int r)
    {
        int mid=(l+r)/2;
        hash1[k]=(1LL*hash1[k*2]*p[r-mid]+hash1[k*2+1])%MOD;
        hash2[k]=(1LL*hash2[k*2+1]*p[mid-l+1]+hash2[k*2])%MOD;
    }
    void update(int k,int l,int r,int pos)
    {
        if(l==r) 
        {
            hash1[k]=hash2[k]=1; 
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos); else update(k*2+1,mid+1,r,pos);
        merge(k,l,r);
    }
    int query1(int k,int l,int r,int x,int y)
    {
        if(x>r||y<l) return 0;
        if(l>=x&&r<=y) return 1LL*p[y-r]*hash1[k]%MOD;
        int mid=(l+r)/2;
        return add(query1(k*2,l,mid,x,y),query1(k*2+1,mid+1,r,x,y));
    }
    int query2(int k,int l,int r,int x,int y)
    {
        if(x>r||y<l) return 0;
        if(l>=x&&r<=y) return 1LL*p[l-x]*hash2[k]%MOD;
        int mid=(l+r)/2;
        return add(query2(k*2,l,mid,x,y),query2(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    T=read();
    p[0]=1;
    for(int j=1;j<=10000;j++) p[j]=add(p[j-1],p[j-1]);
    while(T--)
    {
        N=read();
        for(int i=1;i<=N;i++) a[i]=read();
        seg.build(1,1,N);
        bool f=false;
        for(int i=1;i<=N;i++)
        {
            if(f) break;
            seg.update(1,1,N,a[i]);
            int len=min(a[i],N-a[i]+1);
            if(seg.query1(1,1,N,a[i]-len+1,a[i])!=seg.query2(1,1,N,a[i],a[i]+len-1)) {f=true; break;}
        }
        if(f) printf("Y\n"); else printf("N\n");
    }
    return 0;
}

