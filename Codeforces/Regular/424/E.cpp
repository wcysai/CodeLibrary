#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,bit[MAXN],cnt[MAXN];
pair<int,int> a[MAXN];
int lowbit(int x)
{
    return x&-x;
}
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=lowbit(i);
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=lowbit(i);
    }
}
int main()
{
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        a[i].second=i+1;
        scanf("%d",&a[i].first);
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        assert(true);
        cnt[i-sum(a[i].second)]++;
        add(a[i].second,1);
    }
    int t=n,k=0;
    while(t>0)
    {
        while(cnt[k]==0) k++;
        ans+=t;
        t-=cnt[k];
        k++;
    }
    printf("%I64d\n",ans);
    return 0;
}
