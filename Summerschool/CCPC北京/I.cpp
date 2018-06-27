#include<bits/stdc++.h>
#define MAXN 1<<17
#define INF 100000000000
using namespace std;
typedef long long ll;
int n;
ll dat1[2*MAXN+1],dat2[2*MAXN+1],dat3[2*MAXN+1],dat4[2*MAXN+1];
void init(int x)
{
    n=x;
    for(int i=0;i<2*n-1;i++) dat1[i]=-INF,dat2[i]=INF,dat3[i]=INF,dat4[i]=-INF;
}
void update(int k,int a)
{
    k+=n-1;
    if(a<0)
    {
        dat1[k]=-INF;
        dat2[k]=INF;
        dat3[k]=a;
        dat4[k]=a;
    }
    else
    {
        dat1[k]=dat2[k]=a;
        dat3[k]=INF;
        dat4[k]=-INF;
    }
    while(k>0)
    {
        k=(k-1)/2;
        dat1[k]=max(dat1[k*2+1],dat1[k*2+2]);
        dat2[k]=min(dat2[k*2+1],dat2[k*2+2]);
        dat3[k]=min(dat3[k*2+1],dat3[k*2+2]);
        dat4[k]=max(dat4[k*2+1],dat4[k*2+2]);
    }
}
ll query1(int a,int b,int k,int l,int r)
{
    if (r<=a||b<=l) return -INF;
    if (a<=l&&r<=b) return dat1[k];
    else
    {
        ll vl=query1(a,b,k*2+1,l,(l+r)/2);
        ll vr=query1(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}
ll query2(int a,int b,int k,int l,int r)
{
    if (r<=a||b<=l) return INF;
    if (a<=l&&r<=b) return dat2[k];
    else
    {
        ll vl=query2(a,b,k*2+1,l,(l+r)/2);
        ll vr=query2(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
ll query3(int a,int b,int k,int l,int r)
{
    if (r<=a||b<=l) return INF;
    if (a<=l&&r<=b) return dat3[k];
    else
    {
        ll vl=query3(a,b,k*2+1,l,(l+r)/2);
        ll vr=query3(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
ll query4(int a,int b,int k,int l,int r)
{
    if (r<=a||b<=l) return -INF;
    if (a<=l&&r<=b) return dat4[k];
    else
    {
        ll vl=query4(a,b,k*2+1,l,(l+r)/2);
        ll vr=query4(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}
ll query(int a,int b,int k,int l,int r)
{
    ll x=query1(a,b,k,l,r);
    ll y=query2(a,b,k,l,r);
    ll z=query3(a,b,k,l,r);
    ll m=query4(a,b,k,l,r);
    if(z<0) return min(m*m,z*x);
    else return y*y;
}
int t,k,q;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        init(1<<k);
        for(int i=0;i<1<<k;i++)
        {
            int x;
            scanf("%d",&x);
            update(i,x);
        }
        scanf("%d",&q);
        while(q--)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            if(x==1) printf("%lld\n",query(y,z+1,0,0,(1<<k)));
            else update(y,z);
        }
    }
    return 0;
}
