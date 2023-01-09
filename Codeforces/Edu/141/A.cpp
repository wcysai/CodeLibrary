#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int s[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(a[1]==a[n]) puts("NO");
        else{
            puts("YES");
            printf("%d",a[n]);
            for(int i=1;i<n;i++) printf(" %d",a[i]);
            puts("");
        }
    }
    return 0;
}

