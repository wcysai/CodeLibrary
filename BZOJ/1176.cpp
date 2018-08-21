/*************************************************************************
    > File Name: 1176.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 20:38:30
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXC 160005
#define MAXQ 10005
#define MAXK 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int s,w,q,tot;
int bit[MAXK];
int ans[MAXQ];
void add(int i,int x)
{
    while(i<=w)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int query(int i)
{
    int sum=0;
    while(i)
    {
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}
struct op
{
    int x,y,id,pos,val,type;
}a[MAXC+4*MAXQ],tmp[MAXC+4*MAXQ];
bool cmp(op p,op q)
{
    if(p.x!=q.x) return p.x<q.x;
    if(p.y!=q.y) return p.y<q.y;
    return p.type<q.type;
}
void add_query(int x,int y,int sgn)
{
    a[++tot].x=x;a[tot].y=y;a[tot].type=1;a[tot].val=sgn;a[tot].pos=q;a[tot].id=tot;
}
void cdq(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    int l1=l,l2=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(a[i].id<=mid&&a[i].type==0) add(a[i].y,a[i].val);
        if(a[i].id>mid&&a[i].type==1) ans[a[i].pos]+=a[i].val*query(a[i].y);
    }
    for(int i=l;i<=r;i++)
        if(a[i].id<=mid&&!a[i].type) add(a[i].y,-a[i].val);
    for(int i=l;i<=r;i++)
        if(a[i].id<=mid) tmp[l1++]=a[i]; else tmp[l2++]=a[i];
    for(int i=l;i<=r;i++) a[i]=tmp[i];
    cdq(l,mid);cdq(mid+1,r);
}
int main()
{
    scanf("%d%d",&s,&w);
    int o,x1,y1,x2,y2,v;
    while(true)
    {
        scanf("%d",&o);
        if(o==3) break;
        if(o==1)
        {
            scanf("%d%d%d",&x1,&y1,&v);
            tot++;
            a[tot].x=x1;a[tot].y=y1;a[tot].id=tot;
            a[tot].type=0;a[tot].val=v;a[tot].pos=0;
        }
        else
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            q++;
            add_query(x1-1,y1-1,1);
            add_query(x2,y2,1);
            add_query(x1-1,y2,-1);
            add_query(x2,y1-1,-1);
        }
    }
    sort(a+1,a+tot+1,cmp);
    cdq(1,tot);
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}

