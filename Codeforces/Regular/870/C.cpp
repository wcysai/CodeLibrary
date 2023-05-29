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
int t,n,m,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n==1) {puts("YES"); continue;} 
        bool f=false;
        for(int i=1;i*i<=n;i++){
            if(n%i) continue;
            if(i!=1&&i<=m) f=true;
            if(n/i<=m) f=true;
        }
        if(!f) puts("YES"); else puts("NO");
    }
    return 0;
}

