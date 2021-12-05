#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll s[MAXN];
vector<P> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        sum+=s[i];
    }
    if(s[n]!=0) {puts("-1"); return 0;}
    if(sum%n) {puts("-1"); return 0;}
    ll delta=sum/n,ans=0;
    if(delta>0)
    {
        for(int i=1;i<=n;i++) if(i==n-1) s[i]-=2*delta; else if(i<n) s[i]-=delta;
        ans+=delta; 
    }
    else 
    {
        for(int i=1;i<=n;i++) if(i==1) s[i]-=2*delta; else if(i<n) s[i]-=delta;
        ans-=delta; 
    }
    ll minsum=INF,ss=0;
    for(int i=1;i<=n-1;i++) ss+=s[i],minsum=min(minsum,ss);
    ans+=2*(-minsum); s[1]-=minsum; s[n-1]+=minsum; 
    for(int i=1;i<=n-1;i++) ans-=1LL*s[i]*i;
    printf("%lld\n",ans);
    return 0;
}