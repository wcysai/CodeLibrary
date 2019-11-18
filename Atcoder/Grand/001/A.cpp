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
int main()
{
    int ans=0;
    scanf("%d",&n); n*=2;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=(n&1?2:1);i<=n;i+=2) ans+=a[i];
    printf("%d\n",ans);
    return 0;
}
