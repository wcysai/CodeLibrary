#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=1;
    for(int i=1;i<=n;i++) 
    {
        ans=1LL*ans*(a[i]+1-i)%MOD;
        if(ans==0) break;
    }
    printf("%d\n",ans);
    return 0;
}