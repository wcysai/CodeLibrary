#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k;
int a[MAXN];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n==5){
            db res=(a[n-2]+a[n])/2.0-(a[1]+a[2])/2.0;
            res=max(res,(a[n-1]+a[n])/2.0-(a[1]+a[3])/2.0);
            printf("Case #%d: %.10f\n",t,res);
            continue;
        }
        printf("Case #%d: %.10f\n",t,(a[n-1]+a[n])/2.0-(a[1]+a[2])/2.0);
    }
    return 0;
}

