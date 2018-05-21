#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 50002
#define MAXM 500000
#define INT_MAX 1<<17
#define INF 1000000000
using namespace std;
int n,m,dat[4*MAXN-1];
int s[MAXM],t[MAXM];
int dp[MAXN+1];
void init(int n_)
{
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i]=INT_MAX;
}
void update(int k,int a)
{
    k+=n-1;
    dat[k]=a;
    while(k>0)
    {
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}
int query(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l) return INT_MAX;
    if(a<=l&&r<=b) return dat[k];
    else
    {
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&s[i],&t[i]);
    int x=n;
    init(n);
    fill(dp,dp+x+1,INF);
    dp[1]=0;
    update(1,0);
    for(int i=0;i<m;i++)
    {
        int v=min(dp[t[i]],query(s[i],t[i]+1,0,0,n)+1);
        dp[t[i]]=v;
        update(t[i],v);
    }
    printf("%d\n",dp[x]);
}

