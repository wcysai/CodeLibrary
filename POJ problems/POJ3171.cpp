#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 10002
#define MAXE 90000
#define INT_MAX 1<<20
using namespace std;
int n,m,e,size,dat[4*MAXE-1];
struct cow
{
    int start,end,salary;
    const bool operator < (const cow &other)
{
    return start < other.start;
}
};
cow shed[MAXN];
void init(int n_)
{
    size=1;
    while(size<n_) size*=2;
    for(int i=0;i<2*size-1;i++) dat[i]=INT_MAX;
}
void update(int k,int a)
{
    k+=size-1;
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
    scanf("%d%d%d",&n,&m,&e);
    e-=m;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&shed[i].start,&shed[i].end,&shed[i].salary);
        shed[i].start=max(0,shed[i].start-m)+1;
        shed[i].end=max(0,shed[i].end-m)+1;
    }
    sort(shed,shed+n);
    init(e+1);
    update(0,0);
    for(int i=0;i<n;i++)
    {
        update(shed[i].end,min(dat[size+shed[i].end-1],query(shed[i].start-1,shed[i].end+1,0,0,size)+shed[i].salary));
    }
    printf("%d\n",dat[e+size]==INT_MAX?-1:dat[e+size]);
    return 0;
}

