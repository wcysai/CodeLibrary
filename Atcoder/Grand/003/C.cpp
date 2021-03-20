#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(b+1,b+n+1,a[i])-b;
        if((pos+i)&1) ans++;
    }
    assert(ans%2==0);
    printf("%d\n",ans/2);
    return 0;
}