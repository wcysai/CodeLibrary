#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int pre[MAXN],suf[MAXN];
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(bit,0,sizeof(bit));
        int ans=0;
        for(int i=1;i<=n;i++) 
        {
            pre[i]=sum(a[i])+1;
            ans=max(ans,pre[i]);
            add(a[i],pre[i]);
        }
        memset(bit,0,sizeof(bit));
        for(int i=n;i>=1;i--) 
        {
            suf[i]=sum(n+1-a[i])+1;
            add(n+1-a[i],suf[i]);
        }
        if(ans%2==0) {puts("YES"); continue;}
        int k=(ans-1)/2,cnt=0;
        for(int i=1;i<=n;i++) if(pre[i]+suf[i]>=k+2) cnt++;
        if(cnt>=2*k+2) puts("YES"); else puts("NO");
    }
    return 0;
}