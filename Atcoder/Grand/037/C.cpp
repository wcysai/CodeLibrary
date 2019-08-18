#include<bits/stdc++.h>
#define MAXN 200005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
bool check(int x)
{
    return b[x]>a[x]&&b[x]>b[x==1?n:x-1]+b[x==n?1:x+1];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    ll ans=0;
    queue<int> que;
    for(int i=1;i<=n;i++)
        if(b[i]>a[i]&&check(i))
            que.push(i);
    while(que.size())
    {
        int p=que.front(); que.pop();
        if(!check(p)) continue;
        int l=(p==1?n:p-1),r=(p==n?1:p+1);
        int x=b[p]-a[p];
        int round=x/(b[l]+b[r]);
        ans+=round;
        b[p]-=round*(b[l]+b[r]);
        if(round)
        {
            if(check(l)) que.push(l);
            if(check(r)) que.push(r);
        }
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            puts("-1");
            return 0;
        }
    printf("%lld\n",ans);
    return 0;
}
