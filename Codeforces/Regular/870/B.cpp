#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int g=0;
        for(int i=1;i<=n;i++){
            int d=a[i]-a[n+1-i]; d=max(d,-d);
            if(d==0) continue;
            g=__gcd(g,d);
        }
        printf("%d\n",g);
    }
    return 0;
}

