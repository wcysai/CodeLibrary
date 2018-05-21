#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 50000
#define INF 100000000
using namespace std;
int n,q;
pair<int,int> dat[4*MAXN-1];
void init(int n_)
{
    n=1;
    while (n<n_) n*=2;
    for(int i=0;i<2*n-1;i++)
    {
        dat[i].first=INF;
        dat[i].second=-INF;
    }
}
void update(int k,int a)
{
    k+=n-1;
    dat[k].first=a;
    dat[k].second=a;
    while(k>0)
    {
        k=(k-1)/2;
        dat[k].first=min(dat[k*2+1].first,dat[k*2+2].first);
        dat[k].second=max(dat[k*2+1].second,dat[k*2+2].second);
    }
}
int query1(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l) return INF;
    if(a<=l&&r<=b) return dat[k].first;
    else
    {
        int vl=query1(a,b,k*2+1,l,(l+r)/2);
        int vr=query1(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
int query2(int a,int b,int k,int l,int r)
{
    if(r<=a||b<=l) return -INF;
    if(a<=l&&r<=b) return dat[k].second;
    else
    {
        int vl=query2(a,b,k*2+1,l,(l+r)/2);
        int vr=query2(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    int t=n;
    init(n);
    for(int i=0;i<t;i++)
    {
        int p;
        scanf("%d",&p);
        update(i,p);
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",query2(x-1,y,0,0,n)-query1(x-1,y,0,0,n));
    }
    return 0;
}
