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
int t,a,b;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        a=max(a,-a); b=max(b,-b);
        if(a>b) swap(a,b);
        int ans=2*a; b-=a;
        if(b) ans+=2*b-1;
        printf("%d\n",ans);
    }
    return 0;
}

