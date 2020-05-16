#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,m;
struct hole
{
    int x,y,id;
}a[MAXN];
bool cmp(hole p,hole q)
{
    return p.y<q.y;
}
P b[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=INF;
    while(i>0)
    {
        s=min(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXN)
    {
        bit[i]=min(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
    for(int i=1;i<=MAXN;i++) bit[i]=INF;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&b[i].S,&b[i].F);
    sort(b+1,b+m+1);
    int cur=1;
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        while(cur<=n&&a[cur].y<=b[i].F) add(100001-a[cur].x,a[cur].id),cur++;
        ans+=sum(100001-b[i].S);
    }
    printf("%lld\n",ans);
    return 0;
}