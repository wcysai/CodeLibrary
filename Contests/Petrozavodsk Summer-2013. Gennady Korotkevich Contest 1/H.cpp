#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int N,X;
int a[MAXN],b[MAXN];
bool check(int x)
{
    int res=a[1]+b[x];
    int now=1,i=N,cnt=0;
    for(int i=N;i>=2;i--)
    {
        while(now==x) now++;
        if(b[now]+a[i]>res) cnt++,now++;
    }
    return cnt<X;
}
int main()
{
    freopen("hop.in","r",stdin);i=1;i<=N;i++) scanf("%d",&b[i]);
    freopen("hop.out","w",stdout);
    scanf("%d%d",&N,&X);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int
    sort(a+2,a+N+1,greater<int>());
    int l=0,r=N+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    if(l==0) puts("-1"); else printf("%d\n",l);
}
