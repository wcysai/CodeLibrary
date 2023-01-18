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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        if(a[1]!=0) ans++;
        for(int i=1;i<=n;i++){
            if(i-1<a[i]||((i!=n)&&a[i+1]<=i));
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

