/*************************************************************************
    > File Name: 4742.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-21 23:48:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MOD=1<<30;
int T,n,m;
P bit[2*MAXN+1];
P ans[MAXN];
int _mod(int x) {return x>=MOD?x-MOD:x;}
void merge(P &x,P y)
{
    if(x.F<y.F) x=y;
    else if(x.F==y.F) x.S=_mod(x.S+y.S);
}
void add(int i,P p)
{
    while(i<=m)
    {
        merge(bit[i],p);
        i+=i&-i;
    }
}
void clear(int i)
{
    while(i<=m)
    {
        bit[i]=P(0,0);
        i+=i&-i;
    }
}
P query(int i)
{
    P p=P(0,0);
    while(i>0)
    {
        merge(p,bit[i]);
        i-=i&-i;
    }
    return p;
}
struct node
{
    int x,y,z,id;
}a[MAXN],tmp[MAXN];
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
    cdq(l,mid);
    for(int i=l;i<=r;i++) tmp[i]=a[i];
    sort(tmp+l,tmp+mid+1,cmp2);sort(tmp+mid+1,tmp+r+1,cmp2);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        while(j<=mid&&tmp[j].y<=tmp[i].y) add(tmp[j].z,ans[tmp[j].id]),++j;
        P p=query(tmp[i].z);p.F++;
        merge(ans[tmp[i].id],p);
    }
    for(int i=l;i<j;i++) clear(tmp[i].z);
    cdq(mid+1,r);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vector<int> v;v.clear();
        for(int i=1;i<=n;i++)
        {
            ans[i]=P(1,1);
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);a[i].id=i;
            v.push_back(a[i].x);v.push_back(a[i].y);v.push_back(a[i].z);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        m=(int)v.size()+1;
        for(int i=1;i<=n;i++)
        {
            a[i].x=lower_bound(v.begin(),v.end(),a[i].x)-v.begin()+1;
            a[i].y=lower_bound(v.begin(),v.end(),a[i].y)-v.begin()+1;
            a[i].z=lower_bound(v.begin(),v.end(),a[i].z)-v.begin()+1;
        }
        sort(a+1,a+n+1,cmp);
        cdq(1,n);
        P res=P(0,0);
        for(int i=1;i<=n;i++) merge(res,ans[i]);
        printf("%d %d\n",res.F,res.S);
    }
    return 0;
}

