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
int t,n,m,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ll sa=0,sb=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sa+=a[i];
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            sb+=b[i];
        }
        if(sa>sb) puts("Tsondu"); else if(sa<sb) puts("Tenzing"); else puts("Draw");
    }
    return 0;
}

