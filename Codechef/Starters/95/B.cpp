#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int maxi=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            for(int j=60;j>=0;j--){
                if(a[i]&(1LL<<j)) maxi=max(maxi,j);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(a[i]&(1LL<<maxi)) cnt++;
        printf("%d\n",(cnt+1)/2);
    }
    return 0;
}

