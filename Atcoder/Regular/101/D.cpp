#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int bit[2*MAXN+1],s[MAXN];
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
    while(i<=2*MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
ll check(int x)
{
    memset(bit,0,sizeof(bit));
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x) s[i]=s[i-1]+1;
        else s[i]=s[i-1];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        add(2*s[i-1]-(i-1)+n,1);
        ans+=sum(2*s[i]-i+n-1);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll cnt=1LL*n*(n+1)/2;
    int l=0,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)>=cnt/2+1) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}

