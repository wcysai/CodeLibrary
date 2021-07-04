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
priority_queue<int> pque;
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x); x-=i;
        pque.push(x);
        ans+=pque.top()-x;
        pque.pop();
        pque.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}