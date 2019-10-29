#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,ans;
void solve(int x)
{
    ans=min(ans,2*x+2*(n/x));
}
int main()
{
    scanf("%d",&n);
    ans=INF;
    for(int i=1;i*i<=n;i++) if(n%i==0) solve(i);
    printf("%d\n",ans);
    return 0;
}
