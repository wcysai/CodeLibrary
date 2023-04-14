#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],d[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
        if(n==2) {if(a[1]>a[2]) puts("NO"); else puts("YES");}
        else if(n&1) puts("YES");
        else{
            ll s=0; 
            for(int i=2;i<=n;i+=2) s+=d[i];
            if(s<0) puts("NO"); else puts("YES");
        }
    }
    return 0;
}

