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
int n,k,a[MAXN];
int st[MAXN],t;
int fa[MAXN],ls[MAXN],rs[MAXN],root;
int sum[MAXN],cnt[MAXN],shift;
ll ans;
void solve(int pos,int l,int r)
{
    if(l>=r) 
    {
        for(int i=l-1;i<=r;i++) cnt[sum[i]]--;
        return;
    }
    int lb=pos-l,rb=r-pos;
    if(lb<=rb)
    {
        for(int i=l-1;i<=pos-1;i++) cnt[sum[i]]--;
        for(int i=pos;i>=l;i--)
        {    
            int need=(sum[i-1]+a[pos])%k;
            ans+=cnt[need];
            if(i==pos&&sum[pos]==need) ans--;
        }
        solve(rs[pos],pos+1,r);
        for(int i=l-1;i<=pos-1;i++) cnt[sum[i]]++;
        solve(ls[pos],l,pos-1);
    }
    else
    {
        for(int i=pos;i<=r;i++) cnt[sum[i]]--;
        for(int i=pos;i<=r;i++)
        {    
            int need=(sum[i]-a[pos])%k; if(need<0) need+=k;
            ans+=cnt[need];
            if(i==pos&&sum[pos-1]==need) ans--;
        }
        solve(ls[pos],l,pos-1);
        for(int i=pos;i<=r;i++) cnt[sum[i]]++;
        solve(rs[pos],pos+1,r);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        while(t&&a[st[t-1]]<a[i]) ls[i]=st[--t];
        if(t) rs[st[t-1]]=i;
        st[t++]=i;
    }
    for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
    for(int i=1;i<=n;i++) if(!fa[i]) root=i;
    for(int i=1;i<=n;i++) 
    {
        sum[i]=(sum[i-1]+a[i])%k;
        cnt[sum[i]]++;
    }
    cnt[0]++;
    ans=0;
    solve(root,1,n);
    printf("%lld\n",ans);
    return 0;
}

