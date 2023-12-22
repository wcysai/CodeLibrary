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
int t,n,k,s[MAXN],e[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&s[i],&e[i]);
        bool f=true;
        for(int i=2;i<=n;i++) if(s[i]>=s[1]&&e[i]>=e[1]) f=false;
        if(!f) puts("-1"); else printf("%d\n",s[1]);
    }
    return 0;
}

