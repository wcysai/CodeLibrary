#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
ll x[MAXN],w[MAXN];
ll leftmost[MAXN],rightmost[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=q;i++) scanf("%lld",&w[i]);
    ll cur=0;
    memset(leftmost,0,sizeof(leftmost));
    memset(rightmost,0,sizeof(rightmost));
    for(int i=1;i<=q;i++)
    {
        cur+=w[i];
        leftmost[i]=leftmost[i-1]; rightmost[i]=rightmost[i-1];
        leftmost[i]=min(leftmost[i],cur);
        rightmost[i]=max(rightmost[i],cur);
    }
    for(int i=1;i<=n-1;i++)
    {
        ll dist=x[i+1]-x[i];
        int l=0,r=q;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(rightmost[mid]-leftmost[mid]>dist) r=mid; else l=mid;
        }
        if(rightmost[r]-leftmost[r]<=dist)
        {
            ans[i]+=rightmost[r];
            ans[i+1]-=leftmost[r];
        }
        else if(w[r]>0)
        {
            ans[i+1]+=-leftmost[r];
            ans[i]+=dist+leftmost[r];
        }
        else
        {
            ans[i]+=rightmost[r];
            ans[i+1]+=dist-rightmost[r];
        }
    }
    ans[1]-=leftmost[q]; ans[n]+=rightmost[q];
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}