/*************************************************************************
    > File Name: 3262_cdq.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 19:03:16
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int bit[2*MAXN+1],res[MAXN];
void add(int i,int x)
{
    while(i<=m)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int query(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
struct node
{
    int x,y,z,cnt,ans;
}a[MAXN];
bool cmp(node p,node q)
{
    if(p.x!=q.x) return p.x<q.x;
    if(p.y!=q.y) return p.y<q.y;
    return p.z<q.z;
}
bool cmp2(node p,node q)
{
    if(p.y!=q.y) return p.y<q.y;
    if(p.z!=q.z) return p.z<q.z;
    return p.x<q.x;
}
void cdq(int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    cdq(l,mid);cdq(mid+1,r);
    sort(a+l,a+mid+1,cmp2);sort(a+mid+1,a+r+1,cmp2);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        while(j<=mid&&a[j].y<=a[i].y) add(a[j].z,a[j].cnt),++j;
        a[i].ans+=query(a[i].z);
    }
    for(int i=l;i<j;i++) add(a[i].z,-a[i].cnt);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        a[i].cnt=1;
    }
    sort(a+1,a+n+1,cmp);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&a[i].x==a[i-1].x&&a[i].y==a[i-1].y&&a[i].z==a[i-1].z) a[tot].cnt++;
        else a[++tot]=a[i];
    }
    for(int i=1;i<=tot;i++) a[i].ans+=a[i].cnt-1;
    cdq(1,tot);
    for(int i=1;i<=tot;i++) res[a[i].ans]+=a[i].cnt;
    for(int i=0;i<n;i++) printf("%d\n",res[i]);
    return 0;
}

