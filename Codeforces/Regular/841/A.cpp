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
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        ll s=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            s*=a[i];
        }
        s+=n-1;
        printf("%lld\n",2022*s);
    }
    return 0;
}

