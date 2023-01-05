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
        if(n==3) puts("NO");
        else{
            puts("YES");
            if(n%2==0)
            {
                for(int i=1;i<=n;i++) printf("%d ",i&1?1:-1);
                puts("");
            }
            else{
                int x=n/2-1,y=n/2;
                for(int i=1;i<=n;i++) printf("%d ",i&1?x:-y);
                puts("");
            }
        }
    }
    return 0;
}

