#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans;
P a[MAXN];
int bit[MAXN+1],pos[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void solve(int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    int mmin=a[mid].F,curmin=a[mid].S,mmax=a[mid].S,curmax=a[mid].F;
    int ll=mid,rr=mid;
    for(int i=mid+1;i<=r;i++)
    {
        if(a[i].S<mmin) break;
        mmin=max(mmin,a[i].F);
        curmin=min(curmin,a[i].S);
        rr=i;pos[i]=curmin;
    }
    for(int i=mid-1;i>=l;i--)
    {
        if(a[i].F>mmax) break;
        mmax=min(mmax,a[i].S);
        curmax=max(curmax,a[i].F);
        ll=i;pos[i]=curmax;
    }
    ans=max(ans,mid-ll+1); ans=max(ans,rr-mid+1);
    int p1=mid,p2=rr;
    while(p2>mid)
    {
        while(p1>ll&&pos[p1-1]<=pos[p2]) p1--;
        ans=max(ans,p2-p1+1);
        p2--;
    }
    solve(l,mid-1);solve(mid+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    ans=1;
    solve(1,n);
    printf("%d\n",ans);
    return 0;
}

