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
int t,n,x,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        bool f=true;
        for(int i=1;i<=n;i++) if(a[i]+x>a[i+n]) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

