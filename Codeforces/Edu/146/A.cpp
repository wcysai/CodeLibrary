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
int t,a[MAXN];
ll k,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        if(n%2==0) puts("YES");
        else if(k%2==0) puts("NO");
        else if(n<k) puts("NO");
        else puts("YES");
    }
    return 0;
}

