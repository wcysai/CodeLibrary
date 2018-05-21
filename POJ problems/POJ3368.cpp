#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_N 100000
#define MAX_Q 100000
using namespace std;
const int DAT_SIZE=(1<<18)-1;
int n,q;
int A[MAX_N];
int L[MAX_Q],R[MAX_Q];
struct save
{
    int lm,rm,m;
}dat[DAT_SIZE];
void init(int k,int l,int r)
{
    if(r-l==1)
    {
        dat[k].lm=1;
        dat[k].rm=1;
        dat[k].m=1;
    }
    else
    {
        int lch=k*2+1,rch=k*2+2;
        int mid=(l+r)/2;
        init(lch,l,mid);
        init(rch,mid,r);
        if(A[mid-1]==A[mid]) dat[k].m=max(dat[lch].rm+dat[rch].lm,max(dat[lch].m,dat[rch].m)); else dat[k].m=max(dat[lch].m,dat[rch].m);
        if(A[l]==A[mid]) dat[k].lm=dat[rch].lm+dat[lch].lm; else dat[k].lm=dat[lch].lm;
        if(A[mid-1]==A[r-1]) dat[k].rm=dat[lch].rm+dat[rch].rm; else dat[k].rm=dat[rch].rm;
    }
}
save query(int i,int j,int k,int l,int r)
{
    if(j<=l||r<=i)
    {
        save t;
        t.lm=0;
        t.rm=0;
        t.m=0;
        return t;
    }
    else if(i<=l&&r<=j) return dat[k];
    else
    {
        int mid=(l+r)/2;
        save lch=query(i,j,k*2+1,l,mid);
        save rch=query(i,j,k*2+2,mid,r);
        save res;
         if(A[mid-1]==A[mid]) res.m=max(lch.rm+rch.lm,max(lch.m,rch.m)); else res.m=max(lch.m,rch.m);
        if(A[l]==A[mid]) res.lm=rch.lm+lch.lm; else res.lm=lch.lm;
        if(A[mid-1]==A[r-1]) res.rm=lch.rm+rch.rm; else res.rm=rch.rm;
        return res;
    }
}
void solve()
{
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&q);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    init(0,0,n);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&L[i],&R[i]);
        int l=L[i]-1,r=R[i];
        printf("%d\n",query(l,r,0,0,n).m);
    }
    scanf("%d",&n);
}
}
int main()
{
    solve();
    return 0;
}
