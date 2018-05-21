#include<bits/stdc++.h>
#define MAXN 50005
#define M_PI 3.1415926535897932384626
using namespace std;
typedef long long ll;
struct point
{
    int x,y,val;
    double ang;
};
int n,t;
point a[MAXN];
int sum[MAXN];
ll ans=0;
bool cmp(point a,point b)
{
   return a.ang<b.ang;
}
bool C(int p,int q)
{
    if(p>n) p-=n;
    if(q>n) q-=n;
    double i=a[p].ang,j=a[q].ang;
    if(i<j) return i+180>j;
    else return i-180>j;
}
int main()
{
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].val);
        a[i].ang=atan2((double)a[i].y,(double)a[i].x)*180/M_PI;
        if(a[i].ang<0) a[i].ang+=360;
    }
    sort(a+1,a+n+1,cmp);
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i].val;
     for(int i=1;i<=n;i++)
    {
        int left=i,right=i+n;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(C(i,mid)) left=mid; else right=mid;
        }
        if(left>n) left-=n;
        ll s;
        if(i<=left) s=sum[left]-sum[i-1];
        else s=sum[n]-sum[i-1]+sum[left];
        ans=max(ans,(ll)s*(sum[n]-s));
        ans=max(ans,(ll)(s-a[i].val)*(sum[n]-s+a[i].val));
    }
    printf("%lld\n",ans);
    }
    return 0;
}
