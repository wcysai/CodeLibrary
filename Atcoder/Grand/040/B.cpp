#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN];
P pre[MAXN],suf[MAXN];
P intersect(P x,P y)
{
    if(x.F>y.S||y.F>x.S) return P(1,0);
    return P(max(x.F,y.F),min(x.S,y.S));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    sort(a+1,a+n+1);
    pre[0]=suf[n+1]=P(1,INF);
    for(int i=1;i<=n;i++) pre[i]=intersect(pre[i-1],a[i]);
    for(int i=n;i>=1;i--) suf[i]=intersect(suf[i+1],a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        P p=intersect(pre[i-1],suf[i+1]);
        ans=max(ans,a[i].S-a[i].F+1+p.S-p.F+1);
    }
    for(int i=1;i<=n-1;i++) ans=max(ans,pre[i].S-pre[i].F+1+suf[i+1].S-suf[i+1].F+1);
    printf("%d\n",ans);
    return 0;
}
